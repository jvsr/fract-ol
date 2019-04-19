# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 14:23:09 by jvisser        #+#    #+#                 #
#    Updated: 2019/04/12 17:57:09 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
HEADER = fractol.h
FLAGS = -Wall -Wextra -Werror
C_FILES = \
		main.c \
		julia.c \
		mandelbrot.c \
		burningship.c \
		print.c \
		key_press.c \
		utils.c \
		color.c \
		color_palettes.c
O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	@echo "\033[1;32m 🛠️  Building $@ from $< file \033[0m"
	@gcc $(FLAGS) -c -o $@ $<

$(NAME): $(O_FILES)
	@echo "\033[1;35m 🏁  Start building mlx library \033[0m"
	@make -C minilibx_macos > /dev/null
	@echo "\033[1;35m 🏁  Done building mlx library \033[0m"
	@echo "\033[1;35m 🏁  Start building ft library \033[0m"
	@make -C libft
	@echo "\033[1;35m 🏁  Done building ft library \033[0m"
	@echo "\033[1;32m 🛠️  Building Fractol from objects \033[0m"
	@gcc $(FLAGS) -o $(NAME) $(O_FILES) -L minilibx_macos/ -lmlx\
		-framework OpenGL -framework AppKit -L libft -lft
	@echo "\033[1;35m 🏁  Done building Fractol \033[0m"

clean:
	@echo "\033[1;35m 🏁  Start cleaning ft library \033[0m"
	@make -C libft clean
	@echo "\033[1;35m 🏁  Done cleaning ft library \033[0m"
ifeq (,$(wildcard $(O_FILES)))
	@echo "\033[1;31m 🗑️  No objects to clean \033[0m"
else
	@echo "\033[1;31m 🗑️  Cleaning library objects \033[0m"
	@/bin/rm -f $(O_FILES)
endif

fclean: clean
	@echo "\033[1;35m 🏁  Start fcleaning ft library \033[0m"
	@make -C libft fclean
	@echo "\033[1;35m 🏁  Done fcleaning ft library \033[0m"
ifeq (,$(wildcard $(NAME)))
	@echo "\033[1;31m 🗑️  No executable to clean \033[0m"
else
	@echo "\033[1;31m 🗑️  Cleaning fractol file \033[0m"
	@/bin/rm -f $(NAME)
endif

re: fclean
	@echo "\033[1;35m 🏁  Start rebuilding mlx library \033[0m"
	@make -C minilibx_macos re > /dev/null
	@echo "\033[1;35m 🏁  Done rebuilding mlx library \033[0m"
	@echo "\033[1;35m 🏁  Start rebuilding ft library \033[0m"
	@make -C libft re
	@echo "\033[1;35m 🏁  Done rebuilding ft library \033[0m"
	@echo "\033[1;35m 🏁  Start rebuilding Fractol \033[0m"
	@make all
	@echo "\033[1;35m 🏁  Done rebuilding Fractol \033[0m"
	
# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jvisser <jvisser@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/04 14:23:09 by jvisser        #+#    #+#                 #
#    Updated: 2019/04/10 17:49:42 by jvisser       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fractol
HEADER = fractol.h
FLAGS = -Wall -Wextra -Werror
C_FILES = \
		main.c \
		print.c \
		mandelbrot.c \
		burningship.c \
		key_press.c \
		color.c
O_FILES = $(C_FILES:.c=.o)

all: $(NAME)

%.o: %.c $(HEADER)
	gcc $(FLAGS) -c $<

$(NAME): $(O_FILES)
	make -C minilibx_macos
	make -C libft
	gcc $(FLAGS) -o $(NAME) $(O_FILES) -L minilibx_macos/ -lmlx\
		-framework OpenGL -framework AppKit -L libft -lft

clean:
	make -C libft clean
	rm -f $(O_FILES)

fclean: clean
	make -C libft fclean
	rm -f $(NAME)

re: fclean
	make -C minilibx_macos re
	make all
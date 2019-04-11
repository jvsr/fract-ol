/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 11:30:08 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/11 16:18:38 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	exit_failure_errno(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	exit_failure_message(char *message)
{
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

void	print_usage(void)
{
	ft_printf("Usage: ./fractol:\n	./fractol [mandelbrot, burningship]\n");
	exit(EXIT_FAILURE);
}

void	draw_menu(t_mlx_data *data)
{
	if (data->menu == false)
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 20, 0xFFFFFF, "Open Menu");
	else
	{
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 20, 0xFFFFFF, "Close Menu");
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 60, 0xFFFFFF, "Move:        Arrows");
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 80, 0xFFFFFF, "Zoom in:     + / Right mouse / Scroll down");
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 100, 0xFFFFFF, "Zoom out:    - / Left mouse  / Scroll up");
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 120, 0xFFFFFF, "Mandelbrot:  M");
		mlx_string_put(MLX_PTR, WIN_PTR, 20, 140, 0xFFFFFF, "Burningship: B");

		mlx_string_put(MLX_PTR, WIN_PTR, 20, 160, 0xFFFFFF, "Reset:       R");
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 14:23:48 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/12 17:48:57 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	init_data(t_mlx_data *data, char *fract_name)
{
	t_color	*palette;

	if (ft_strequ(fract_name, "mandelbrot"))
		data->type = 0;
	else if (ft_strequ(fract_name, "burningship"))
		data->type = 1;
	else if (ft_strequ(fract_name, "julia"))
		data->type = 2;
	else
		print_usage();
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(MLX_PTR, WIN_X, WIN_Y, "Fractol");
	data->img_ptr = mlx_new_image(MLX_PTR, WIN_X, WIN_Y);
	data->img_add = mlx_get_data_addr(IMG_PTR, &data->bpp,
									&data->sl, &data->endian);
	data->menu = false;
	data->pause = false;
	data->c = 0;
	palette = (t_color*)malloc(sizeof(t_color));
	if (!palette)
		exit_failure_errno();
	data->palette = palette;
	init_color(data->palette);
}

void	create_fract(t_mlx_data *data)
{
	if (data->type == 0)
		create_mandelbrot(data);
	else if (data->type == 1)
		create_burningship(data);
	else if (data->type == 2)
		create_julia(data);
}

void	init_fract(t_mlx_data *data)
{
	if (data->type == 0)
		mandelbrot_init(data);
	else if (data->type == 1)
		burningship_init(data);
	else if (data->type == 2)
		julia_init(data);
	create_fract(data);
}

int		main(int ac, char **av)
{
	t_mlx_data	*data;

	if (ac != 2)
		print_usage();
	data = (t_mlx_data*)malloc(sizeof(t_mlx_data));
	if (!data)
		exit_failure_errno();
	init_data(data, av[1]);
	init_fract(data);
	mlx_hook(WIN_PTR, 2, 2, key_press, data);
	mlx_hook(WIN_PTR, 6, 6, mouse_move, data);
	mlx_mouse_hook(WIN_PTR, mouse_press, data);
	mlx_loop(MLX_PTR);
	return (0);
}

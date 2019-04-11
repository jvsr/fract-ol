/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_press.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 15:26:52 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/10 18:25:10 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "fractol.h"

int key_press(int keycode, t_mlx_data *data)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	else if (keycode == 69) 					// - num
		data->iteration_max += 100;
	else if (keycode == 78)						// + num
		data->iteration_max -= 100;
	else if (keycode == 27) 					// - key
	{
		data->x_scale = (WIN_X / 2 / data->zoom + data->x_scale) - (WIN_X / 2 / (data->zoom / 1.3));
		data->y_scale = (WIN_Y / 2 / data->zoom + data->y_scale) - (WIN_Y / 2 / (data->zoom / 1.3));
		data->zoom /= 1.3;
	}
	else if (keycode == 24)						// + key
	{
		data->x_scale = (WIN_X / 2 / data->zoom + data->x_scale) - (WIN_X / 2 / (data->zoom * 1.3));
		data->y_scale = (WIN_Y / 2 / data->zoom + data->y_scale) - (WIN_Y / 2 / (data->zoom * 1.3));
		data->zoom *= 1.3;
	}
	else if (keycode == 123)					// <-
		data->x_scale -= 30 / data->zoom;
	else if (keycode == 124)					// ->
		data->x_scale += 30 / data->zoom;
	else if (keycode == 125)					// v
		data->y_scale += 30 / data->zoom;
	else if (keycode == 126)					// ^
		data->y_scale -= 30 / data->zoom;
	else if (keycode == 15)						// R
		init_fract(data);
	else if (keycode == 18)						// 1
		init_color(data->palette);
	else if (keycode == 19)						// 2
		init_color1(data->palette);
	else if (keycode == 20)						// 3
		init_color2(data->palette);
	else if (keycode == 46)
	{
		data->type = 0;
		mandelbrot_init(data);
	}
	else if (keycode == 11)
	{
		data->type = 1;
		burningship_init(data);
	}
	create_fract(data);
	return (1);
}

int		mouse_press(int mousecode, int x, int y, t_mlx_data *data)
{
	if (mousecode == 1 && x < 120 && y < 50)
	{
		if (data->menu == false)
			data->menu = true;
		else
			data->menu = false;
	}
	else if (mousecode == 4 || mousecode == 1)
	{
		data->x_scale = (x / data->zoom + data->x_scale) - (WIN_X / 2 / (data->zoom * 1.3));
		data->y_scale = (y / data->zoom + data->y_scale) - (WIN_Y / 2 / (data->zoom * 1.3));
		data->zoom *= 1.3;
	}
	else if (mousecode == 5 || mousecode == 2)
	{
		data->x_scale = (x / data->zoom + data->x_scale) - (WIN_X / 2 / (data->zoom / 1.3));
		data->y_scale = (y / data->zoom + data->y_scale) - (WIN_Y / 2 / (data->zoom / 1.3));
		data->zoom /= 1.3;
	}
	create_fract(data);
	return (0);
}

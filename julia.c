/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 11:43:36 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/15 13:33:00 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <pthread.h>

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	julia_init(t_mlx_data *data)
{
	data->zoom = WIN_Y / 2;
	data->color = 300;
	data->x_scale = -1.7;
	data->y_scale = -0.9;
	data->iteration_max = 30;
}

void	julia_calc_pixel(t_mlx_data *data)
{
	double	x;
	double	y;
	double	x_save;

	x = data->px / data->zoom + data->x_scale;
	y = data->py / data->zoom + data->y_scale;
	data->iteration = 0;
	while (x * x + y * y <= (1 << 8) && data->iteration < data->iteration_max)
	{
		x_save = x;
		x = x * x - y * y - 1.7 + (data->mouse_x / WIN_X);
		y = 2 * x_save * y - 0.9 + data->mouse_y / WIN_Y;
		data->iteration++;
	}
	if (data->iteration == data->iteration_max)
		pixel_to_img(data, data->px, data->py, 0);
	else
		pixel_to_img(data, data->px, data->py, set_color(x, y, data));
}

void	*julia(void *tab)
{
	int			save;
	t_mlx_data	*data;

	data = (t_mlx_data*)tab;
	data->px = 0;
	save = data->py;
	while (data->px < WIN_X)
	{
		data->py = save;
		while (data->py < data->py_max)
		{
			julia_calc_pixel(data);
			data->py++;
		}
		data->px++;
	}
	return (tab);
}

void	create_julia(t_mlx_data *data)
{
	int			i;
	t_mlx_data	tab[THREAD_AMOUNT];
	pthread_t	thread[THREAD_AMOUNT];

	i = 0;
	while (i < THREAD_AMOUNT)
	{
		ft_memcpy((void*)&tab[i], (void*)data, sizeof(t_mlx_data));
		tab[i].py = THREAD_LINES * i;
		tab[i].py_max = THREAD_LINES * (i + 1);
		pthread_create(&thread[i], NULL, julia, &tab[i]);
		i++;
	}
	while (i)
	{
		pthread_join(thread[i - 1], NULL);
		i--;
	}
	mlx_put_image_to_window(MLX_PTR, WIN_PTR, IMG_PTR, 0, 0);
	draw_menu(data);
}

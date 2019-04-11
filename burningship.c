/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   burningship.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 17:45:10 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/10 17:55:15 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <pthread.h>
#include <stdlib.h>

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	burningship_init(t_mlx_data *data)
{
	data->zoom = WIN_Y * 3.4 ;
	data->color = 300;
	data->x_scale = -2;
	data->y_scale = -0.20;
	data->iteration_max = 30;
}

void	burningship_calc_pixel(t_mlx_data *data)
{
	double	x = 0.0;
	double	y = 0.0;
	double	x0 = data->px / data->zoom + data->x_scale;
	double	y0 = data->py / data->zoom + data->y_scale;
	double	x_save;

	data->iteration = 0;
	while (x * x + y * y <= (1 << 8)  &&  data->iteration < data->iteration_max)
	{
		x_save = x * x - y * y + x0;
		y = fabs(2 * x * y) + y0;
		x = x_save;
		data->iteration++;
	}
	int color = set_color(x, y, data);
	if (data->iteration == data->iteration_max)
		pixel_to_img(data, data->px, data->py, 0);
	else
		pixel_to_img(data, data->px, data->py, color);
}

void	*burningship(void* tab)
{
	int			save;
	t_mlx_data	*data;

	data = (t_mlx_data*)tab;
	data->px = 0;
	save = data->py;
	while(data->px < WIN_X)
	{
		data->py = save;
		while (data->py < data->py_max)
		{
			burningship_calc_pixel(data);
			data->py++;
		}
		data->px++;
	}
	return(tab);
}

void	create_burningship(t_mlx_data *data)
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
		pthread_create(&thread[i], NULL, burningship, &tab[i]);
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

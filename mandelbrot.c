/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 11:49:48 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/10 17:44:37 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <pthread.h>
#include <stdlib.h>

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	mandelbrot_init(t_mlx_data *data)
{
	data->zoom = WIN_Y / 2;
	data->color = 300;
	data->x_scale = -2.5;
	data->y_scale = -1;
	data->iteration_max = 30;
}

void	pixel_to_img(t_mlx_data *data, int px, int py, int color)
{
	if (data->px < WIN_X && data->py < WIN_Y)
	{
		color = mlx_get_color_value(MLX_PTR, color);
		ft_memcpy(IMG_ADD + data->sl * py + px * data->bpp / 8, &color, sizeof(int));
	}
}

int		set_color(int x, int y, t_mlx_data *data)
{
	int	color;
	double size = sqrt(x * x + y * y);
	double smoothed = log(log(size) * (1 / log(2))) * (1 / log(2));
	double colorI = (double)((int)(sqrt(data->iteration + 1 - smoothed) * data->color) % data->palette->length);

	if (colorI < (data->palette->length * data->palette->pos2))
	{
		color = ((65536 * ((int)((data->palette->r2 - data->palette->r1) * (colorI / (data->palette->length * data->palette->pos2))) + data->palette->r1))\
				+ (256 * ((int)((data->palette->g2 - data->palette->g1) * (colorI / (data->palette->length * data->palette->pos2))) + data->palette->g1))\
				+ (1 * ((int)((data->palette->b2 - data->palette->b1) * (colorI / (data->palette->length * data->palette->pos2))) + data->palette->b1)));
	}
	else if (colorI < (data->palette->length * data->palette->pos3))
	{
		color = ((65536 * ((int)((data->palette->r3 - data->palette->r2) * ((colorI - data->palette->length * data->palette->pos2) / (data->palette->length * data->palette->pos3 - data->palette->length * data->palette->pos2))) + data->palette->r2))\
				+ (256 * ((int)((data->palette->g3 - data->palette->g2) * ((colorI - data->palette->length * data->palette->pos2) / (data->palette->length * data->palette->pos3 - data->palette->length * data->palette->pos2))) + data->palette->g2))\
				+ (1 * ((int)((data->palette->b3 - data->palette->b2) * ((colorI - data->palette->length * data->palette->pos2) / (data->palette->length * data->palette->pos3 - data->palette->length * data->palette->pos2))) + data->palette->b2)));
	}
	else if (colorI < (data->palette->length * data->palette->pos4))
	{
		color = ((65536 * ((int)((data->palette->r4 - data->palette->r3) * ((colorI - data->palette->length * data->palette->pos3) / (data->palette->length * data->palette->pos4 - data->palette->length * data->palette->pos3))) + data->palette->r3))\
				+ (256 * ((int)((data->palette->g4 - data->palette->g3) * ((colorI - data->palette->length * data->palette->pos3) / (data->palette->length * data->palette->pos4 - data->palette->length * data->palette->pos3))) + data->palette->g3))\
				+ (1 * ((int)((data->palette->b4 - data->palette->b3) * ((colorI - data->palette->length * data->palette->pos3) / (data->palette->length * data->palette->pos4 - data->palette->length * data->palette->pos3))) + data->palette->b3)));
	}
	else if (colorI < (data->palette->length * data->palette->pos5))
	{
		color = ((65536 * ((int)((data->palette->r5 - data->palette->r4) * ((colorI - data->palette->length * data->palette->pos4) / (data->palette->length * data->palette->pos5 - data->palette->length * data->palette->pos4))) + data->palette->r4))\
				+ (256 * ((int)((data->palette->g5 - data->palette->g4) * ((colorI - data->palette->length * data->palette->pos4) / (data->palette->length * data->palette->pos5 - data->palette->length * data->palette->pos4))) + data->palette->g4))\
				+ (1 * ((int)((data->palette->b5 - data->palette->b4) * ((colorI - data->palette->length * data->palette->pos4) / (data->palette->length * data->palette->pos5 - data->palette->length * data->palette->pos4))) + data->palette->b4)));
	}
	else
	{
		color = ((65536 * ((int)((data->palette->r1 - data->palette->r5) * ((colorI - data->palette->length * data->palette->pos5) / (data->palette->length * 1 - data->palette->length * data->palette->pos5))) + data->palette->r5))\
				+ (256 * ((int)((data->palette->g1 - data->palette->g5) * ((colorI - data->palette->length * data->palette->pos5) / (data->palette->length * 1 - data->palette->length * data->palette->pos5))) + data->palette->g5))\
				+ (1 * ((int)((data->palette->b1 - data->palette->b5) * ((colorI - data->palette->length * data->palette->pos5) / (data->palette->length * 1 - data->palette->length * data->palette->pos5))) + data->palette->b5)));
	}
	return (color);
}

/*
**	colorI = 1;
**	while (colorI < 2048)
**	{
**
**		for(int y = 0; y < 50; y++)
**			mlx_pixel_put(MLX_PTR, WIN_PTR, colorI, y, color);
**		colorI++;
**	}
**
**
*/

void	mandelbrot_calc_pixel(t_mlx_data *data)
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
		y = 2 * x * y + y0;
		x = x_save;
		data->iteration++;
	}
	int color = set_color(x, y, data);
	if (data->iteration == data->iteration_max)
		pixel_to_img(data, data->px, data->py, 0);
	else
		pixel_to_img(data, data->px, data->py, color);
}

void	*mandelbrot(void* tab)
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
			mandelbrot_calc_pixel(data);
			data->py++;
		}
		data->px++;
	}
	return(tab);
}

void	create_mandelbrot(t_mlx_data *data)
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
		pthread_create(&thread[i], NULL, mandelbrot, &tab[i]);
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

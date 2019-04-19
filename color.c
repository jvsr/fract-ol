/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 15:40:40 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/12 17:48:36 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>

#include "fractol.h"

static int	more_set_color2(double colori, t_mlx_data *data)
{
	int	color;

	if (colori < (LENGTH * POS5))
	{
		color = ((65536 * ((int)((R5 - R4) * ((colori - LENGTH * POS4)
				/ (LENGTH * POS5 - LENGTH * POS4))) + R4))\
				+ (256 * ((int)((G5 - G4) * ((colori - LENGTH * POS4)
				/ (LENGTH * POS5 - LENGTH * POS4))) + G4))\
				+ (1 * ((int)((B5 - B4) * ((colori - LENGTH * POS4)
				/ (LENGTH * POS5 - LENGTH * POS4))) + B4)));
	}
	else
	{
		color = ((65536 * ((int)((R1 - R5) * ((colori - LENGTH * POS5)
				/ (LENGTH * 1 - LENGTH * POS5))) + R5))\
				+ (256 * ((int)((G1 - G5) * ((colori - LENGTH * POS5)
				/ (LENGTH * 1 - LENGTH * POS5))) + G5))\
				+ (1 * ((int)((B1 - B5) * ((colori - LENGTH * POS5)
				/ (LENGTH * 1 - LENGTH * POS5))) + B5)));
	}
	return (color);
}

static int	more_set_color(double colori, t_mlx_data *data)
{
	int	color;

	if (colori < (LENGTH * POS3))
	{
		color = ((65536 * ((int)((R3 - R2) * ((colori - LENGTH * POS2)
						/ (LENGTH * POS3 - LENGTH * POS2))) + R2))
						+ (256 * ((int)((G3 - G2) * ((colori - LENGTH * POS2)
						/ (LENGTH * POS3 - LENGTH * POS2))) + G2))
						+ (1 * ((int)((B3 - B2) * ((colori - LENGTH * POS2)
						/ (LENGTH * POS3 - LENGTH * POS2))) + B2)));
	}
	else if (colori < (LENGTH * POS4))
	{
		color = ((65536 * ((int)((R4 - R3) * ((colori - LENGTH * POS3)
				/ (LENGTH * POS4 - LENGTH * POS3))) + R3))\
				+ (256 * ((int)((G4 - G3) * ((colori - LENGTH * POS3)
				/ (LENGTH * POS4 - LENGTH * POS3))) + G3))\
				+ (1 * ((int)((B4 - B3) * ((colori - LENGTH * POS3)
				/ (LENGTH * POS4 - LENGTH * POS3))) + B3)));
	}
	else
		color = more_set_color2(colori, data);
	return (color);
}

int			set_color(int x, int y, t_mlx_data *data)
{
	int		color;
	double	size;
	double	smoothed;
	double	colori;

	size = sqrt(x * x + y * y);
	smoothed = log(log(size) * (1 / log(2))) * (1 / log(2));
	colori = (double)((int)(sqrt(data->iteration + (1 - smoothed))
							* data->color + data->c) % LENGTH);
	if (colori < (LENGTH * POS2))
	{
		color = ((65536 * ((int)((R2 - R1) * (colori / (LENGTH * POS2))) + R1))
		+ (256 * ((int)((G2 - G1) * (colori / (LENGTH * POS2))) + G1))
		+ (1 * ((int)((B2 - B1) * (colori / (LENGTH * POS2))) + B1)));
	}
	else
		color = more_set_color(colori, data);
	return (color);
}

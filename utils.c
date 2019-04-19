/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/12 13:34:48 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/12 14:34:46 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "libft/libft.h"
#include "minilibx_macos/mlx.h"

void	pixel_to_img(t_mlx_data *data, int px, int py, int color)
{
	if (data->px < WIN_X && data->py < WIN_Y)
	{
		color = mlx_get_color_value(MLX_PTR, color);
		ft_memcpy(IMG_ADD + data->sl * py + px * data->bpp / 8,
					&color, sizeof(int));
	}
}

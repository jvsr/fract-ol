/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   color.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 15:40:40 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/10 17:21:32 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_color1(t_color *palette)
{
	palette->pos1 = 0;
	palette->r1 = 0;
	palette->g1 = 7;
	palette->b1 = 20;
	palette->pos2 = 0.16;
	palette->r2 = 32;
	palette->g2 = 107;
	palette->b2 = 203;
	palette->pos3 = 0.42;
	palette->r3 = 237;
	palette->g3 = 255;
	palette->b3 = 255;
	palette->pos4 = 0.6425;
	palette->r4 = 255;
	palette->g4 = 170;
	palette->b4 = 0;
	palette->pos5 = 0.8575;
	palette->r5 = 0;
	palette->g5 = 2;
	palette->b5 = 0;
	palette->length = 2048;
}

void	init_color2(t_color *palette)
{
	palette->pos1 = 0;
	palette->r1 = 80;
	palette->g1 = 81;
	palette->b1 = 79;
	palette->pos2 = 0.16;
	palette->r2 = 242;
	palette->g2 = 95;
	palette->b2 = 92;
	palette->pos3 = 0.42;
	palette->r3 = 255;
	palette->g3 = 224;
	palette->b3 = 102;
	palette->pos4 = 0.65;
	palette->r4 = 36;
	palette->g4 = 123;
	palette->b4 = 160;
	palette->pos5 = 0.83;
	palette->r5 = 112;
	palette->g5 = 193;
	palette->b5 = 179;
	palette->length = 2048;
}

void	init_color(t_color *palette)
{
	palette->pos1 = 0;
	palette->r1 = 1;
	palette->g1 = 22;
	palette->b1 = 39;
	palette->pos2 = 0.16;
	palette->r2 = 253;
	palette->g2 = 255;
	palette->b2 = 252;
	palette->pos3 = 0.42;
	palette->r3 = 46;
	palette->g3 = 196;
	palette->b3 = 182;
	palette->pos4 = 0.65;
	palette->r4 = 231;
	palette->g4 = 29;
	palette->b4 = 54;
	palette->pos5 = 0.83;
	palette->r5 = 255;
	palette->g5 = 159;
	palette->b5 = 28;
	palette->length = 2048;
}

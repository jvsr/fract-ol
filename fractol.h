/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 14:23:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/10 17:50:43 by jvisser       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>

typedef struct	s_color
{
	double		pos1;
	double		r1;
	double		g1;
	double		b1;
	double		pos2;
	double		r2;
	double		g2;
	double		b2;
	double		pos3;
	double		r3;
	double		g3;
	double		b3;
	double		pos4;
	double		r4;
	double		g4;
	double		b4;
	double		pos5;
	double		r5;
	double		g5;
	double		b5;
	int			length;
}				t_color;

typedef struct	s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*img_add;
	int			type;
	int			bpp;
	int			sl;
	int			endian;
	double			iteration;
	double			iteration_max;
	int			color;
	int			px;
	int			py;
	int			py_max;
	double		x0;
	double		y0;
	double		x_scale;
	double		y_scale;
	double		zoom;
	t_color		*palette;
	bool		menu;
}				t_mlx_data;

# define WIN_X 2800
# define WIN_Y 1500
# define THREAD_LINES 125
# define THREAD_AMOUNT 12
# define MLX_PTR data->mlx_ptr
# define WIN_PTR data->win_ptr
# define IMG_PTR data->img_ptr
# define IMG_ADD data->img_add

void	print_usage(void);
void	exit_failure_errno(void);
void	draw_menu(t_mlx_data *data);
void	exit_failure_message(char *message);

void	init_fract(t_mlx_data *data);
void	create_fract(t_mlx_data *data);

void	mandelbrot_init(t_mlx_data *data);
void	burningship_init(t_mlx_data *data);

int		key_press(int keycode, t_mlx_data *data);
int		mouse_julia(int x, int y, t_mlx_data *data);
int		mouse_press(int mousecode, int x, int y, t_mlx_data *data);

void	init_color(t_color *palette);
void	init_color1(t_color *palette);
void	init_color2(t_color *palette);
int		set_color(int x, int y, t_mlx_data *data);

void	pixel_to_img(t_mlx_data *data, int px, int py, int color);

void	create_mandelbrot(t_mlx_data *data);
void	create_burningship(t_mlx_data *data);

# endif
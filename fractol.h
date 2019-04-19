/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jvisser <jvisser@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 14:23:51 by jvisser        #+#    #+#                */
/*   Updated: 2019/04/12 17:48:46 by jvisser       ########   odam.nl         */
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
	int			offset_x;
	int			offset_y;
	double		iteration;
	double		iteration_max;
	int			color;
	int			px;
	int			py;
	int			py_max;
	int			c;
	double		mouse_x;
	double		mouse_y;
	double		x0;
	double		y0;
	double		x_scale;
	double		y_scale;
	double		zoom;
	t_color		*palette;
	bool		menu;
	bool		pause;
}				t_mlx_data;

# define WIN_X 800
# define WIN_Y 500
# define THREAD_LINES 50
# define THREAD_AMOUNT 10

# define POS1 data->palette->pos1
# define R1 data->palette->r1
# define G1 data->palette->g1
# define B1 data->palette->b1
# define POS2 data->palette->pos2
# define R2 data->palette->r2
# define G2 data->palette->g2
# define B2 data->palette->b2
# define POS3 data->palette->pos3
# define R3 data->palette->r3
# define G3 data->palette->g3
# define B3 data->palette->b3
# define POS4 data->palette->pos4
# define R4 data->palette->r4
# define G4 data->palette->g4
# define B4 data->palette->b4
# define POS5 data->palette->pos5
# define R5 data->palette->r5
# define G5 data->palette->g5
# define B5 data->palette->b5
# define LENGTH data->palette->length

# define MLX_PTR data->mlx_ptr
# define WIN_PTR data->win_ptr
# define IMG_PTR data->img_ptr
# define IMG_ADD data->img_add

/*
**				>>>> PRINT FUNCTIONS
*/
void			print_usage(void);
void			exit_failure_errno(void);
void			draw_menu(t_mlx_data *data);
void			exit_failure_message(char *message);
/*
**				>>>> FRACTOL CREATION FUNCTIONS
*/
void			init_fract(t_mlx_data *data);
void			create_fract(t_mlx_data *data);
/*
**				>>>> FRACTOL SPECIFIC FUNCTIONS
*/
void			create_julia(t_mlx_data *data);
void			create_mandelbrot(t_mlx_data *data);
void			create_burningship(t_mlx_data *data);
void			julia_init(t_mlx_data *data);
void			mandelbrot_init(t_mlx_data *data);
void			burningship_init(t_mlx_data *data);
/*
**				>>>> CONTROL FUNCTIONS
*/
int				key_press(int keycode, t_mlx_data *data);
int				mouse_move(int x, int y, t_mlx_data *data);
int				mouse_press(int mousecode, int x, int y, t_mlx_data *data);
/*
**				>>>> COLOR FUNCTIONS
*/
void			init_color(t_color *palette);
void			init_color1(t_color *palette);
void			init_color2(t_color *palette);
void			init_color3(t_color *palette);
int				set_color(int x, int y, t_mlx_data *data);
/*
**				>>>> IMAGE FUNCTIONS
*/
void			pixel_to_img(t_mlx_data *data, int px, int py, int color);

#endif

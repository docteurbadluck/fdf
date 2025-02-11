/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 11:10:07 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define M_PI 3.14159265358979323846
# define HEIGHT 1000
# define PADDING 100
# define WIDTH 1200
# define STR 0
# define INT 1
# define POINT3D 2
# define POINT2D 3
# define WHITE       0xFFFFFF

typedef struct s_point_3d
{
	int	x;
	int	y;
	int	z;
	int	last;
}	t_point_3d;

typedef struct s_point_2d
{
	double	x;
	double	y;
	int		z;
	int		screen_x;
	int		screen_y;
	int		last;
}	t_point_2d;

typedef struct s_line
{
	t_point_2d	first;	
	t_point_2d	second;
	int			dx;
	int			dy;
	int			step;
	float		x_increment;
	float		y_increment;
	int			color_start;
	int			color_end;
	int			blue;
	int			green;
	int			color;
}	t_line;

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}		t_img;

typedef struct s_field
{
	char		*name;
	void		*mlx_ptr;
	void		*win_ptr;
	char		***array_str;
	int			***array_int;
	double		range_y;
	double		range_x;
	double		scale;
	int			screen_x;
	int			screen_y;
	int			i;
	int			j;
	int			min_z;
	int			max_z;
	t_point_3d	*point3d;
	t_point_2d	*point2d;	
	t_img		img;
}		t_field;

		//***init.c***
void	init_field( t_field *field, char **argv);
int		close_clean(t_field *field);

		//***array_of_str_to_int.c***
int		***array_of_str_to_int(char ***array);
		//***free_any_array.c***
void	free_any_array(void *array, int type);
		//***print_any_array.c***
void	print_any_array(void *array, int type);
		//***any_test_on_str_array.c***
int		test_on_array_of_array_of_str(char ***array_array_str,
			int (*f)(char *str));

		//***valid_input.c***
int		valid_input(char *str);

		//***from_file_to_array.c***
char	***from_file_to_array(char *file);
void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);

		//***same_number_of_colone_in_str_array.c***
int		same_number_of_column_in_str_array(char ***array_str);

		//***point.c***
void	init_3d_point(t_field *field);
void	init_2d_point(t_field *field);
void	correct_point_2d(t_field *field);

		//***print.c***
void	render_fdf(t_field *field);
void	my_pixel_put(int x, int y, t_img *img, int color);
void	render_line(t_field *field);

void	init_size(t_field *field);

		//***draw_line.c***
void	draw_line(t_point_2d *first, t_point_2d *second, t_field *field);

double	map(double unscaled_num, double new_max,
			double old_min, double old_max);

#endif
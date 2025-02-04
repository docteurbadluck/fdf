/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:16 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/03 17:52:27 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/Xlib.h>
# include <stdio.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define HEIGHT 800
# define WIDTH 800
# define STR 0
# define INT 1

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
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	char	***array_str;
	int		*** array_int;
	t_img	img;
}		t_field;

		//***init.c***
void	init_field( t_field *field, char **argv);
int		close_clean(t_field *field);
//static int	keyhandler(int keycode, t_field *field)
		//***array_of_str_to_int.c***
int 	***array_of_str_to_int(char ***array);
		//***free_any_array.c***
void	free_any_array(void *array, int type);
		//***print_any_array.c***
void	print_any_array(void *array, int type);
		//***any_test_on_str_array.c***
int		test_on_array_of_array_of_str(char ***array_array_str, int (*f)(char *str));

		//***valid_input.c***
int		valid_input(char *str);

		//***from_file_to_array.c***
char	***from_file_to_array(char *file);
void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);










#endif
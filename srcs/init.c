/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 11:19:17 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		init_field_part1(t_field *field, char **argv);
void		init_field_part2(t_field *field, char **argv);
static int	keyhandler(int keycode, t_field *field);

// Initializes the field by calling two parts: one for setting up the
// window, image, and mlx hooks, and another for loading data from the
// file, converting it to integers, and setting up 3D and 2D points.
void	init_field(t_field *field, char **argv)
{
	init_field_part1(field, argv);
	init_field_part2(field, argv);
}

void	init_field_part1(t_field *field, char **argv)
{
	field->array_str = NULL;
	field->array_int = NULL;
	field->point3d = NULL;
	field->point2d = NULL;
	field->mlx_ptr = mlx_init();
	if (!field->mlx_ptr)
		exit(1);
	field->win_ptr = mlx_new_window(field->mlx_ptr, WIDTH, HEIGHT, "fdf");
	if (!field->win_ptr)
		exit(1);
	field->img.img_ptr = mlx_new_image(field->mlx_ptr, WIDTH, HEIGHT);
	if (!field->img.img_ptr)
		exit(1);
	field->img.img_pixels_ptr = mlx_get_data_addr(field->img.img_ptr,
			&field->img.bits_per_pixel, &field->img.line_len,
			&field->img.endian);
	if (!field->img.img_pixels_ptr)
		exit(1);
	mlx_hook(field->win_ptr, KeyPress, KeyPressMask, keyhandler, field);
	mlx_hook(field->win_ptr, 17, NoEventMask, close_clean, field);
}

void	init_field_part2(t_field *field, char **argv)
{
	field->array_str = from_file_to_array(argv[1]);
	if (test_on_array_of_array_of_str(field->array_str, valid_input))
	{
		perror("problem map\n");
		close_clean(field);
	}
	if (same_number_of_column_in_str_array(field->array_str))
		close_clean(field);
	field->array_int = array_of_str_to_int(field->array_str);
	init_3d_point(field);
	init_2d_point(field);
	init_size(field);
}

int	close_clean(t_field *field)
{
	mlx_destroy_image(field->mlx_ptr, field->img.img_ptr);
	mlx_destroy_window(field->mlx_ptr, field->win_ptr);
	mlx_destroy_display(field->mlx_ptr);
	free(field->mlx_ptr);
	if (field->array_str)
		free_any_array(field->array_str, STR);
	if (field->array_int)
		free_any_array(field->array_int, INT);
	if (field->point3d)
		free(field->point3d);
	if (field->point2d)
		free(field->point2d);
	exit(EXIT_SUCCESS);
	return (0);
}

static int	keyhandler(int keycode, t_field *field)
{
	if (keycode == XK_Escape)
		close_clean(field);
	return (0);
}

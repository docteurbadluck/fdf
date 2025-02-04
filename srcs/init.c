/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/03 17:53:59 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		keyhandler(int keycode, t_field *field)
{
	if (keycode == XK_Escape)
		close_clean(field);
	return 0;
}

void	init_field( t_field *field, char **argv)
{

	field->mlx_ptr = mlx_init();
	field->win_ptr = mlx_new_window(field->mlx_ptr, WIDTH, HEIGHT, "fdf");
	field->img.img_ptr = mlx_new_image(field->mlx_ptr, WIDTH, HEIGHT);
	field->img.img_pixels_ptr = mlx_get_data_addr(&field->img.img_ptr,
			&field->img.bits_per_pixel, 
				&field->img.line_len, &field->img.endian);
	mlx_hook(field->win_ptr, KeyPress, KeyPressMask, keyhandler, field);
	mlx_hook(field->win_ptr, 17, NoEventMask, close_clean, field);
}

int	close_clean(t_field *field)
{
	mlx_destroy_image(field->mlx_ptr, field->img.img_ptr);
	mlx_destroy_window(field->mlx_ptr, field->win_ptr);
	mlx_destroy_display(field->mlx_ptr);
	free(field->mlx_ptr);
	free_any_array(field->array_str, STR);
	free_any_array(field->array_int, INT);
	exit(EXIT_SUCCESS);
	return (0);
}


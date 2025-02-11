/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:53:39 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 11:15:24 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bits_per_pixel / 8));
	*(unsigned int *)(img ->img_pixels_ptr + offset) = color;
}

void	map_to_screen(double x, double y, t_field *field)
{
	field->screen_x = (int)(x * field->scale + PADDING);
	field->screen_y = (int)(y * field->scale + PADDING);
}

void	init_size(t_field *field)
{
	int	i;

	field->scale = 1000;
	i = 0;
	while (field->point2d[i].last == 0)
	{
		map_to_screen(field->point2d[i].x, field->point2d[i].y, field);
		if ((field->screen_x < 0 || field->screen_x >= WIDTH - PADDING)
			|| (field->screen_y < 0 || field->screen_y >= HEIGHT - PADDING))
		{
			field->scale -= 0.1;
			i = 0;
		}
		i++;
	}
	i = 0;
	while (field->point2d[i].last == 0)
	{
		map_to_screen(field->point2d[i].x, field->point2d[i].y, field);
		field->point2d[i].screen_x = field->screen_x;
		field->point2d[i].screen_y = field->screen_y;
		i++;
	}
}

double	map(double unscaled_num,
	double new_max, double old_min, double old_max)
{
	double	mapped_value;

	if (old_max == old_min)
		return (0);
	mapped_value = ((new_max - 0) * (unscaled_num - old_min))
		/ (old_max - old_min) + 0;
	if (mapped_value < 0)
		mapped_value = 0;
	if (mapped_value > 255)
		mapped_value = 255;
	return (mapped_value);
}

// Renders the lines between the 2D points of the field.
// Iterates through the points in the 2D grid and draws lines connecting
// adjacent points both horizontally and vertically. After drawing the lines,
// the image is displayed in the window.
void	render_line(t_field *field)
{
	int	a;
	int	i;

	i = 1;
	a = 0;
	while (a < (field->i - 1) * field->j)
	{
		draw_line(&field->point2d[a], &field->point2d[a + field->j], field);
		a++;
	}
	a = 0;
	while (i < field->j)
	{
		while (a < ((field->j) * field ->i))
		{
			draw_line(&field->point2d[a], &field->point2d[a + 1], field);
			a += field->j;
		}
		a = i;
		i++;
	}
	mlx_put_image_to_window(field->mlx_ptr, field->win_ptr,
		field->img.img_ptr, 0, 0);
}

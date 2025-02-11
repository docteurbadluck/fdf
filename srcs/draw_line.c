/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 17:07:13 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 11:02:47 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_line(t_line *line, t_point_2d *first,
	t_point_2d *second, t_field *field)
{
	line->first = *first;
	line->second = *second;
	line->dx = second->screen_x - first->screen_x;
	line->dy = second->screen_y - first->screen_y;
	line->color_start = (int)map(first->z, 255, field->min_z, field->max_z);
	line->color_end = (int)map(second->z, 255, field->min_z, field->max_z);
	if (abs(line->dx) >= abs(line->dy))
		line->step = abs(line->dx);
	else 
		line->step = abs(line->dy);
	if (line->step == 0)
		line->step = 1;
	line->x_increment = (float) line->dx / line->step;
	line->y_increment = (float) line->dy / line->step;
}

void	draw_line(t_point_2d *first, t_point_2d *second, t_field *field)
{
	t_line	line;
	int		i;
	float	x;
	float	y;

	i = 0;
	init_line(&line, first, second, field);
	x = line.first.screen_x;
	y = line.first.screen_y;
	while (i <= line.step)
	{
		line.color = (int)(((float)(line.step - i) / line.step)
				* line.color_start + ((float)i / line.step) * line.color_end);
		line.green = 0;
		line.blue = 255 - line.color;
		line.color = (line.color << 16) | (line.green << 8) | line.blue;
		my_pixel_put(round(x), round(y), &field->img, line.color);
		x += line.x_increment;
		y += line.y_increment;
		i++;
	}
}

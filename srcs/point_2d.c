/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 10:56:15 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 10:57:52 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	allocate_point2d(t_field *field)
{
	int	i;
	int	j;

	i = 0;
	while (field->array_int[i])
	{
		j = 0;
		while (field->array_int[i][j])
		{
			j++;
		}
		i++;
	}
	field->point2d = malloc ((i * j + 1) * sizeof (t_point_2d));
	field->i = i--;
	field->j = j--;
}

void	init_2d_point(t_field *field)
{
	int		i;
	float	angle;

	angle = 120 * (M_PI / 180);
	allocate_point2d(field);
	i = 0;
	while (field->point3d[i].last == 0)
	{
		field->point2d[i].x = field->point3d[i].x * cos(angle)
			+ field->point3d[i].y * cos(angle - 2 * (M_PI / 3)) + 
			field->point3d[i].z * cos(angle + 2 * (M_PI / 3) * 1.2);
		field->point2d[i].y = field->point3d[i].x * sin(angle) 
			+ field->point3d[i].y * sin(angle - 2 * (M_PI / 3)) + 
			field->point3d[i].z * sin(angle + 2 * (M_PI / 3) * 1.2);
		field->point2d[i].last = 0;
		field->point2d[i].z = field->point3d[i].z;
		i++;
	}
	field->point2d[i].last = 1;
	correct_point_2d(field);
}

void	correct_point_2d(t_field *field)
{
	double	min_x;
	double	min_y;
	int		i;

	min_x = field->point2d[0].x;
	min_y = field->point2d[0].y;
	i = 0;
	while (field->point2d[i].last == 0)
	{
		field->point2d[i].screen_x = 0;
		field->point2d[i].screen_y = 0;
		if (field->point2d[i].x < min_x)
			min_x = field->point2d[i].x;
		if (field->point2d[i].y < min_y)
			min_y = field->point2d[i].y;
		i++;
	}
	i = 0;
	while (field->point2d[i].last == 0)
	{
		field->point2d[i].x -= min_x;
		field->point2d[i].y -= min_y;
		i++;
	}
}

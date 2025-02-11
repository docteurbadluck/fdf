/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:32:13 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 10:57:49 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	min_max_z(t_field *field);

void	allocate_point3d(t_field *field)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (field->array_int[i])
	{
		j = 0;
		while (field->array_int[i][j])
			j++;
		i++;
	}
	field->point3d = malloc ((i * j + 1) * sizeof(t_point_3d));
}

void	init_3d_point(t_field *field)
{
	int	i;
	int	j;
	int	k;

	allocate_point3d(field);
	i = 0;
	k = 0;
	while (field->array_int[i])
	{
		j = 0;
		while (field->array_int[i][j])
		{
			field->point3d[k].x = i;
			field->point3d[k].y = j;
			field->point3d[k].z = *field->array_int[i][j];
			field->point3d[k].last = 0;
			k++;
			j++;
		}
		i++;
	}
	field->point3d[k].last = 1;
	min_max_z(field);
}

void	min_max_z(t_field *field)
{
	int	min_z;
	int	max_z;
	int	i;

	min_z = field->point3d[0].z;
	max_z = field->point3d[0].z;
	i = 0;
	while (field->point3d[i].last == 0)
	{
		if (field->point3d[i].z < min_z)
			min_z = field->point3d[i].z;
		if (field->point3d[i].z > max_z)
			max_z = field->point3d[i].y;
		i++;
	}
	field->min_z = min_z;
	field->max_z = max_z;
}

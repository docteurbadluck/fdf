/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 10:05:53 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_array_of_str(char ***array);
void	print_array_of_int(int ***array);
void	print_array_of_point3d(t_point_3d *array);
void	print_array_of_point2d(t_point_2d *array);

void	print_any_array(void *array, int type)
{
	char		***str_array;
	int			***int_array;
	t_point_3d	*point_array;
	t_point_2d	*point2d_array;

	if (type == STR)
	{
		str_array = array;
		print_array_of_str(str_array);
	}
	else if (type == INT)
	{
		int_array = array;
		print_array_of_int(int_array);
	}
	else if (type == POINT3D)
	{
		point_array = array;
		print_array_of_point3d(point_array);
	}
	else if (type == POINT2D)
	{
		point2d_array = array;
		print_array_of_point2d(point2d_array);
	}
}

void	print_array_of_str(char ***array)
{
	int	i;
	int	j;

	i = 0;
	ft_printf("\tPRINT STR***: \n\n");
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			ft_printf("[%d][%d] =%s\t", i, j, array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	ft_printf("\n");
}

void	print_array_of_int(int ***array)
{
	int	i;
	int	j;

	ft_printf("\tPRINT INT***: \n\n");
	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			ft_printf("[%d][%d] =%d\t", i, j, *array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_array_of_point3d(t_point_3d *ar)
{
	int	i;

	ft_printf("\tPRINT POINT3D*: \n\n");
	i = 0;
	while (!ar[i].last)
	{
		ft_printf("[%d] x=%d\ty=%d\tz=%d\t\n", i, ar[i].x, ar[i].y, ar[i].z);
		i++;
	}
}

void	print_array_of_point2d(t_point_2d *ar)
{
	int	i;

	ft_printf("\tPRINT POINT2D*: \n\n");
	i = 0;
	while (ar[i].last == 0)
	{
		printf("i[%d]x = %f\t y = %f \nscreen_x = %d, screen_y = %d, z = %d\n\n",
			i, ar[i].x, ar[i].y, ar[i].screen_x, ar[i].screen_y, ar[i].z);
		i++;
	}
}

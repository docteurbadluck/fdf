/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:49:12 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/03 12:14:00 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_array_of_str(char ***array);
void	print_array_of_int(int ***array);


void	print_any_array(void *array, int type)
{
	char	***str_array;
	int		***int_array;

	if (type == 0)
	{
		str_array = array;
		print_array_of_str(str_array);
	}
	else if (type == 1)
	{
		int_array = array;
		print_array_of_int(int_array);
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
		while(array[i][j])
		{
			ft_printf("[%d][%d] =%s\t",i,j, array[i][j]);
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
		while(array[i][j])
		{
			ft_printf("[%d][%d] =%d\t",i,j, *array[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_of_str_to_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:43:25 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/03 12:49:04 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void count_tab( int *i, int *j, char ***array);
static void allocate_array(int i, int j, int ****new);


int ***array_of_str_to_int(char ***array)
{
	int	i;
	int	j;
	int k;
	int ***new;

	count_tab(&i, &j, array);
	allocate_array(i, j, &new);

	i = 0;
	j = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			*new[i][j] = ft_atoi(array[i][j]);
			j++;
		}
		i++;
	}
	//print_array_of_int(new);
	return new;
}

static void count_tab( int *i, int *j, char ***array)
{

	*i = 0;
	while (array[*i])
	{
		*j = 0;
		while (array[*i][*j])
		{
			(*j)++;
		}
		(*i)++;
	}
}

static void allocate_array(int i, int j, int ****new)
{
	int k;
	
	*new = malloc((i + 1) * sizeof(int **));
	k = 0; 
	while (k < i)
	{
		(*new)[k] = malloc((1 + j) * sizeof(int *));
		k++;
	}
	(*new)[i] = NULL;
	i = 0;
	while ((*new)[i])
	{
		k = 0;
		while (k < j)
		{
			(*new)[i][k] = malloc(sizeof(int));
			k++;
		}
		(*new)[i][j] = NULL;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_any_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:45:37 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 09:33:58 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	free_array_of_int(int ***int_array);
static void	free_array_of_str(char ***array);

void	free_any_array(void *array, int type)
{
	char	***str_array;
	int		***int_array;

	if (type == 0)
	{
		str_array = array;
		free_array_of_str(str_array);
	}
	else if (type == 1)
	{
		int_array = array;
		free_array_of_int(int_array);
	}
}

static void	free_array_of_str(char ***array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = 0;
		while (array[i][j])
		{
			free(array[i][j]);
			j++;
		}
		free(array[i]);
		i++;
	}
	free(array);
}

static void	free_array_of_int(int ***int_array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (int_array[i] != NULL)
	{
		j = 0;
		while (int_array[i][j] != NULL)
		{
			free(int_array[i][j]);
			j++;
		}
		free(int_array[i]);
		i++;
	}
	free(int_array);
}

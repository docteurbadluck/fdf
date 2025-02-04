/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   any_test_on_str_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:17:00 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/03 17:23:11 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int test_on_array_of_array_of_str(char ***array_array_str, int (*f)(char *str))
{
	int i = 0;
	int j;
	while (array_array_str[i])
	{
		j = 0;
		while (array_array_str[i][j])
		{
			if (f(array_array_str[i][j]))
				return -1;
			j++;
		}
		i++;
	}
	return (0);
}

int	any_test_on_str_array(char **array_str, int (*f)(char *str))
{
	int	i;

	i = 0;
	while(array_str[i])
	{
		if (f(array_str[i]))
			return -1; //error
		i++;
	}
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_number_of_column_in_array.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 09:57:17 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 10:19:32 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	same_number_of_column_in_str_array(char ***array_str)
{
	int	i;
	int	j;
	int	flag;

	j = 0;
	i = 0;
	while (array_str[0][j])
		j++;
	flag = j;
	while (array_str[i])
	{
		j = 0;
		while (array_str[i][j])
		{
			j++;
		}
		if (flag != j)
			return (-1);
		i++;
	}
	return (0);
}

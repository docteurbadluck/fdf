/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:12:57 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 10:20:04 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int	has_digit(char *str);

//control if the input is corect. (sign allow, one digit required)
int	valid_input(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!has_digit(str))
		return (-1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '\n' && str[i] != ' ')
			{
				return (-1);
			}
		}
		i++;
	}
	return (0);
}

static int	has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]))
			return (1);
		i++;
	}
	return (0);
}

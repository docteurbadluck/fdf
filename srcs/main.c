/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 11:11:43 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int argc, char **argv)
{
	t_field	field;

	if (argc == 2)
	{
		init_field(&field, argv);
		render_line(&field);
		mlx_loop(field.mlx_ptr);
	}
	else
		ft_printf("Usage : <file> <deepness> <space width>");
	return (0);
}

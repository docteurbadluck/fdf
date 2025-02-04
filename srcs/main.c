/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 10:56:07 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/03 17:56:23 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	main(int argc, char **argv)
{
	t_field field;

	if (argc == 4)
	{
		//array_str = from_file_to_array(argv, 100);
		field.array_str = from_file_to_array(argv[1]);
		ft_printf("result test %d\n", test_on_array_of_array_of_str(field.array_str, valid_input));
		field.array_int = array_of_str_to_int(field.array_str);
		init_field(&field, argv);
		mlx_loop(field.mlx_ptr);
	}
	else
	{
		ft_printf("Usage : <file> <deepness> <space width>");
	}

	return 0;
}

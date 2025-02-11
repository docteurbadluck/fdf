/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_file_to_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:15:44 by tdeliot           #+#    #+#             */
/*   Updated: 2025/02/11 09:43:35 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size);

char	***from_file_to_array(char *file)
{
	char	***ar;
	char	***tmp;
	char	*line;
	int		fd;
	int		i;

	fd = open(file, O_RDONLY);
	i = 0;
	ar = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			break ;
		}
		ar = ft_realloc(ar, (i * sizeof (char **)),
				(i + 1) * sizeof(char **));
		ar[i] = ft_split(line, ' ');
		free(line);
		i++;
	}
	ar = ft_realloc(ar, (i * sizeof (char **)), (i + 1) * sizeof (char **));
	ar[i] = NULL;
	return (ar);
}

void	*ft_realloc(void *old_ptr, size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (old_size == new_size)
		return (old_ptr);
	if (new_size == 0)
	{
		free(old_ptr);
		return (NULL);
	}
	if (old_size < new_size) 
		copy_size = old_size;
	else 
		copy_size = new_size;
	if (old_ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		ft_memcpy(new_ptr, old_ptr, copy_size);
		free(old_ptr);
	}
	else 
		new_ptr = malloc(new_size);
	return (new_ptr);
}

void	*ft_realloc_array_of_str(void *old_ptr,
			size_t old_size, size_t new_size)
{
	void	*new_ptr;
	size_t	copy_size;

	if (old_size == new_size)
		return (old_ptr);
	if (new_size == 0)
	{
		free_any_array((char ***)old_ptr, STR);
		return (NULL);
	}
	if (old_size < new_size) 
		copy_size = old_size;
	else 
		copy_size = new_size;
	if (old_ptr)
	{
		new_ptr = malloc(new_size);
		if (!new_ptr)
			return (NULL);
		ft_memcpy(new_ptr, old_ptr, copy_size);
		free_any_array((char ***)old_ptr, STR);
	}
	else 
		new_ptr = malloc(new_size);
	return (new_ptr);
}

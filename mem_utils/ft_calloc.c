/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 22:41:35 by schahir           #+#    #+#             */
/*   Updated: 2024/10/26 13:39:18 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_calloc - Allocate and zero-initialize memory
 *
 * @count: Number of elements to allocate
 * @size: Size of each element
 *
 * Returns: Pointer to allocated memory, or NULL on failure
 */
void	*ft_calloc(size_t count, size_t size)
{
	void	*allocated_memory;
	size_t	total_size;

	if (size && count > ((size_t)-1) / size)
		return (NULL);
	total_size = count * size;
	allocated_memory = malloc(total_size);
	if (!allocated_memory)
		return (NULL);
	ft_bzero(allocated_memory, total_size);
	return (allocated_memory);
}

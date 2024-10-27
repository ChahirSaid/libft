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

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*arr;

	arr = malloc(nelem * elsize);
	if (!arr)
		return (0);
	ft_bzero(arr, nelem * elsize);
	return (arr);
}

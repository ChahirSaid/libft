/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 15:07:43 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 17:11:05 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstsize - counts the number of elements in a list.
 *
 * @lst: The beginning of the list.
 *
 * Return: The number of elements in the list.
 */
int	ft_lstsize(t_list *lst)
{
	t_list	*node;
	int		len;

	node = lst;
	len = 0;
	while (node)
	{
		len++;
		node = node->next;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:01:52 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 22:32:17 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstclear - deletes and frees the given element and every
 *				successor of that element, using the function ’del’
 *				and free(3). Finally, the pointer to the list must be set
 *				to NULL.
 *
 * @lst: The address of a pointer to an element.
 * @del: The address of the function used to delete the content of the element.
 *
 * Return: None.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}

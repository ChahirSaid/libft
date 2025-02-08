/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 22:20:08 by schahir           #+#    #+#             */
/*   Updated: 2024/10/27 22:32:25 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/**
 * ft_lstiter - iterates the list ’lst’ and applies the function ’f’ to the
 *				content of each element.
 *
 * @lst: The address of a pointer to an element.
 * @f: The address of the function used to iterate on the list.
 *
 * Return: None.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

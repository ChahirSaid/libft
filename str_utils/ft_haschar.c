/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_haschar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schahir <schahir@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:48:52 by schahir           #+#    #+#             */
/*   Updated: 2024/10/24 12:01:13 by schahir          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * ft_haschar - Check if a character exists in a string
 *
 * @str: String to search
 * @target: Character to search for
 *
 * Returns: 1 if the character is found, 0 otherwise
 */
int	ft_haschar(char *str, char target)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == target)
			return (1);
		str++;
	}
	return (0);
}

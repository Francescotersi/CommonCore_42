/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:01:18 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:47:41 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* DESCRIPTION
The  strcmp()  function compares the two strings s1 and s2.  The locale
is not taken into account. It  returns an integer less than, equal to, 
or greater than zero if s1 is found, respectively, to be less than,
to match,  or  be greater than s2.
The  strncmp()  function  is similar, except it compares only the first
(at most) n bytes of s1 and s2.
 */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	if (s1 == NULL || s2 == NULL)
		return (s1[0] - s2[0]);
	i = 0;
	while (i < n)
	{
		if (s1[i] && s1[i] == s2[i])
		{
			while (s1[i] && s1[i] == s2[i] && i < n)
				i++;
		}
		else
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

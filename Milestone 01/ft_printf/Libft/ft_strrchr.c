/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 10:57:18 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:47:53 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* The strrchr() function returns a pointer to the LAST occurrence of  the
       character c in the string s. */

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	else
	{
		while (i >= 0)
		{
			if (s[i] == c)
			{
				return ((char *)(s + i));
			}
			i--;
		}
		return ((NULL));
	}
}

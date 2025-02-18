/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:58:29 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:48:04 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a copy of
’s1’ with the characters specified in ’set’ removed
from the beginning and the end of the string. */

static int	ft_settimesbeg(const char *str, const char *set)
{
	int	i;
	int	count;
	int	j;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		i++;
	}
	return (count);
}

static int	ft_settimeslast(const char *str, const char *set)
{
	int	len;
	int	count;
	int	j;

	len = ft_strlen(str);
	count = 0;
	while (len > 0)
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (str[len - 1] == set[j])
			{
				count++;
				break ;
			}
			j++;
		}
		if (set[j] == '\0')
			break ;
		len--;
	}
	return (count);
}

char	*ft_strtrim(const char *str, const char *set)
{
	char	*trimmed_str;
	int		nsetbeg;
	int		nsetlast;
	int		len_trimmed;

	if (str == NULL || set == NULL)
		return (NULL);
	nsetbeg = ft_settimesbeg(str, set);
	nsetlast = ft_settimeslast(str, set);
	len_trimmed = ft_strlen(str) - nsetbeg - nsetlast;
	if (len_trimmed < 0)
		len_trimmed = 0;
	trimmed_str = malloc(sizeof(char) * (len_trimmed + 1));
	if (trimmed_str == NULL)
		return (NULL);
	ft_strlcpy(trimmed_str, str + nsetbeg, len_trimmed + 1);
	return (trimmed_str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:02:43 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:39:39 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns an array
of strings obtained by splitting ’s’ using the
character ’c’ as a delimiter. The array must end
with a NULL pointer. */

static int	ft_lookforwords(char const *s, char c)
{
	int	i;
	int	wc;

	wc = 0;
	i = 0;
	while (s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i - 1] != c)
			wc++;
		i++;
	}
	if (s[i] == '\0' && s[i - 1] != c && i > 0)
		wc++;
	return (wc);
}

static int	ft_allocrows(char const *s, char c, char **ret, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		len++;
		i++;
	}
	ret[0] = ft_substr(&s[i - len], 0, len);
	return (i);
}

static char	**ft_free(char **ret)
{
	int	i;

	i = 0;
	while (ret[i])
	{
		free(ret[i]);
		i++;
	}
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ret = (char **)malloc(sizeof(char *) * ((ft_lookforwords(s, c) * \
			ft_strlen(s)) + 1));
	if (!ret)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			i = ft_allocrows(s, c, &ret[j], i);
			if (!ret[j])
				return (ft_free(ret));
			j++;
		}
		else
			i++;
	}
	ret[j] = NULL;
	return (ret);
}

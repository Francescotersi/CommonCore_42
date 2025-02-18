/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:27:01 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:47:48 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione strnstr è una funzione della libreria C che cerca una 
sottostringa all'interno di una stringa, limitando la ricerca a un 
numero massimo di caratteri (ovvero un numero definito dalla dimensione 
della stringa). È simile a strstr, ma con la differenza che nella 
versione strnstr puoi specificare quanta parte della stringa 
principale vuoi considerare per la ricerca. */

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	little_len;

	if (!little || !little[0])
		return ((char *)big);
	little_len = ft_strlen(little);
	if (little_len > len || little_len > ft_strlen(big))
		return (NULL);
	i = 0;
	while (i < len - little_len + 1)
	{
		if (big[i] == little[0])
		{
			if (ft_strncmp(&big[i], little, little_len) == 0)
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}

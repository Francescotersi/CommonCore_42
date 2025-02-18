/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 09:24:23 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/04 11:33:36 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione esplora i primi n byte della memoria puntata da s e cerca il 
valore specificato da c. Se trova una corrispondenza, restituisce un puntatore 
a quella posizione nella memoria. Altrimenti, restituisce NULL. */

void	*ft_memchr(const void *src, int c, size_t length)
{
	const unsigned char	*string;
	unsigned char		sample;
	size_t				counter;

	string = src;
	sample = c;
	counter = 0;
	while (counter < length)
	{
		if (string[counter] == sample)
		{
			return ((void *)(string + counter));
		}
		counter++;
	}
	return ((NULL));
}

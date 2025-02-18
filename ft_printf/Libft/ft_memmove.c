/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:25:56 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:38:02 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione memmove copia n byte da un blocco di memoria all'altro, 
gestendo correttamente anche i casi in cui i due blocchi di memoria 
si sovrappongono. A differenza di memcpy, che non gestisce la sovrapposizione 
tra origine e destinazione, memmove garantisce che i dati vengano 
copiati correttamente, anche quando src e dest si sovrappongono. */

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char			*destination;
	const unsigned char		*source;
	size_t					counter;

	if (dest == NULL && src == NULL)
		return (NULL);
	counter = 0;
	destination = (unsigned char *)dest;
	source = (const unsigned char *)src;
	if (dest <= src)
	{
		while (counter < n)
		{
			destination[counter] = source[counter];
			counter++;
		}
	}
	else if (dest > src)
	{
		counter = n;
		while (counter-- > 0)
			destination[counter] = source[counter];
	}
	return (dest);
}

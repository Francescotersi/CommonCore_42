/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:24:00 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:37:53 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione memcpy copia n byte dalla memoria indicata da src alla memoria 
indicata da dest. I byte vengono copiati uno per uno, senza alcun tipo di 
controllo sui contenuti dei dati (ad esempio, non gestisce la sovrapposizione 
tra i due blocchi di memoria). Se i blocchi di memoria si sovrappongono, 
il comportamento è indefinito, quindi in questi casi si dovrebbe usare memmove, 
che gestisce la sovrapposizione correttamente. */

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*source;
	unsigned char	*destination;
	size_t			counter;

	if (dest == NULL && src == NULL)
		return (NULL);
	counter = 0;
	source = (unsigned char *)src;
	destination = (unsigned char *)dest;
	while (counter < n)
	{
		destination[counter] = source[counter];
		counter++;
	}
	return (dest);
}

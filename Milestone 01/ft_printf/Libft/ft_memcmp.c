/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:12:28 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:37:44 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione memcmp confronta i primi n byte di due blocchi di 
memoria (s1 e s2). Se i blocchi sono uguali fino al byte n, restituisce 0. 
Se ci sono differenze, la funzione restituisce una valore negativo o 
positivo, che riflette la differenza tra i byte che non sono uguali. */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			counter;

	string1 = (unsigned char *)s1;
	string2 = (unsigned char *)s2;
	counter = 0;
	while (counter < n)
	{
		if (string1[counter] != string2[counter])
			return (string1[counter] - string2[counter]);
		counter++;
	}
	return (0);
}

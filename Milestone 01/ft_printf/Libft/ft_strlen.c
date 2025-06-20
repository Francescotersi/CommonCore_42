/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:13:38 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:46:53 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione strlen è una delle funzioni più comuni in C, ed è utilizzata per 
calcolare la lunghezza di una stringa. Essa restituisce il numero di caratteri 
presenti in una stringa, escludendo il carattere di terminazione \0 
(null terminator), che segna la fine della stringa in C. */

size_t	ft_strlen(const char *str)
{
	size_t	lenght;

	lenght = 0;
	while (*(str + lenght) != '\0')
	{
		lenght ++;
	}
	return (lenght);
}

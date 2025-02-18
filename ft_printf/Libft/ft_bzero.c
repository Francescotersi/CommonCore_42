/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 10:44:31 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:34:06 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione bzero in C serve a impostare a zero una porzione di memoria.
Dove s è il puntatore alla memoria da azzerare e n è la dimensione in byte. 
Sebbene fosse ampiamente utilizzata in passato, oggi bzero è deprecata e si 
preferisce utilizzare memset per maggiore flessibilità */

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*string;
	size_t			counter;

	counter = 0;
	string = s;
	while (counter < n)
	{
		string[counter] = '\0';
		counter++;
	}
}

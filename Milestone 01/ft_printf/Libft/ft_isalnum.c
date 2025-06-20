/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 14:52:12 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/09 08:32:28 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* La funzione isalnum in C è una funzione della libreria standard <ctype.h> 
che verifica se un carattere è alfanumerico, ossia se è una lettera 
(maiuscola o minuscola) o una cifra. Restituisce un valore diverso da zero
(vero) se il carattere è alfanumerico, e zero (falso) altrimenti. */

int	ft_isalnum(int c)
{
	if (((65 <= c && c <= 90) || (97 <= c && c <= 122)) || \
	(c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}

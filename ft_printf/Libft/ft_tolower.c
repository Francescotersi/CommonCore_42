/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:03:37 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:48:16 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Una funzione che restituisce il carattere dato in argomento come minuscolo */

int	ft_tolower(int c)
{
	if (90 >= c && c >= 65)
	{
		return (c + 32);
	}
	return (c);
}

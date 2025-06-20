/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:06:38 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:36:09 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Una funzione che stabilisce se il valore passatogli e' un ascii */

int	ft_isascii(int c)
{
	if ((c >= 0) & (c <= 127))
	{
		return (1);
	}
	return (0);
}

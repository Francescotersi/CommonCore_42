/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 17:39:26 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/02 12:48:21 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Una funzione che restituisce il carattere dato in argomento come maiuscolo */

int	ft_toupper(int c)
{
	if (122 >= c && c >= 97)
	{
		return (c - 32);
	}
	return (c);
}

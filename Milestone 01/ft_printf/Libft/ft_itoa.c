/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:43:35 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/09 08:32:08 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates (with malloc(3)) and returns a string
representing the integer received as an argument.
Negative numbers must be handled. */

static int	ft_numlenght(int nb)
{
	int	length;

	length = 0;
	if (nb < 0)
	{
		nb = -nb;
		length++;
	}
	while (nb > 0)
	{
		nb /= 10;
		length++;
	}
	if (length == 0)
		length = 1;
	return (length);
}

static char	*ft_minnb(int n, char *ret)
{
	if (n == -2147483648)
	{
		ret = malloc(12 * sizeof(char));
		ret[0] = '-';
		ret[1] = '2';
		ret[2] = '1';
		ret[3] = '4';
		ret[4] = '7';
		ret[5] = '4';
		ret[6] = '8';
		ret[7] = '3';
		ret[8] = '6';
		ret[9] = '4';
		ret[10] = '8';
		ret[11] = '\0';
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		i;
	int		sign;

	if (n == -2147483648)
		return (ft_minnb(n, (number = NULL)));
	i = ft_numlenght(n);
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n = -n;
	}
	number = malloc((i + 1) * sizeof(int));
	if (number == NULL)
		return (NULL);
	number[i] = '\0';
	if (sign == 1)
		number[0] = '-';
	while (i-- > sign)
	{
		number[i] = (n % 10) + '0';
		n = n / 10;
	}
	return (number);
}

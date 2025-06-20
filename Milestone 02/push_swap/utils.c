/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:50:47 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:56:39 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	matrix_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		i++;
	}
	return (i);
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	print_matrix(char **matrix)
{
	int	counter;

	counter = 0;
	while (matrix[counter])
	{
		ft_printf("%s\n", matrix[counter]);
		counter++;
	}
}

int	check_nsign(const char *nptr, int i)
{
	if (nptr[i] == '+')
	{
		i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (1);
	}
	if (nptr[i] == '-')
	{
		i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (1);
		return (2);
	}
	return (0);
}

long	atol(const char *nptr)
{
	long	i;
	long	minus;
	long	number;
	long	sign;

	i = 0;
	minus = 1;
	number = 0;
	sign = check_nsign(nptr, i);
	if (sign == 1)
		return (1);
	else if (sign == 2)
	{
		minus *= -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9'))
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	if (number == -2147483648)
		return (-2147483648);
	return (number * minus);
}

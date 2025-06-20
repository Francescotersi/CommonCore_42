/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:30:38 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:51:26 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	string_check(char **av)
{
	int	count;

	count = 0;
	if (string_is_digit(av, count) == 1)
		return (write_error(), 1);
	if (gt_st_int(av, count) == 1)
		return (write_error(), 1);
	return (0);
}

int	gt_st_int(char **av, int count)
{
	long	l;

	l = 0;
	while (av[count])
	{
		l = atol(av[count]);
		if (l < -2147483648 || l > 2147483647)
			return (1);
		count++;
		if (!av[count])
			return (0);
	}
	return (1);
}

int	string_is_digit(char **av, int count)
{
	while (av[count] && push_isdigit(av[count]) == 0)
	{
		count++;
		if (!av[count])
			return (0);
	}
	return (1);
}

int	*matrix_to_int(char **av, int *mx)
{
	int	len;

	len = matrix_len(av);
	mx = ft_calloc(sizeof(int), len + 1);
	if (!mx)
		return (0);
	len = 0;
	while (av[len])
	{
		mx[len] = ft_atoi(av[len]);
		len++;
	}
	return (mx);
}

int	equal_numbers(int *mx, char **av)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = matrix_len(av);
	while (j < len)
	{
		i = 0;
		while (i < len)
		{
			if (i == j)
				i++;
			if (i >= len)
				break ;
			if (mx[i] == mx[j])
				return (1);
			i++;
		}
		j++;
	}
	return (0);
}

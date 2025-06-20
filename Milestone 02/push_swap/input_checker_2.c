/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_checker_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:02:24 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:54:52 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**normal_sized_matrix(char **av)
{
	char	**temp;
	int		i;
	int		j;

	i = matrix_len(av);
	temp = ft_calloc(sizeof(char *), i + 2);
	if (!temp)
		return (write_error(), NULL);
	j = 1;
	i = 0;
	while (av[j])
	{
		temp[i] = av[j];
		i++;
		j++;
	}
	return (temp);
}

int	push_isdigit(char *str)
{
	int	count;

	count = 0;
	if (str[0] == '+' || str[0] == '-')
	{
		count++;
		if (str[1] == '+' || str[1] == '-')
			return (1);
	}
	while (ft_isdigit(str[count]) == 1)
	{
		count++;
		if (str[count] == '\0')
			return (0);
	}
	return (1);
}

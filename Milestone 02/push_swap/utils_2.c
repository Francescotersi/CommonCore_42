/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 15:25:23 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:50:23 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_list(t_data *thing, t_h_ls *lists)
{
	t_list	*start;
	int		i;

	i = 1;
	start = ft_lstnew(thing->mx[0]);
	lists->a = start;
	while (i < thing->matrix_len)
	{
		ft_lstadd_back(&lists->a, ft_lstnew(thing->mx[i]));
		i++;
	}
	start = NULL;
	free_list(start);
}

void	free_list(t_list *x)
{
	t_list	*temp;

	while (x)
	{
		temp = x->next;
		free(x);
		x = temp;
	}
}

void	print_list(t_list *x)
{
	while (x != NULL)
	{
		printf("%d\n", x->content);
		x = x->next;
	}
}

void	del(void *content)
{
	int	sium;

	sium = 0;
	if (content)
		sium += 1;
	else
		sium = 7;
}

int	stack_len(t_list *stack)
{
	int	count;

	if (NULL == stack)
		return (0);
	count = 0;
	while (stack)
	{
		++count;
		stack = stack->next;
	}
	return (count);
}

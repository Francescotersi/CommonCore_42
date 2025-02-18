/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 10:51:08 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:55:50 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// ritorna il nodo meno costoso
t_list	*return_cheapest(t_list *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// trova il nodo piu piccolo
t_list	*find_smallest(t_list	*stack)
{
	long	smallest;
	t_list	*smallest_node;

	if (stack == NULL)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->content < smallest)
		{
			smallest = stack->content;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

void	write_error(void)
{
	write(2, "Error\n", 6);
}

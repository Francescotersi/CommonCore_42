/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 11:28:58 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/18 08:35:09 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finisce la rotazione nel senso che lui continua a fare ra o rra finche il 
// nodo meno caro non arriva in cima allo stack B o allo stack A in base
// a cio che gli passi
void	finish_rotation(t_list *stack, t_list *top_node, char stack_name, \
							t_h_ls *lists)
{
	while (stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(lists);
			else
				rra(lists, 1);
			stack = lists->a;
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(lists);
			else
				rrb(lists, 1);
			stack = lists->b;
		}
	}
}

// il loop si ferma quando il nodo meno costoso arriva in cima ad A o a B
void	rr_both(t_h_ls *lists, t_list *cheapest_node)
{
	while (lists->a != cheapest_node->target_node && lists->b != cheapest_node)
		rrr(lists);
	set_current_position(lists->a);
	set_current_position(lists->b);
}

// il loop si ferma quando il nodo meno costoso arriva in cima ad A o a B
void	r_both(t_h_ls *lists, t_list *cheapest_node)
{
	while (lists->a != cheapest_node->target_node && lists->b != cheapest_node)
		rr(lists);
	set_current_position(lists->a);
	set_current_position(lists->b);
}

// muove i nodi da B in A,
// fa andare ai limiti degli stack i target node e poi pusha in A
void	move_nodes(t_h_ls *lists)
{
	t_list	*cheapest_node;

	cheapest_node = return_cheapest(lists->b);
	if (cheapest_node->above_median && \
			cheapest_node->target_node->above_median)
		while (cheapest_node->above_median && \
				cheapest_node->target_node->above_median && \
				cheapest_node != lists->b && \
				cheapest_node->target_node != lists->a)
			r_both(lists, cheapest_node);
	else if (!(cheapest_node->above_median) && \
			!(cheapest_node->target_node->above_median))
		while (!(cheapest_node->above_median) && \
				!(cheapest_node->target_node->above_median) && \
				cheapest_node != lists->b && \
				cheapest_node->target_node != lists->a)
			rr_both(lists, cheapest_node);
	finish_rotation(lists->b, cheapest_node, 'b', lists);
	finish_rotation(lists->a, cheapest_node->target_node, 'a', lists);
	pa(lists);
}

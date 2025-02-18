/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 09:55:34 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:56:49 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// trova il nodo meno costoso da pushare
void	set_cheapest(t_list *stack)
{
	long	best_value;
	t_list	*best_node;

	if (stack == NULL)
		return ;
	best_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_price < best_value)
		{
			best_value = stack->push_price;
			best_node = stack;
		}
		stack->cheapest = 0;
		stack = stack->next;
	}
	best_node->cheapest = 1;
}

// mette il prezzo di mosse ai nodi
void	set_price(t_h_ls *lists)
{
	int	len_b;
	int	len_a;

	len_a = stack_len(lists->a);
	len_b = stack_len(lists->b);
	while (lists->b)
	{
		lists->b->push_price = lists->b->current_position;
		if (!(lists->b->above_median))
			lists->b->push_price = len_b - (lists->b->current_position);
		if (lists->b->target_node->above_median)
			lists->b->push_price += lists->b->target_node->current_position;
		else
			lists->b->push_price += \
				len_a - (lists->b->target_node->current_position);
		lists->b = lists->b->next;
	}
}

// assegna ad ogni nodo in b il suo target in a
// lo assegan al nodo con il valore piu alto, se
// questo non esiste lo assegna al piu piccolo                  
void	target_node(t_h_ls *lists)
{
	t_list	*current_a;
	t_list	*target_node;
	long	its_a_match;

	while (lists->b)
	{
		its_a_match = LONG_MAX;
		current_a = lists->a;
		while (current_a)
		{
			if (current_a->content > lists->b->content && \
				current_a->content < its_a_match)
			{
				its_a_match = current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (its_a_match == LONG_MAX)
			lists->b->target_node = find_smallest(lists->a);
		else
			lists->b->target_node = target_node;
		lists->b = lists->b->next;
	}
}

// setta la posizione corrente di ogni nodo in base a dove si trova nella lista
// e se sta sopra o sotto la mediana(prima o dopo la meta della lista)
void	set_current_position(t_list *stack)
{
	int	i;
	int	stack_middle;

	i = 0;
	if (stack == NULL)
		return ;
	stack_middle = stack_len(stack) / 2;
	while (stack)
	{
		stack->current_position = i;
		if (i <= stack_middle)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

void	node_init(t_h_ls *lists)
{
	t_list	*temp;

	set_current_position(lists->a);
	set_current_position(lists->b);
	temp = lists->b;
	target_node(lists);
	lists->b = temp;
	set_price(lists);
	lists->b = temp;
	set_cheapest(lists->b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:30:33 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/10 09:58:09 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// pusha tutto in B, per ogni configurazione trova il nodo meno costoso e 
// ripusha tutto in A in ordine
void	big_sort(t_h_ls *lists)
{
	int		len_a;
	t_list	*smallest;

	len_a = stack_len(lists->a);
	while (len_a-- > 3)
		pb(lists);
	case_ft_3(lists);
	while (lists->b)
	{
		node_init(lists);
		move_nodes(lists);
	}
	set_current_position(lists->a);
	smallest = find_smallest(lists->a);
	if (smallest->above_median)
	{
		while (lists->a != smallest)
			ra(lists);
	}
	else
	{
		while (lists->a != smallest)
			rra(lists, 1);
	}
}

void	start(t_data *thing, t_h_ls *lists)
{
	fill_list(thing, lists);
	if (all_sorted(thing) == 1 || special_cases(lists, thing) == 1)
	{
		free_list(lists->a);
		free_list(lists->b);
		return ;
	}
	big_sort(lists);
	free_list(lists->a);
	free_list(lists->b);
}

int	push_swap(int ac, char **av, t_data *thing, t_h_ls *lists)
{
	if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		if (string_check(av) == 1)
			return (free_matrix(av), 1);
		thing->mx = matrix_to_int(av, thing->mx);
		if (equal_numbers(thing->mx, av) == 1)
			return (free(thing->mx), free_matrix(av), write_error(), 1);
		thing->matrix_len = matrix_len(av);
		free_matrix(av);
	}
	else if (ac > 2)
	{
		av = normal_sized_matrix(av);
		if (string_check(av) == 1)
			return (free(av), 1);
		thing->mx = matrix_to_int(av, thing->mx);
		if (equal_numbers(thing->mx, av) == 1)
			return (free(thing->mx), free(av), write_error(), 1);
		thing->matrix_len = matrix_len(av);
		free(av);
	}
	start(thing, lists);
	free(thing->mx);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	thing;
	t_h_ls	lists;

	lists.a = NULL;
	lists.b = NULL;
	if (ac >= 2)
		return (push_swap(ac, av, &thing, &lists), 0);
	return (0);
}

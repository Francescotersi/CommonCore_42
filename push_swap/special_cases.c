/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:44:39 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:53:10 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_ft_5(t_h_ls *lists)
{
	smallest_finder(lists);
	if (lists->b->content < lists->b->next->content)
		sb(lists);
	case_ft_3(lists);
	pa(lists);
	pa(lists);
}

void	case_ft_3(t_h_ls *lists)
{
	int	first;
	int	second;
	int	third;

	first = lists->a->content;
	second = lists->a->next->content;
	third = lists->a->next->next->content;
	if (first > second && third > second && third > first)
		sa(lists);
	else if (first > second && first > third && third > second)
		ra(lists);
	else if (first < second && second > third && first > third)
		rra(lists, 1);
	else if (first < third && second > third && first < third)
	{
		sa(lists);
		ra(lists);
	}
	else if (first > second && first > third && second > third)
	{
		sa(lists);
		rra(lists, 1);
	}
}

void	case_ft_2(t_h_ls *lists)
{
	if (lists->a->content > lists->a->next->content)
		sa(lists);
	else
		return ;
}

int	all_sorted(t_data *thing)
{
	int	i;

	i = 1;
	while (i < thing->matrix_len && thing->mx[i - 1] < thing->mx[i])
		i++;
	if (i == thing->matrix_len)
		return (1);
	return (0);
}

int	special_cases(t_h_ls *lists, t_data *thing)
{
	if (thing->matrix_len == 2)
	{
		case_ft_2(lists);
		return (1);
	}
	else if (thing->matrix_len == 3)
	{
		case_ft_3(lists);
		return (1);
	}
	else if (thing->matrix_len == 4)
	{
		case_ft_4(lists);
		return (1);
	}
	else if (thing->matrix_len == 5)
	{
		case_ft_5(lists);
		return (1);
	}
	return (0);
}

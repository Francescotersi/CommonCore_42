/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 09:12:46 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:56:12 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	case_ft_4(t_h_ls *lists)
{
	smallest_finder_2(lists);
	case_ft_3(lists);
	pa(lists);
}

void	smallest_finder_2(t_h_ls *lists)
{
	int		lowest;
	int		other_low;
	t_list	*tmp;

	lowest = lists->a->content;
	tmp = lists->a;
	while (tmp != NULL)
	{
		if (lowest > tmp->content)
			lowest = tmp->content;
		tmp = tmp->next;
	}
	tmp = lists->a;
	if (tmp->content == lowest)
		other_low = tmp->next->content;
	else
		other_low = tmp->content;
	while (tmp != NULL)
	{
		if (other_low > tmp->content && lowest != tmp->content)
			other_low = tmp->content;
		tmp = tmp->next;
	}
	smallest_to_b_2(lowest, lists);
}

void	smallest_to_b_2(int lowest, t_h_ls *lists)
{
	int	i;

	i = 0;
	while (i < 1)
	{
		if (lists->a->content == lowest)
		{
			pb(lists);
			i++;
		}
		else
			ra(lists);
	}
}

void	smallest_finder(t_h_ls *lists)
{
	int		lowest;
	int		other_low;
	t_list	*tmp;

	lowest = lists->a->content;
	tmp = lists->a;
	while (tmp != NULL)
	{
		if (lowest > tmp->content)
			lowest = tmp->content;
		tmp = tmp->next;
	}
	tmp = lists->a;
	if (tmp->content == lowest)
		other_low = tmp->next->content;
	else
		other_low = tmp->content;
	while (tmp != NULL)
	{
		if (other_low > tmp->content && lowest != tmp->content)
			other_low = tmp->content;
		tmp = tmp->next;
	}
	smallest_to_b(lowest, other_low, lists);
}

void	smallest_to_b(int lowest, int other_low, t_h_ls *lists)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (lists->a->content == lowest || lists->a->content == other_low)
		{
			pb(lists);
			i++;
		}
		else
			ra(lists);
	}
}

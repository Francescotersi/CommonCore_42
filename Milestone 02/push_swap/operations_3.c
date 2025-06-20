/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:07:30 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:56:55 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_h_ls *lists, int check)
{
	t_list	*temp;
	t_list	*temp_2;

	temp_2 = lists->a;
	while (temp_2->next && temp_2->next->next)
		temp_2 = temp_2->next;
	temp = temp_2->next;
	temp_2->next = NULL;
	ft_lstadd_front(&lists->a, temp);
	if (check == 1)
		ft_printf("rra\n");
}

void	rrb(t_h_ls *lists, int check)
{
	t_list	*temp;
	t_list	*temp_2;

	temp_2 = lists->b;
	while (temp_2->next && temp_2->next->next)
		temp_2 = temp_2->next;
	temp = temp_2->next;
	temp_2->next = NULL;
	ft_lstadd_front(&lists->b, temp);
	if (check == 1)
		ft_printf("rrb\n");
}

void	rrr(t_h_ls *lists)
{
	rra(lists, 0);
	rrb(lists, 0);
	ft_printf("rrr\n");
}

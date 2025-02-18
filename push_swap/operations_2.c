/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:55:42 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:55:23 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_h_ls *lists)
{
	t_list	*temp;

	temp = lists->a;
	lists->a = lists->a->next;
	temp->next = NULL;
	ft_lstadd_back(&lists->a, temp);
	ft_printf("ra\n");
}

void	rb(t_h_ls *lists)
{
	t_list	*temp;

	temp = lists->b;
	lists->b = lists->b->next;
	temp->next = NULL;
	ft_lstadd_back(&lists->b, temp);
	ft_printf("rb\n");
}

void	rr(t_h_ls *lists)
{
	t_list	*temp;
	t_list	*temp_2;

	temp = lists->a;
	lists->a = lists->a->next;
	temp->next = NULL;
	ft_lstadd_back(&lists->a, temp);
	temp_2 = lists->b;
	lists->b = lists->b->next;
	temp_2->next = NULL;
	ft_lstadd_back(&lists->b, temp_2);
	ft_printf("rr\n");
}

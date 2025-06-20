/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:33:18 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/07 14:15:18 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_h_ls *lists)
{
	t_list	*temp;

	if (lists->a == NULL || lists->a->next == NULL)
	{
		ft_printf("sa\n");
		return ;
	}
	temp = lists->a->next;
	lists->a->next = temp->next;
	temp->next = lists->a;
	lists->a = temp;
	ft_printf("sa\n");
}

void	sb(t_h_ls *lists)
{
	t_list	*temp;

	if (lists->b == NULL || lists->b->next == NULL)
	{
		ft_printf("sb\n");
		return ;
	}
	temp = lists->b->next;
	lists->b->next = temp->next;
	temp->next = lists->b;
	lists->b = temp;
	ft_printf("sb\n");
}

void	ss(t_h_ls *lists)
{
	t_list	*temp;
	t_list	*temp_2;

	if (lists->a == NULL || lists->a->next == NULL)
	{
		ft_printf("ss\n");
		return ;
	}
	if (lists->b == NULL || lists->b->next == NULL)
	{
		ft_printf("ss\n");
		return ;
	}
	temp = lists->a->next;
	lists->a->next = temp->next;
	temp->next = lists->a;
	lists->a = temp;
	temp_2 = lists->b->next;
	lists->b->next = temp_2->next;
	temp_2->next = lists->b;
	lists->b = temp_2;
	ft_printf("ss\n");
}

void	pa(t_h_ls *lists)
{
	t_list	*temp;

	if (lists->b == NULL)
	{
		ft_printf("pa\n");
		return ;
	}
	temp = lists->b->next;
	ft_lstadd_front(&lists->a, lists->b);
	lists->b = temp;
	ft_printf("pa\n");
}

void	pb(t_h_ls *lists)
{
	t_list	*temp;

	if (lists->a == NULL)
	{
		ft_printf("pb\n");
		return ;
	}
	temp = lists->a->next;
	ft_lstadd_front(&lists->b, lists->a);
	lists->a = temp;
	ft_printf("pb\n");
}

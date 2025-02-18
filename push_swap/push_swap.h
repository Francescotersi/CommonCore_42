/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:30:36 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/08 10:55:40 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Push_libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <stdbool.h>
# include <limits.h>

typedef struct s_data
{
	int		matrix_len;
	int		*mx;
}				t_data;

typedef struct s_h_ls
{
	t_list	*a;
	t_list	*b;
}				t_h_ls;

void	start(t_data *thing, t_h_ls *lists);
int		push_swap(int ac, char **av, t_data *thing, t_h_ls *lists);
int		string_check(char **av);
int		*matrix_to_int(char **av, int *mx);

int		push_isdigit(char *str);
int		string_is_digit(char **av, int count);
int		gt_st_int(char **av, int count);
long	atol(const char *nptr);
int		check_nsign(const char *nptr, int i);
int		equal_numbers(int *mx, char **av);
char	**normal_sized_matrix(char **av);

void	fill_list(t_data *thing, t_h_ls *lists);
int		all_sorted(t_data *thing);

int		special_cases(t_h_ls *lists, t_data *thing);
void	case_ft_2(t_h_ls *lists);
void	case_ft_3(t_h_ls *lists);
void	case_ft_4(t_h_ls *lists);
void	case_ft_5(t_h_ls *lists);

void	sa(t_h_ls *lists);
void	sb(t_h_ls *lists);
void	ss(t_h_ls *lists);
void	pa(t_h_ls *lists);
void	pb(t_h_ls *lists);
void	ra(t_h_ls *lists);
void	rb(t_h_ls *lists);
void	rr(t_h_ls *lists);
void	rra(t_h_ls *lists, int check);
void	rrb(t_h_ls *lists, int check);
void	rrr(t_h_ls *lists);

void	big_sort(t_h_ls *lists);
void	node_init(t_h_ls *lists);
void	set_current_position(t_list *stack);
void	target_node(t_h_ls *lists);
t_list	*find_smallest(t_list	*stack);
void	set_price(t_h_ls *lists);
void	set_cheapest(t_list *stack);
void	move_nodes(t_h_ls *lists);
void	r_both(t_h_ls *lists, t_list *cheapest_node);
void	rr_both(t_h_ls *lists, t_list *cheapest_node);
void	finish_rotation(t_list *stack, t_list *top_n, char stack_name, \
						t_h_ls *lists);
t_list	*return_cheapest(t_list *stack);

int		stack_len(t_list *stack);
void	print_matrix(char **matrix);
void	free_matrix(char **matrix);
void	write_error(void);
int		matrix_len(char **av);
void	free_list(t_list *x);
void	print_list(t_list *x);
void	del(void *content);
void	smallest_finder(t_h_ls *lists);
void	smallest_to_b(int lowest, int other_low, t_h_ls *lists);
void	smallest_finder_2(t_h_ls *lists);
void	smallest_to_b_2(int lowest, t_h_ls *lists);

#endif
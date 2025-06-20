/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:51:38 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 09:23:41 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	action_print(t_philos *philosophy, int id, char *str)
{
	t_data	*gen;

	gen = philosophy->gen;
	pthread_mutex_lock(&gen->writing);
	pthread_mutex_lock(&gen->check_dead);
	if (gen->death == 0 && c_ate(gen) == 0)
	{
		printf("%lld ", timestamp() - gen->t_start_program);
		printf("%d ", id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&gen->check_dead);
	pthread_mutex_unlock(&gen->writing);
}

void	destroy_mutex(t_philos *philosophy)
{
	int	i;

	i = 0;
	while (i < philosophy->gen->n_philo)
	{
		pthread_mutex_destroy(&philosophy[i].fork);
		i++;
	}
	pthread_mutex_destroy(&philosophy->gen->writing);
	pthread_mutex_destroy(&philosophy->gen->check_fork);
	pthread_mutex_destroy(&philosophy->gen->check_dead);
	pthread_mutex_destroy(&philosophy->gen->check_meal);
	pthread_mutex_destroy(&philosophy->gen->check_time);
	pthread_mutex_destroy(&philosophy->gen->death_timer_check);
	pthread_mutex_destroy(&philosophy->gen->loop_check);
	pthread_mutex_destroy(&philosophy->gen->check_all_ate);
}

int	check_nsign(const char *nptr, int i)
{
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		i++;
		if (nptr[i] == '+' || nptr[i] == '-')
			return (1);
		return (2);
	}
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int	i;
	int	minus;
	int	number;
	int	sign;

	i = 0;
	minus = 1;
	number = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	sign = check_nsign(nptr, i);
	if (sign == 1)
		return (0);
	while (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			minus *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		number = number * 10 + (nptr[i] - '0');
		i++;
	}
	return (number * minus);
}

int	ft_isdigit_and_positive(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '+')
		{
			i++;
			continue ;
		}
		if (str[i] >= 48 && str[i] <= 57)
		{
			i++;
			continue ;
		}
		return (1);
	}
	return (0);
}

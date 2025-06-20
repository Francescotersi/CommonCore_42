/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 15:38:50 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 09:22:25 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mutex_init_2(t_data *gen)
{
	if (pthread_mutex_init(&gen->check_meal, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&gen->check_time, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&gen->death_timer_check, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&gen->loop_check, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&gen->check_all_ate, NULL) != 0)
		return (1);
	return (0);
}

int	mutex_init(t_data *gen)
{
	int	i;

	i = 0;
	while (i < gen->n_philo)
	{
		if (pthread_mutex_init(&gen->philosophy[i].fork, NULL) != 0)
			return (1);
		i++;
	}
	i = -1;
	while (++i < gen->n_philo)
	{
		if (i == 0)
			gen->philosophy[i].left_philo_mutex = \
				&gen->philosophy[gen->n_philo - 1].fork;
		else
			gen->philosophy[i].left_philo_mutex = &gen->philosophy[i - 1].fork;
	}
	if (pthread_mutex_init(&gen->writing, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&gen->check_fork, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&gen->check_dead, NULL) != 0)
		return (1);
	return (0);
}

/* inizializzazione della struttura dei filosofi */
void	data_init(t_data *gen)
{
	int	i;

	i = 0;
	while (i < gen->n_philo)
	{
		gen->philosophy[i].id = i + 1;
		gen->philosophy[i].x_meal = 0;
		gen->philosophy[i].last_meal = 0;
		gen->philosophy[i].gen = gen;
		i++;
	}
}

int	init_all(t_data *gen, char **av, bool check)
{
	gen->n_philo = ft_atoi(av[1]);
	gen->n_fork = gen->n_philo;
	gen->t_die = (long long)ft_atoi(av[2]);
	gen->t_eat = ft_atoi(av[3]);
	gen->t_sleep = ft_atoi(av[4]);
	gen->all_ate = 0;
	gen->death = 0;
	gen->t_start_program = 0;
	if (check == true)
	{
		gen->total_meal = ft_atoi(av[5]);
		if (gen->total_meal <= 0)
			return (1);
	}
	else
		gen->total_meal = -1;
	if (mutex_init(gen) == 1)
		return (printf("Error\nMutex\n"), 0);
	if (mutex_init_2(gen) == 1)
		return (printf("Error\nMutex\n"), 0);
	data_init(gen);
	return (0);
}

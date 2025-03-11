/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 09:37:28 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 10:16:15 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// create the thread when just one philo exists

int	one_philo_case(t_philos *philosophy)
{
	if (pthread_create(&philosophy->philo, NULL, brute_force_1, \
			philosophy) != 0)
		return (1);
	return (0);
}

void	*brute_force_1(void *thread)
{
	t_philos	*philosophy;
	t_data		*gen;

	philosophy = (t_philos *)thread;
	gen = philosophy->gen;
	pthread_mutex_lock(&philosophy->fork);
	action_print(philosophy, philosophy->id, "has taken a fork");
	pthread_mutex_unlock(&philosophy->fork);
	better_usleep(gen->t_die, gen);
	action_print(philosophy, philosophy->id, "died");
	return (0);
}

// rendi questa funzione la routine del checker della morte

void	death(t_data *gen, t_philos *philosophy)
{
	while (!(c_ate(gen)))
	{
		usleep(100);
		if (check_all_meals(gen, philosophy) == 1)
		{
			pthread_mutex_lock(&gen->check_all_ate);
			gen->all_ate = 1;
			pthread_mutex_unlock(&gen->check_all_ate);
			return ;
		}
		if (check_death(gen, philosophy) == 1)
			return ;
	}
}

// philo spleep (he is a sleepy boy)

void	ft_sleep(t_philos *philosophy)
{
	action_print(philosophy, philosophy->id, "is sleeping");
	better_usleep(philosophy->gen->t_sleep, philosophy->gen);
}

// i filosofi guardano la propria forchetta e quella del filosofo 
// alla propria sinistra il timer della morte inzia 
// dall`inizio dell`ultimo pasto
void	eat(t_philos *philosophy)
{
	t_data	*gen;

	gen = philosophy->gen;
	lock_forks(gen, philosophy);
	action_print(philosophy, philosophy->id, "has taken a fork");
	action_print(philosophy, philosophy->id, "has taken a fork");
	action_print(philosophy, philosophy->id, "is eating");
	pthread_mutex_lock(&gen->check_time);
	philosophy->last_meal = timestamp();
	pthread_mutex_unlock(&gen->check_time);
	better_usleep(gen->t_eat, gen);
	pthread_mutex_unlock(philosophy->left_philo_mutex);
	pthread_mutex_unlock(&philosophy->fork);
	pthread_mutex_lock(&gen->check_meal);
	philosophy->x_meal++;
	pthread_mutex_unlock(&gen->check_meal);
}

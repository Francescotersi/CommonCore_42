/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 08:37:14 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 10:25:10 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// // check the death of every philosophers 

int	check_death(t_data *gen, t_philos *philosophy)
{
	int			i;
	long long	value;

	i = 0;
	while (i < gen->n_philo || !(mutex_return_death(gen->death, gen)))
	{
		pthread_mutex_lock(&gen->check_time);
		value = philosophy[i].last_meal;
		pthread_mutex_unlock(&gen->check_time);
		if (timestamp() - value >= mutex_return_t_die(gen->t_die, gen))
		{
			action_print(&philosophy[i], philosophy[i].id, "died");
			pthread_mutex_lock(&gen->check_dead);
			gen->death = 1;
			pthread_mutex_unlock(&gen->check_dead);
			return (1);
		}
		i++;
		if (i == gen->n_philo || mutex_return_death(gen->death, gen))
			break ;
		usleep(1000);
	}
	return (0);
}

// // lock forks for mutex lock order

void	lock_forks(t_data *gen, t_philos *philosophy)
{
	if (philosophy->id == 1)
	{
		pthread_mutex_lock(&gen->philosophy->fork);
		pthread_mutex_lock(philosophy->left_philo_mutex);
	}
	else
	{
		pthread_mutex_lock(philosophy->left_philo_mutex);
		pthread_mutex_lock(&philosophy->fork);
	}
}

void	unlock_forks(t_data *gen, t_philos *philosophy)
{
	if (philosophy->id == 0)
	{
		pthread_mutex_unlock(gen->philosophy->left_philo_mutex);
		pthread_mutex_unlock(&gen->philosophy->fork);
	}
	else
	{
		pthread_mutex_unlock(philosophy->left_philo_mutex);
		pthread_mutex_unlock(&philosophy->fork);
	}
}

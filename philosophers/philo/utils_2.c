/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 11:28:07 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 09:26:40 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_all_meals(t_data *gen, t_philos *philosophy)
{
	int	i;
	int	meals;

	i = 0;
	pthread_mutex_lock(&gen->check_meal);
	meals = philosophy[i].x_meal;
	pthread_mutex_unlock(&gen->check_meal);
	while (gen->total_meal != -1 && i < gen->n_philo && \
		meals >= gen->total_meal)
	{
		pthread_mutex_lock(&gen->check_meal);
		meals = philosophy[i].x_meal;
		pthread_mutex_unlock(&gen->check_meal);
		i++;
	}
	if (i == gen->n_philo)
		return (1);
	return (0);
}

void	better_usleep(long long time, t_data *gen)
{
	long long	i;
	int			death;

	pthread_mutex_lock(&gen->check_dead);
	death = gen->death;
	pthread_mutex_unlock(&gen->check_dead);
	i = timestamp();
	while (!(death))
	{
		if (diff_timestamp(timestamp(), i) >= time)
			break ;
		usleep(1);
	}
}

long long	diff_timestamp(long long present, long long past)
{
	return (present - past);
}

long long	timestamp(void)
{
	struct timeval	temp;

	gettimeofday(&temp, NULL);
	return ((temp.tv_sec * 1000) + (temp.tv_usec / 1000));
}

void	join_threads(t_data *gen)
{
	int	i;

	i = 0;
	while (i < gen->n_philo)
	{
		pthread_join(gen->philosophy[i].philo, NULL);
		i++;
	}
}

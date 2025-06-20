/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_returns.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:02:21 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 10:04:40 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// these functions are useful cause they dont cause data races when 
// accessing the values of some parameters, so that i can use these values
// inside if and whileconditions whiout doing a 
// mess with mutex locks and ulocks

long long	mutex_return_meal(long long mutex, t_data *gen)
{
	long long	value;

	pthread_mutex_lock(&gen->check_time);
	value = mutex;
	pthread_mutex_unlock(&gen->check_time);
	return (value);
}

int	mutex_return_death(int mutex, t_data *gen)
{
	int	value;

	pthread_mutex_lock(&gen->check_dead);
	value = mutex;
	pthread_mutex_unlock(&gen->check_dead);
	return (value);
}

long long	mutex_return_t_die(long long mutex, t_data *gen)
{
	long long	value;

	pthread_mutex_lock(&gen->death_timer_check);
	value = mutex;
	pthread_mutex_unlock(&gen->death_timer_check);
	return (value);
}

int	c_ate(t_data *gen)
{
	int	value;

	pthread_mutex_lock(&gen->check_all_ate);
	value = gen->all_ate;
	pthread_mutex_unlock(&gen->check_all_ate);
	return (value);
}

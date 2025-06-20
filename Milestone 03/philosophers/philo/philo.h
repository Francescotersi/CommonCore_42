/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:35:02 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 09:19:23 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <stdbool.h> 
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <pthread.h>

struct	s_philos;

typedef struct s_data
{
	int				all_ate;
	int				death;
	int				total_meal;
	int				n_philo;
	int				n_fork;
	long long		t_die;
	int				t_eat;
	int				t_sleep;
	long long		t_start_program;
	pthread_mutex_t	writing;
	pthread_mutex_t	check_fork;
	pthread_mutex_t	check_dead;
	pthread_mutex_t	check_meal;
	pthread_mutex_t	death_timer_check;
	pthread_mutex_t	check_time;
	pthread_mutex_t	loop_check;
	pthread_mutex_t	check_all_ate;
	struct s_philos	*philosophy;
	struct timeval	tv;
}	t_data;

typedef struct s_philos
{
	int				id;
	int				x_meal;
	long long		last_meal;
	pthread_mutex_t	*left_philo_mutex;
	pthread_mutex_t	fork;
	pthread_t		philo;
	t_data			*gen;
}	t_philos;

int			arg_parsing(char **av);
int			philosophers(int ac, char **av, t_data *gen);
void		*launcher(void *thread);
int			start(t_data *gen);

int			init_all(t_data *gen, char **av, bool check);
int			mutex_init(t_data *gen);
void		data_init(t_data *gen);
void		destroy_mutex(t_philos *philosophy);
void		join_threads(t_data *gen);
int			mutex_return_death(int mutex, t_data *gen);
long long	mutex_return_meal(long long mutex, t_data *gen);

int			ft_atoi(const char *nptr);
int			check_nsign(const char *nptr, int i);
int			ft_isdigit_and_positive(char *str);
void		action_print(t_philos *philosophy, int id, char *str);
long long	timestamp(void);
long long	diff_timestamp(long long present, long long past);
void		better_usleep(long long time, t_data *gen);

int			one_philo_case(t_philos *philosophy);
void		*brute_force_1(void *thread);
void		eat(t_philos *philosophy);
void		think(t_philos *philosophy);
void		ft_sleep(t_philos *philosophy);
void		death(t_data *gen, t_philos *philosophy);
int			check_all_meals(t_data *gen, t_philos *philosophy);
int			c_ate(t_data *gen);

// void		*death_checker(void *thread);
long long	mutex_return_t_die(long long mutex, t_data *gen);
int			check_death(t_data *gen, t_philos *philosophy);
void		lock_forks(t_data *gen, t_philos *philosophy);

#endif
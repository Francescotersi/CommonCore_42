/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:33:45 by ftersill          #+#    #+#             */
/*   Updated: 2025/03/11 11:45:48 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
// PER TUTTE LE BOOLEANE SE SONO VERE GLI ARGOMENTI PASSATI SONO 6
// QUINDI SONO STATE INSERITE ANCHE LE VOLTE CHE I FILOSOFI DEVONO MANGIARE

/* la funzione forza l`ingresso dell`ordine dei filosofi: se sono pari entrano
   prima i dispari, se sono dispari entrano prima i pari */
void	*launcher(void *thread)
{
	t_data		*gen;
	t_philos	*philosophy;

	philosophy = (t_philos *)thread;
	gen = philosophy->gen;
	pthread_mutex_lock(&gen->check_time);
	philosophy->last_meal = timestamp();
	pthread_mutex_unlock(&gen->check_time);
	if (philosophy->id % 2 == 1)
		usleep(100);
	while (mutex_return_death(gen->death, gen) == 0 && c_ate(gen) == 0)
	{
		eat(philosophy);
		ft_sleep(philosophy);
		action_print(philosophy, philosophy->id, "is thinking");
		usleep(1000);
	}
	return (0);
}
/* crea thread e fa iniziare la routine, poi manda il processo principale 
   a fare controlli sulla morte e sul numero totale di pasti fatti */

int	start(t_data *gen)
{
	t_philos	*philosophy;
	int			i;

	i = 0;
	philosophy = gen->philosophy;
	gen->t_start_program = timestamp();
	if (gen->n_philo == 1)
	{
		if (one_philo_case(philosophy) == 1)
			return (1);
		join_threads(gen);
		return (0);
	}
	while (i < gen->n_philo)
	{
		if (pthread_create(&philosophy[i].philo, NULL, launcher, \
				&philosophy[i]) != 0)
			return (1);
		i++;
	}
	usleep(1000);
	death(gen, philosophy);
	join_threads(gen);
	destroy_mutex(philosophy);
	return (0);
}

int	arg_parsing(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		if (ft_isdigit_and_positive(av[i]) == 1)
			return (1);
		j = ft_atoi(av[i]);
		if (j <= 0)
			return (1);
		i++;
	}
	return (0);
}

int	philosophers(int ac, char **av, t_data *gen)
{
	if (arg_parsing(av) == 1)
		return (printf("Please insert valid parameters\n"), 0);
	if (ac == 5)
	{
		if (init_all(gen, av, false) == 1)
			return (printf("Error\n"));
	}
	else if (ac == 6)
	{
		if (init_all(gen, av, true) == 1)
			return (printf("Error\n"));
	}
	if (start(gen) == 1)
		return (printf("Error\n"), 1);
	return (0);
}

int	main(int ac, char **av)
{
	t_data		gen;
	t_philos	*philosophy;
	int			result;
	int			i;

	i = 0;
	result = 0;
	philosophy = gen.philosophy;
	if (ac == 5 || ac == 6)
	{
		if (ft_atoi(av[1]) <= 0)
			return (printf("Please insert valid parameters\n"));
		gen.philosophy = (t_philos *)malloc(ft_atoi(av[1]) * sizeof(t_philos));
		if (!gen.philosophy)
			return (printf("alloc error\n"), 1);
		result = philosophers(ac, av, &gen);
		free(gen.philosophy);
		return (0);
	}
	printf("insert: n_philo tm_die tm_eat tm_sleep tms_philo_eat(optional)\n");
	return (0);
}

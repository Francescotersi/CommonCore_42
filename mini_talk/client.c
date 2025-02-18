/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:02:20 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:16 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

// 													     \O     \>
//                                                          ==B  |
// FAI ALTRI TEST CON VALORI DIFFERENTI PER GLI USLEEP ! /O     />

static void	send_char_to_server(char c, int server_pid)
{
	static int	i;

	i = 0;
	while (i < 8)
	{
		if (0x01 & c)
		{
			if (kill(server_pid, SIGUSR1) == -1)
				return ;
		}
		else
		{
			if (kill(server_pid, SIGUSR2) == -1)
				return ;
		}
		c >>= 1;
		i++;
		usleep(800);
	}
	usleep(333);
}

int	main(int ac, char **av)
{
	int	server_pid;
	int	i;

	i = 0;
	if (ac != 3)
		return (ft_printf("insert : ./client server_pid (message)"), 0);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		return (ft_printf("PID = -1 is invalid change it"), 0);
	while (av[2][i])
	{
		send_char_to_server(av[2][i], server_pid);
		i++;
	}
	return (0);
}

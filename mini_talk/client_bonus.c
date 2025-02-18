/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:14:03 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/17 09:41:37 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static void	action(int signal, siginfo_t *info, void *s)
{
	(void)s;
	(void)info;
	if (signal == SIGUSR1)
		ft_printf("The server received the message correctly!\n");
	exit(0);
}

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
	int					server_pid;
	int					i;
	struct sigaction	sa;
	t_data				mum;

	i = 0;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = action;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	if (ac != 3)
		return (ft_printf("insert : ./client server_pid (message)"), 0);
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
		return (ft_printf("PID = -1 is invalid change it"), 0);
	mum.str = av[2];
	mum.str_len = ft_strlen(av[2]);
	while (av[2][i])
	{
		send_char_to_server(av[2][i], server_pid);
		i++;
	}
	send_char_to_server(av[2][i], server_pid);
	pause();
	return (0);
}

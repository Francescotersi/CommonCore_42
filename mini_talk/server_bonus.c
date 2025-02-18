/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:14:00 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/17 09:42:17 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk_bonus.h"

static void	bits_to_char(int signal, siginfo_t *info, void *s)
{
	static int			bits = 0;
	static int			i = 0;
	static pid_t		c_pid;

	(void)s;
	c_pid = info->si_pid;
	if (signal == SIGUSR1)
		i |= (0x01 << bits);
	else if (signal == SIGUSR2)
		;
	else
		return ;
	bits++;
	if (bits == 8)
	{
		write(STDOUT_FILENO, &i, 1);
		if (i == 0)
		{
			write(1, "\n", 1);
			kill(c_pid, SIGUSR1);
		}
		i = 0;
		bits = 0;
		usleep(100);
	}
}

int	main(void)
{
	struct sigaction	sa;
	int					server_pid;

	server_pid = getpid();
	if (server_pid <= 0)
		return (ft_printf("PID is invalid"), 0);
	ft_printf("SERVER PID = %d\n", server_pid);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = bits_to_char;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}

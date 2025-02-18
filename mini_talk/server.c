/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 10:02:17 by ftersill          #+#    #+#             */
/*   Updated: 2025/02/12 14:21:44 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static void	bits_to_char(int signal, siginfo_t *info, void *s)
{
	static int	bits = 0;
	static int	i = 0;

	(void)info;
	(void)s;
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

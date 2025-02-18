/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 11:32:33 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/09 08:26:49 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Outputs the integer ’n’ to the given file
descriptor. */

void	ft_putnbr_fd(int n, int fd)
{
	char	nb;

	if (n >= 10 || n <= -10)
		ft_putnbr_fd(n / 10, fd);
	else
		if (n < 0)
			write(fd, "-", 1);
	if (n < 0)
		nb = ((n % 10) * -1) + '0';
	else
		nb = (n % 10) + '0';
	write (fd, &nb, 1);
}

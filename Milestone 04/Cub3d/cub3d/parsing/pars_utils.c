/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:23:20 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/10 16:48:45 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//Returna 1 se l'arrray mem e' pieno (ossia se tutti i suoi elementi sono
//uguali a 1), 0 se non e' pieno
int	mem_full(int mem[6])
{
	int	i;

	i = 0;
	while (i < 6)
		if (mem[i++] != 1)
			return (0);
	return (1);
}

int	count_collums(int fd, char *str)
{
	int		count;
	int		new_line;

	count = 0;
	new_line = 0;
	while (str != NULL)
	{
		count++;
		free(str);
		str = get_next_line_bonus(fd);
		if (str && ft_strncmp(str, "\n", 1) == 0)
			new_line++;
		else if (str == NULL)
			return (free(str), close(fd), count - new_line);
		else
			new_line = 0;
	}
	return (free(str), close(fd), -1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:23:20 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 07:34:29 by mfanelli         ###   ########.fr       */
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

void	size_init(t_data *gen, int size)
{
	gen->map_width = size;
	gen->mini_size = 16;
	if (gen->map_height > 60 || gen->map_width > 120)
		gen->mini_size = 4;
	else if (gen->map_height > 30 || gen->map_width > 60)
		gen->mini_size = 8;
}

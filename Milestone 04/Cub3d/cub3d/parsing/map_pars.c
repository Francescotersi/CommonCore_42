/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 09:19:03 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/29 15:46:45 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//Controlla la presenza di un player
int	find_player(t_data *gen, int i, int j)
{
	while (++i < gen->map_height)
	{
		j = -1;
		while (++j < (int)ft_strlen(gen->map[i]) && gen->map[i][j])
		{
			if (gen->player_pov == '\0' && (gen->map[i][j] == 'N' || \
			gen->map[i][j] == 'S' || gen->map[i][j] == 'E' || \
			gen->map[i][j] == 'W'))
			{
				gen->player_pov = gen->map[i][j];
				gen->x_player = j;
				gen->y_player = i;
			}
			else if (gen->player_pov != '\0' && (gen->map[i][j] == 'N' || \
			gen->map[i][j] == 'S' || gen->map[i][j] == 'E' || \
			gen->map[i][j] == 'W'))
				return (free_all(gen), error_print("Too many players"), 0);
		}
	}
	if (gen->player_pov == '\0')
		return (free_all(gen), error_print("Zero players in map"), 0);
	return (1);
}

//controlla che ci siano gli angoli, in modo da evitare seg-fault
int	map_has_angles(t_data *gen, int i, int j)
{
	if ((!gen->map[i - 1][j - 1]) || (gen->map[i - 1][j - 1] != \
	gen->player_pov && gen->map[i - 1][j - 1] != '1' && \
	gen->map[i - 1][j - 1] != '0'))
		return (free_all(gen), error_print("Map has not valid angles"), 0);
	if ((!gen->map[i - 1][j + 1]) || (gen->map[i - 1][j + 1] != \
	gen->player_pov && gen->map[i - 1][j + 1] != '1' && \
	gen->map[i - 1][j + 1] != '0'))
		return (free_all(gen), error_print("Map has not valid angles"), 0);
	if ((!gen->map[i + 1][j - 1]) || (gen->map[i + 1][j - 1] != \
	gen->player_pov && gen->map[i + 1][j - 1] != '1' && \
	gen->map[i + 1][j - 1] != '0'))
		return (free_all(gen), error_print("Map has not valid angles"), 0);
	if ((!gen->map[i + 1][j + 1]) || (gen->map[i + 1][j + 1] != \
	gen->player_pov && gen->map[i + 1][j + 1] != '1' && \
	gen->map[i + 1][j + 1] != '0'))
		return (free_all(gen), error_print("Map has not valid angles"), 0);
	return (1);
}

//Controlla che la mappa sia chiusa
int	map_is_closed(t_data *gen, int i, int j)
{
	if ((!gen->map[i][j + 1]) || (gen->map[i][j + 1] == '\n'))
		return (free_all(gen), error_print("Map is not valid"), 0);
	if (j == 0 || !gen->map[i][j - 1] || (gen->map[i][j - 1] == 32))
		return (free_all(gen), error_print("Map is not valid"), 0);
	if ((i == gen->map_height - 1) || ((int)ft_strlen(gen->map[i + 1]) - 2 \
	< j) || (gen->map[i + 1][j] == 32))
		return (free_all(gen), error_print("Map is not valid"), 0);
	if (i == 0 || ((int)ft_strlen(gen->map[i - 1]) - 2 < j) || \
	(gen->map[i - 1][j] == 32))
		return (free_all(gen), error_print("Map is not valid"), 0);
	if (map_has_angles(gen, i, j) == 0)
		return (0);
	return (1);
}

//Controlla se ci sono caratteri validi nella mappa e chiama
//find_player() e map_is_closed()
void	map_pars(t_data *gen)
{
	int	i;
	int	j;

	i = -1;
	find_player(gen, -1, -1);
	while (++i < gen->map_height && gen->map[i])
	{
		j = -1;
		while (gen->map[i][++j])
		{
			if (gen->map[i][j] == ' ' || gen->map[i][0] == '\0' || \
				(gen->map[i][j] >= 7 && gen->map[i][j] <= 13))
				continue ;
			else if (gen->map[i][j] != '1' && gen->map[i][j] != '0' && \
			gen->map[i][j] != 'N' && gen->map[i][j] != 'S' && gen->map[i][j] \
			!= 'E' && gen->map[i][j] != 'W')
			{
				free_all(gen);
				error_print("Invalid character found in map");
			}
			if (gen->map[i][j] != '1')
				map_is_closed(gen, i, j);
		}
	}
}

bool	xpm_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 4] != '.' || str[len - 3] != 'x' || \
		str[len - 2] != 'p' || str[len - 1] != 'm' || \
		str[len] != '\0')
		return (false);
	return (true);
}

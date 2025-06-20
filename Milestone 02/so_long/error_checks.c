/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:15:57 by ftersill          #+#    #+#             */
/*   Updated: 2025/01/28 14:43:33 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// controlla i bordi della mappa che siano 1
int	map_border_valid(t_mlx_data *data)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = (int)ft_strlen(data->map[0]);
	while (data->map[0][i] == '1')
		i++;
	if (data->map[0][i] != '1' && len != i)
		return (1);
	j = 1;
	while (data->map[j] && j < (data->matrix_len - 1))
	{
		if (data->map[j][0] != '1' || data->map[j][len - 1] != '1')
			return (1);
		j++;
	}
	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

// funzione che perfeziona get_next_line eliminando i \n
char	**map_truncate(char **map, int matrix_len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j] && (map[j][i] != '\0'))
	{
		if (map[j][i] == '\n')
		{
			map[j][i] = '\0';
			j++;
			i = 0;
		}
		i++;
	}
	return (map);
}

// controllo che le righe siano uguali
int	map_lines_not_equal(char **map, int matrix_len)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 1;
	len = ft_strlen(map[0]);
	while (map[j])
	{
		if (len != ft_strlen(map[j]))
			return (2);
		j++;
	}
	return (0);
}

// fa dei controlli sul numero di collezionabili, player e uscita
int	coll_exit_p1_checker(char **map, int matrix_len)
{
	int	p;
	int	c;
	int	e;

	p = essential(map, matrix_len, 'P');
	c = essential(map, matrix_len, 'C');
	e = essential(map, matrix_len, 'E');
	if (p != 1)
		return (ft_printf("Error\nThere`s not only one player on the map"), 3);
	else if (e != 1)
		return (ft_printf("Error\nThere`s not only one exit on the map"), 3);
	else if (c < 1)
		return (ft_printf("Error\nThere are not enough collectibles"), 3);
	return (0);
}

// ricerca gli essenziali (p,c,e) in base alla c
int	essential(char **map, int matrix_len, const char c)
{
	int	i;
	int	j;
	int	counter;

	i = 0;
	j = 0;
	counter = 0;
	while (map[j] && j < (matrix_len - 1))
	{
		if (map[j][i] == '\0')
		{
			i = 0;
			j++;
		}
		if (map[j][i] == c)
			counter++;
		i++;
	}
	return (counter);
}

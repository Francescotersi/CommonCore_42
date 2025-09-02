/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:47:51 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/29 12:06:45 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	actual_check_rgb_2(char *str, int *i, t_data *gen)
{
	while (str[(*i)] && str[(*i)] >= '0' && str[(*i)] <= '9')
		(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
	if ((str[(*i)] && str[(*i)] >= '0' && str[(*i)] >= '9') || str[(*i)] == '.')
	{
		free_all(gen);
		error_print("Invalid RGB format, should be R,G,B");
		return ;
	}
	else if (str[(*i)] == ',')
		(*i)++;
	while (str[(*i)] && str[(*i)] == ' ')
		(*i)++;
}

int	actual_check_rgb(char *str, int *i, t_data *gen)
{
	int	j;
	int	rgb_value;

	j = 0;
	while (str[(*i)])
	{
		if (str[(*i)] == ' ' && (str[(*i)] < '0' || str[(*i)] > '9'))
			return (free_all(gen), error_print("Invalid RGB value"), 0);
		rgb_value = ft_atoi(&str[(*i)]);
		if (rgb_value < 0 || rgb_value > 255)
			return (free_all(gen), error_print("RGB value out of range"), 0);
		actual_check_rgb_2(str, i, gen);
		j++;
	}
	if (j != 3)
		return (free_all(gen), \
		error_print("Invalid RGB format, should be R,G,B"), 0);
	return (1);
}

void	check_rgb(t_data *gen)
{
	int	i;

	i = 0;
	while (gen->floor[i])
	{
		if (gen->floor[i] >= '0' && gen->floor[i] <= '9')
			actual_check_rgb(gen->floor, &i, gen);
		else
			i++;
	}
	i = 0;
	while (gen->ceiling[i])
	{
		if (gen->ceiling[i] >= 48 && gen->ceiling[i] <= 57)
			actual_check_rgb(gen->ceiling, &i, gen);
		else
			i++;
	}
}

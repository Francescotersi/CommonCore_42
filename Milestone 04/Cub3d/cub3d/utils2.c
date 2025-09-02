/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:43:23 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/10 18:46:01 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// libera le str delle texture e dei colori
void	free_elements(t_data *gen)
{
	free(gen->no);
	free(gen->so);
	free(gen->ea);
	free(gen->we);
	free(gen->floor);
	free(gen->ceiling);
	free(gen->gen_ptr);
}

// libera tutto
void	free_all(t_data *gen)
{
	free_map(gen);
	free_elements(gen);
}

// libera la mappa
void	free_map(t_data *gen)
{
	int	i;

	i = 0;
	while (i < gen->map_height)
	{
		free(gen->map[i]);
		i++;
	}
	free(gen->map);
}

void	free_display(t_mlx_data *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

//Printa Error seguito dall'errore personalizzato str
void	error_print(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

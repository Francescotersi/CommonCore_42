/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:43:23 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/11 12:19:02 by mfanelli         ###   ########.fr       */
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
	free(gen->door_one);
	free(gen->door_two);
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
	mlx_destroy_image(mlx->mlx_ptr, mlx->mini_img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_destroy_display(mlx->mlx_ptr);
	free(mlx->mlx_ptr);
}

void	init_mlx_params(t_mlx_data *mlx)
{
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	mlx->mini_bpp = 0;
	mlx->mini_size_line = 0;
	mlx->mini_endian = 0;
	mlx->audio_pid = 0;
	mlx->column = -1;
	check_rgb_values(mlx->gen);
	mlx->floor_color = hexa_converter(mlx->gen->floor);
	mlx->ceiling_color = hexa_converter(mlx->gen->ceiling);
	mlx->item_one = false;
	mlx->item_two = false;
	mlx->item_three = false;
	mlx->audio_playing = false;
}

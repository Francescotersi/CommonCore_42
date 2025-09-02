/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 09:39:58 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 10:35:07 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	is_walkable(t_data *gen, double x, double y)
{
	int	mx;
	int	my;

	mx = (int)x;
	my = (int)y;
	return (mx >= 0 && mx < (int)ft_strlen(gen->map[my]) && \
			my >= 0 && my < gen->map_height && \
			gen->map[my][mx] != '1' && gen->map[my][mx] != 'X');
}

int	is_openable(t_data *gen, double x, double y, char c)
{
	int	mx;
	int	my;
	int	dist;

	dist = fixed_distance(gen->player, x, y);
	mx = (int)x / B_HEIGHT;
	my = (int)y / B_HEIGHT;
	return (mx >= 0 && mx < (int)ft_strlen(gen->map[my]) && \
	my >= 0 && my < gen->map_height && dist <= 1 && \
	gen->map[my][mx] == c && \
	gen->map[(int)gen->player->y_player][(int)gen->player->x_player] != 'O');
}

bool	is_lancer_on2(t_player *player, t_mlx_data *mlx, char *str)
{
	if (ft_strncmp(str, "right", ft_strlen(str)) == 0)
	{
		if (mlx->item_one == true)
			return (player->key_a);
		return (player->key_d);
	}
	if (ft_strncmp(str, "rot_left", ft_strlen(str)) == 0)
	{
		if (mlx->item_one == true)
			return (player->key_right);
		return (player->key_left);
	}
	if (ft_strncmp(str, "rot_right", ft_strlen(str)) == 0)
	{
		if (mlx->item_one == true)
			return (player->key_left);
		return (player->key_right);
	}
	return (false);
}

bool	is_lancer_on(t_player *player, t_mlx_data *mlx, char *str)
{
	if (ft_strncmp(str, "up", ft_strlen(str)) == 0)
	{
		if (mlx->item_one == true)
			return (player->key_s);
		return (player->key_w);
	}
	if (ft_strncmp(str, "down", ft_strlen(str)) == 0)
	{
		if (mlx->item_one == true)
			return (player->key_w);
		return (player->key_s);
	}
	if (ft_strncmp(str, "left", ft_strlen(str)) == 0)
	{
		if (mlx->item_one == true)
			return (player->key_d);
		return (player->key_a);
	}
	return (is_lancer_on2(player, mlx, str));
}

float	get_speed(t_mlx_data *mlx)
{
	if (mlx->item_two)
		return (MOVE_SPEED * 2);
	return (MOVE_SPEED);
}

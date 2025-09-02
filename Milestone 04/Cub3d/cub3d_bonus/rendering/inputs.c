/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:41:06 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/11 10:18:03 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	door_touch(float px, float py, t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = px / B_HEIGHT;
	y = py / B_HEIGHT;
	if (mlx->gen->map[y][x] == '1' || mlx->gen->map[y][x] == 'X' || \
	mlx->gen->map[y][x] == 'O')
		return (true);
	return (false);
}

void	walk3(t_player *player, t_mlx_data *mlx, double sin, double cos)
{
	if (is_lancer_on(player, mlx, "left"))
	{
		if (is_walkable(mlx->gen, player->x_player + get_speed(mlx) * \
		(sin * 2), player->y_player))
			player->x_player = player->x_player + get_speed(mlx) * sin;
		if (is_walkable(mlx->gen, player->x_player, player->y_player - \
			get_speed(mlx) * (cos * 2)))
			player->y_player = player->y_player - get_speed(mlx) * cos;
	}
	if (is_lancer_on(player, mlx, "right"))
	{
		if (is_walkable(mlx->gen, player->x_player - get_speed(mlx) * \
		(sin * 2), player->y_player))
			player->x_player = player->x_player - get_speed(mlx) * sin;
		if (is_walkable(mlx->gen, player->x_player, player->y_player + \
			get_speed(mlx) * (cos * 2)))
			player->y_player = player->y_player + get_speed(mlx) * cos;
	}
}

void	walk2(t_player *player, t_mlx_data *mlx, double sin, double cos)
{
	if (is_lancer_on(player, mlx, "up"))
	{
		if (is_walkable(mlx->gen, player->x_player + get_speed(mlx) * \
		(cos * 2), player->y_player))
			player->x_player = player->x_player + get_speed(mlx) * cos;
		if (is_walkable(mlx->gen, player->x_player, player->y_player + \
			get_speed(mlx) * (sin * 2)))
			player->y_player = player->y_player + get_speed(mlx) * sin;
	}
	if (is_lancer_on(player, mlx, "down"))
	{
		if (is_walkable(mlx->gen, player->x_player - get_speed(mlx) * \
		(cos * 2), player->y_player))
			player->x_player = player->x_player - get_speed(mlx) * cos;
		if (is_walkable(mlx->gen, player->x_player, player->y_player - \
			get_speed(mlx) * (sin * 2)))
			player->y_player = player->y_player - get_speed(mlx) * sin;
	}
	walk3(player, mlx, sin, cos);
}

void	walk(t_player *player, t_mlx_data *mlx, double new_x, double new_y)
{
	double	sin_angle;
	double	cos_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_act)
	{
		while (!door_touch(new_x, new_y, mlx))
		{
			new_x += (get_speed(mlx) * cos_angle);
			new_y += (get_speed(mlx) * sin_angle);
		}
		if (is_openable(mlx->gen, new_x, new_y, 'X'))
			mlx->gen->map[(int)(new_y / B_HEIGHT)] = \
			ft_replace(mlx->gen->map[(int)(new_y / B_HEIGHT)], 'X', 'O', \
			new_x / B_HEIGHT);
		else if (is_openable(mlx->gen, new_x, new_y, 'O'))
			mlx->gen->map[(int)(new_y / B_HEIGHT)] = \
			ft_replace(mlx->gen->map[(int)(new_y / B_HEIGHT)], 'O', 'X', \
			new_x / B_HEIGHT);
		player->key_act = false;
	}
}

// il player si muove in base al seno e al coseno dell`angolo
//(ovvero in base alla direzione in cui sta guardando)
void	move_player(t_player *player, t_data *gen, t_mlx_data *mlx)
{
	double	sin_angle;
	double	cos_angle;

	(void)gen;
	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (is_lancer_on(player, mlx, "rot_left"))
		player->angle -= ROTATION_SPEED;
	if (is_lancer_on(player, mlx, "rot_right"))
		player->angle += ROTATION_SPEED;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	walk(player, mlx, player->x_player * B_HEIGHT, \
	player->y_player * B_HEIGHT);
	walk2(player, mlx, sin_angle, cos_angle);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 10:41:06 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/10 17:12:39 by mfanelli         ###   ########.fr       */
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
	my >= 0 && my < gen->map_height && gen->map[my][mx] != '1');
}

void	walk2(t_player *p, t_data *gen, double sin, double cos)
{
	if (p->key_a)
	{
		if (is_walkable(gen, p->x_player + MOVE_SPEED * (sin * 2), p->y_player))
			p->x_player = p->x_player + MOVE_SPEED * sin;
		if (is_walkable(gen, p->x_player, p->y_player - MOVE_SPEED * (cos * 2)))
			p->y_player = p->y_player - MOVE_SPEED * cos;
	}
	if (p->key_d)
	{
		if (is_walkable(gen, p->x_player - MOVE_SPEED * (sin * 2), p->y_player))
			p->x_player = p->x_player - MOVE_SPEED * sin;
		if (is_walkable(gen, p->x_player, p->y_player + MOVE_SPEED * (cos * 2)))
			p->y_player = p->y_player + MOVE_SPEED * cos;
	}
}

void	walk1(t_player *p, t_data *gen, double sin, double cos)
{
	if (p->key_w)
	{
		if (is_walkable(gen, p->x_player + MOVE_SPEED * (cos * 2), p->y_player))
			p->x_player = p->x_player + MOVE_SPEED * cos;
		if (is_walkable(gen, p->x_player, p->y_player + MOVE_SPEED * (sin * 2)))
			p->y_player = p->y_player + MOVE_SPEED * sin;
	}
	if (p->key_s)
	{
		if (is_walkable(gen, p->x_player - MOVE_SPEED * (cos * 2), p->y_player))
			p->x_player = p->x_player - MOVE_SPEED * cos;
		if (is_walkable(gen, p->x_player, p->y_player - MOVE_SPEED * (sin * 2)))
			p->y_player = p->y_player - MOVE_SPEED * sin;
	}
	walk2(p, gen, sin, cos);
}

// il player si muove in base al seno e al coseno dell`angolo
//(ovvero in base alla direzione in cui sta guardando)
void	move_player(t_player *player, t_data *gen)
{
	double	sin_angle;
	double	cos_angle;

	cos_angle = cos(player->angle);
	sin_angle = sin(player->angle);
	if (player->key_left)
		player->angle -= ROTATION_SPEED;
	if (player->key_right)
		player->angle += ROTATION_SPEED;
	if (player->angle > 2 * PI)
		player->angle = 0;
	if (player->angle < 0)
		player->angle = 2 * PI;
	walk1(player, gen, sin_angle, cos_angle);
}

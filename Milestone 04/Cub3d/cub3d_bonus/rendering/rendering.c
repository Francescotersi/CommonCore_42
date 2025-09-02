/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:15:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 10:34:44 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_map(t_mlx_data *mlx, t_data *gen, int size)
{
	int		i;
	int		j;

	i = -1;
	if (mlx->gen->player->key_map)
	{
		while (++i < gen->map_height)
		{
			j = -1;
			while (++j < (int)ft_strlen(gen->map[i]))
			{
				if (gen->map[i][j] == '1' || gen->map[i][j] == 'X')
					draw_square(mlx, j * size + (size / 2), i * size + \
					(size / 2), 0XFFFFFF);
				else if (gen->map[i][j] == '0' || gen->map[i][j] == 'O' || \
				gen->map[i][j] == mlx->gen->player_pov || gen->map[i][j] == 'L')
					draw_square(mlx, j * size + (size / 2), i * size + \
					(size / 2), 0x00000000);
			}
		}
		draw_frame(mlx, 0X00C000);
	}
}

void	clear_image(t_mlx_data *mlx)
{
	int	i;
	int	j;

	i = -1;
	while (++i < SCREEN_Y)
	{
		j = -1;
		while (++j < SCREEN_X)
		{
			if (i > SCREEN_Y / 2)
				my_put_pixel(j, i, mlx->floor_color, mlx);
			else
				my_put_pixel(j, i, mlx->ceiling_color, mlx);
		}
	}
}

// calcoliamo la distanza dal punto di impatto sui quattro i bordi del blocco:
// dist_to_left = ray->delta_x -> distanza dal bordo sinistro
// dist_to_right = (B_HEIGHT - ray->delta_x) -> distanza dal bordo destro
// dist_to_top = ray->delta_y -> distanza dal bordo superiore
// dist_to_bottom = (B_HEIGHT - ray->delta_y) -> distanza dal bordo inferior
// il muro è quello con la distanza minima dal punto di impatto.
void	threed_wrld(t_mlx_data *mlx, t_ray *ray, int i)
{
	ray->delta_x = ray->ray_x - ((int)(ray->ray_x / B_HEIGHT) * B_HEIGHT);
	ray->delta_y = ray->ray_y - ((int)(ray->ray_y / B_HEIGHT) * B_HEIGHT);
	if (mlx->gen->map[(int)(ray->ray_y / B_HEIGHT)][(int)(ray->ray_x / \
	B_HEIGHT)] == 'X' && ((ray->delta_x <= (B_HEIGHT - ray->delta_x) && \
	ray->delta_x <= ray->delta_y && ray->delta_x <= (B_HEIGHT - \
	ray->delta_y)) || ((B_HEIGHT - ray->delta_x) <= ray->delta_y && \
	(B_HEIGHT - ray->delta_x) <= (B_HEIGHT - ray->delta_y))))
		put_texture(mlx, i, ray, 'P');
	else if (mlx->gen->map[(int)(ray->ray_y / B_HEIGHT)][(int)(ray->ray_x / \
	B_HEIGHT)] == 'X')
		put_texture(mlx, i, ray, 'D');
	else if (ray->delta_x <= (B_HEIGHT - ray->delta_x) && ray->delta_x <= \
	ray->delta_y && ray->delta_x <= (B_HEIGHT - ray->delta_y))
		put_texture(mlx, i, ray, 'W');
	else if ((B_HEIGHT - ray->delta_x) <= ray->delta_y && (B_HEIGHT - \
	ray->delta_x) <= (B_HEIGHT - ray->delta_y))
		put_texture(mlx, i, ray, 'E');
	else if (ray->delta_y <= (B_HEIGHT - ray->delta_y))
		put_texture(mlx, i, ray, 'N');
	else
		put_texture(mlx, i, ray, 'S');
}

void	cast_ray_mini(t_mlx_data *mlx, t_ray *ray, double mini_x, double mini_y)
{
	if (mlx->player->key_map)
	{
		while (!mini_touch(mini_x, mini_y, mlx))
		{
			my_mini_put_pixel(mini_x + (mlx->gen->mini_size / 2), mini_y + \
			(mlx->gen->mini_size / 2), 0X7c0505, mlx);
			mini_x += ray->cos_angle * (B_HEIGHT / mlx->gen->mini_size);
			mini_y += ray->sin_angle * (B_HEIGHT / mlx->gen->mini_size);
		}
	}
}

void	cast_ray(t_player *player, t_mlx_data *mlx, t_ray *ray, int i)
{
	double	height;
	double	mini_ray_x;
	double	mini_ray_y;

	ray->ray_x = (player->x_player * B_HEIGHT);
	ray->ray_y = (player->y_player * B_HEIGHT);
	mini_ray_x = (player->x_player * mlx->gen->mini_size);
	mini_ray_y = (player->y_player * mlx->gen->mini_size);
	ray->cos_angle = cos(ray->ray_angle) * get_speed(mlx);
	ray->sin_angle = sin(ray->ray_angle) * get_speed(mlx);
	cast_ray_mini(mlx, ray, mini_ray_x, mini_ray_y);
	while (!touch(ray->ray_x, ray->ray_y, mlx))
	{
		ray->ray_x += ray->cos_angle * 2;
		ray->ray_y += ray->sin_angle * 2;
	}
	ray->ray_dist = fixed_distance(player, ray->ray_x, ray->ray_y);
	height = SCREEN_Y / ray->ray_dist;
	ray->wall_start = (SCREEN_Y - height) / 2;
	ray->wall_end = ray->wall_start + height;
	threed_wrld(mlx, ray, i);
}

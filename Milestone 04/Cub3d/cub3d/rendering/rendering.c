/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 10:15:28 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/16 15:10:14 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

void	put_texture1(t_mlx_data *mlx, t_ray *ray, t_tex *texture, double tex_x)
{
	int		y;
	double	step;
	double	height;
	double	tex_pos;
	char	*pixel;

	height = ray->wall_end - ray->wall_start;
	step = 1.0 * texture->height / height;
	tex_pos = (ray->wall_start - SCREEN_Y / 2 + height / 2) * step;
	y = ray->wall_start;
	while (y < ray->wall_end)
	{
		tex_pos += step;
		pixel = texture->data + (((int)tex_pos & (texture->height - 1)) * \
		texture->size_line + (int)tex_x * (texture->bpp / 8));
		my_put_pixel(mlx->column, y, *(unsigned int *)pixel, mlx);
		y++;
	}
}

void	put_texture(t_mlx_data *mlx, t_ray *ray, char wall_direction)
{
	t_tex	*texture;
	double	tex_x;
	double	wall_x;

	texture = choose_texture(mlx, wall_direction);
	texture->data = mlx_get_data_addr(texture->texture, &texture->bpp, \
	&texture->size_line, &texture->endian);
	if (wall_direction == 'N' || wall_direction == 'S')
		wall_x = ray->ray_x / BLOCK_HEIGHT - floor(ray->ray_x / BLOCK_HEIGHT);
	else
		wall_x = ray->ray_y / BLOCK_HEIGHT - floor(ray->ray_y / BLOCK_HEIGHT);
	wall_x -= floor(wall_x);
	tex_x = wall_x * texture->width;
	if (((wall_direction == 'N' || wall_direction == 'S') && ray->ray_x > 0) || \
		((wall_direction == 'E' || wall_direction == 'W') && ray->ray_y < 0))
		tex_x = texture->width - tex_x - 1;
	put_texture1(mlx, ray, texture, tex_x);
}

// calcoliamo la distanza dal punto di impatto ai quattro i bordi del blocco:
// dist_to_left = ray->delta_x -> distanza dal bordo sinistro
// dist_to_right: distanza dal bordo destro
// dist_to_top = ray->delta_y -> distanza dal bordo superiore
// dist_to_bottom: distanza dal bordo inferiore
// il muro è quello con la distanza minima dal punto di impatto.
void	threed_wrld(t_mlx_data *mlx, t_ray *ray, int i)
{
	int		map_x;
	int		map_y;
	char	wall_direction;
	double	d_to_right;
	double	d_to_bottom;

	map_x = (int)(ray->ray_x / BLOCK_HEIGHT);
	map_y = (int)(ray->ray_y / BLOCK_HEIGHT);
	ray->delta_x = ray->ray_x - (map_x * BLOCK_HEIGHT);
	ray->delta_y = ray->ray_y - (map_y * BLOCK_HEIGHT);
	d_to_right = BLOCK_HEIGHT - ray->delta_x;
	d_to_bottom = BLOCK_HEIGHT - ray->delta_y;
	if (ray->delta_x <= d_to_right && ray->delta_x <= ray->delta_y && \
	ray->delta_x <= d_to_bottom)
		wall_direction = 'W';
	else if (d_to_right <= ray->delta_y && d_to_right <= d_to_bottom)
		wall_direction = 'E';
	else if (ray->delta_y <= d_to_bottom)
		wall_direction = 'N';
	else
		wall_direction = 'S';
	mlx->column = i;
	put_texture(mlx, ray, wall_direction);
}

void	cast_ray(t_player *player, t_mlx_data *mlx, t_ray *ray, int i)
{
	double	height;

	ray->ray_x = (player->x_player * BLOCK_HEIGHT);
	ray->ray_y = (player->y_player * BLOCK_HEIGHT);
	ray->cos_angle = cos(ray->ray_angle) * MOVE_SPEED;
	ray->sin_angle = sin(ray->ray_angle) * MOVE_SPEED;
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

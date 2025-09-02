/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:09:15 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 12:22:21 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*ft_strndup(const char *s, size_t n)
{
	size_t	len;
	size_t	i;
	char	*new_str;

	len = 0;
	i = -1;
	while (s[len] && len < n)
		len++;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		return (NULL);
	while (++i < len)
		new_str[i] = s[i];
	new_str[len] = '\0';
	return (new_str);
}

void	print_map(t_data *gen)
{
	int	i;

	i = 0;
	while (i < gen->map_height)
		printf("%s", gen->map[i++]);
	printf("\n");
}

void	init_ray_params(t_ray *ray)
{
	ray->ray_x = 0;
	ray->ray_y = 0;
	ray->ray_angle = 0;
	ray->ray_dist = 0;
	ray->wall_start = 0;
	ray->wall_end = 0;
	ray->cos_angle = 0;
	ray->sin_angle = 0;
	ray->delta_x = 0;
	ray->delta_y = 0;
}

//i 0.5f è per mettere il player al centro del cubo
void	init_player(t_player *player, t_data *gen)
{
	struct timeval	tmp;

	gettimeofday(&tmp, NULL);
	player->x_player = (float)gen->x_player + 0.5f;
	player->y_player = (float)gen->y_player + 0.5f;
	player->pov = gen->player_pov;
	gen->player = player;
	if (gen->player_pov == 'N')
		player->angle = 3 * PI / 2;
	else if (gen->player_pov == 'S')
		player->angle = PI / 2;
	else if (gen->player_pov == 'E')
		player->angle = 0;
	else if (gen->player_pov == 'W')
		player->angle = PI;
	player->key_w = false;
	player->key_s = false;
	player->key_a = false;
	player->key_d = false;
	player->key_left = false;
	player->key_right = false;
}

void	init_mlx_params(t_mlx_data *mlx)
{
	mlx->bpp = 0;
	mlx->size_line = 0;
	mlx->endian = 0;
	mlx->column = -1;
	check_rgb_values(mlx->gen);
	mlx->floor_color = hexa_converter(mlx->gen->floor);
	mlx->ceiling_color = hexa_converter(mlx->gen->ceiling);
}

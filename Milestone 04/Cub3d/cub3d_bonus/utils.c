/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:09:15 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 11:18:40 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//Inizializza gli elementi della struttura a zero
void	gen_struct_init(t_data *gen)
{
	gen->map = NULL;
	gen->file_name = NULL;
	gen->gen_ptr = NULL;
	gen->no = NULL;
	gen->so = NULL;
	gen->ea = NULL;
	gen->we = NULL;
	gen->floor = NULL;
	gen->ceiling = NULL;
	gen->door_one = NULL;
	gen->door_two = NULL;
	gen->is_door = 0;
	gen->player_pov = '\0';
	gen->map_height = 0;
	gen->map_width = 0;
	gen->mini_size = 0;
	gen->x_player = 0;
	gen->y_player = 0;
}

//Printa Error seguito dall'errore personalizzato str
void	error_print(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd("\n", 2);
	exit(1);
}

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
	player->time = tmp.tv_sec;
	player->key_w = false;
	player->key_s = false;
	player->key_a = false;
	player->key_d = false;
	player->key_left = false;
	player->key_right = false;
	player->key_map = false;
	player->key_act = false;
}

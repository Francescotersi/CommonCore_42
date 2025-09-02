/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 11:17:58 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/23 10:26:14 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(t_data *gen)
{
	int	i;

	i = 0;
	while (i < gen->map_height)
		printf("%s", gen->map[i++]);
	printf("\n");
}

void	put_texture(t_mlx_data *mlx, int column, t_ray *ray, char w_dir)
{
	t_tex	*texture;
	double	tex_x;
	double	wall_x;

	texture = choose_texture(mlx, w_dir);
	texture->data = mlx_get_data_addr(texture->texture, &texture->bpp, \
	&texture->size_line, &texture->endian);
	if (w_dir == 'N' || w_dir == 'S' || w_dir == 'D')
		wall_x = ray->ray_x / B_HEIGHT - floor(ray->ray_x / B_HEIGHT);
	else
		wall_x = ray->ray_y / B_HEIGHT - floor(ray->ray_y / B_HEIGHT);
	wall_x -= floor(wall_x);
	tex_x = wall_x * texture->width;
	if (((w_dir == 'N' || w_dir == 'S' || w_dir == 'D') && ray->ray_x > 0) || \
	((w_dir == 'E' || w_dir == 'W' || w_dir == 'P') && ray->ray_y < 0))
		tex_x = texture->width - tex_x - 1;
	mlx->column = column;
	put_texture1(mlx, ray, texture, tex_x);
}

void	check_rgb_values(t_data *gen)
{
	gen->floor = trim_direction_texture_2(gen->floor, 0, 1);
	gen->ceiling = trim_direction_texture_2(gen->ceiling, 0, 1);
	if (gen->ceiling[0] == '\0' || gen->floor[0] == '\0')
	{
		free_all(gen);
		error_print("Missing texture address");
	}
}

bool	xpm_check(char *str)
{
	int	len;

	len = ft_strlen(str);
	if (str[len - 4] != '.' || str[len - 3] != 'x' || \
		str[len - 2] != 'p' || str[len - 1] != 'm' || \
		str[len] != '\0')
		return (false);
	return (true);
}

void	destroy_all_textures_2(t_mlx_data *mlx)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		if (mlx->lancer[i].texture)
			mlx_destroy_image(mlx->mlx_ptr, mlx->lancer[i].texture);
		if (mlx->dog[i].texture)
			mlx_destroy_image(mlx->mlx_ptr, mlx->dog[i].texture);
		i++;
	}
	i = 0;
	while (i < 17)
	{
		if (mlx->explosion[i].texture)
			mlx_destroy_image(mlx->mlx_ptr, mlx->explosion[i].texture);
		i++;
	}
}

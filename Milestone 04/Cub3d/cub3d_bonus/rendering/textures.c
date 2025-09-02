/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:31 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/29 12:19:02 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_tex	texture_struct_init_2(void)
{
	t_tex	temp;

	temp.texture = NULL;
	temp.data = NULL;
	temp.width = B_HEIGHT;
	temp.height = B_HEIGHT;
	temp.bpp = 0;
	temp.size_line = 0;
	temp.endian = 0;
	return (temp);
}

void	texture_struct_init(t_mlx_data *mlx)
{
	mlx->north = texture_struct_init_2();
	mlx->south = texture_struct_init_2();
	mlx->east = texture_struct_init_2();
	mlx->west = texture_struct_init_2();
	mlx->pew_pew = texture_struct_init_2();
	if (mlx->gen->is_door == 3 && mlx->gen->door_one != NULL)
		mlx->door_one = texture_struct_init_2();
	if (mlx->gen->is_door == 3 && mlx->gen->door_two != NULL)
		mlx->door_two = texture_struct_init_2();
}

void	destroy_all_textures(t_mlx_data *mlx)
{
	if (mlx->pew_pew.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->pew_pew.texture);
	if (mlx->gen->door_one && mlx->door_one.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->door_one.texture);
	if (mlx->gen->door_two && mlx->door_two.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->door_two.texture);
	if (mlx->north.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->north.texture);
	if (mlx->south.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->south.texture);
	if (mlx->east.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->east.texture);
	if (mlx->west.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->west.texture);
	destroy_all_textures_2(mlx);
}

t_tex	*choose_texture(t_mlx_data *mlx, int wall_direction)
{
	if (wall_direction == 'N')
		return (&mlx->north);
	else if (wall_direction == 'S')
		return (&mlx->south);
	else if (wall_direction == 'E')
		return (&mlx->east);
	else if (wall_direction == 'W')
		return (&mlx->west);
	else if (wall_direction == 'D')
		return (&mlx->door_one);
	else if (wall_direction == 'P')
		return (&mlx->door_two);
	return (NULL);
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

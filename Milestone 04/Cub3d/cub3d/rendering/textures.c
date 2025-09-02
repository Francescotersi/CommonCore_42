/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:03:31 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/16 09:21:26 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_tex	texture_struct_init_2(void)
{
	t_tex	temp;

	temp.texture = NULL;
	temp.data = NULL;
	temp.width = BLOCK_HEIGHT;
	temp.height = BLOCK_HEIGHT;
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
}

void	destroy_all_textures(t_mlx_data *mlx)
{
	if (mlx->north.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->north.texture);
	if (mlx->south.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->south.texture);
	if (mlx->east.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->east.texture);
	if (mlx->west.texture)
		mlx_destroy_image(mlx->mlx_ptr, mlx->west.texture);
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
	return (NULL);
}

// inizializza le immagini
void	texture_init(t_mlx_data *mlx)
{
	mlx->north.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->no, \
		&mlx->north.width, &mlx->north.height);
	mlx->south.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->so, \
		&mlx->south.width, &mlx->south.height);
	mlx->east.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->ea, \
		&mlx->east.width, &mlx->east.height);
	mlx->west.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->we, \
		&mlx->west.width, &mlx->west.height);
	if (!mlx->north.texture || !mlx->south.texture || \
		!mlx->east.texture || !mlx->west.texture)
	{
		destroy_all_textures(mlx);
		free_all(mlx->gen);
		free_display(mlx);
		error_print("Error loading textures");
	}
}

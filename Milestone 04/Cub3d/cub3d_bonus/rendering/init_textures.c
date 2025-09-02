/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 10:36:42 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 10:51:51 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	texture_init_5(t_mlx_data *mlx)
{
	mlx->explosion[12].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_13.xpm", &mlx->explosion[12].width, \
	&mlx->explosion[12].height);
	mlx->explosion[13].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_14.xpm", &mlx->explosion[13].width, \
	&mlx->explosion[13].height);
	mlx->explosion[14].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_15.xpm", &mlx->explosion[14].width, \
	&mlx->explosion[14].height);
	mlx->explosion[15].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_16.xpm", &mlx->explosion[15].width, \
	&mlx->explosion[15].height);
	mlx->explosion[16].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_17.xpm", &mlx->explosion[16].width, \
	&mlx->explosion[16].height);
}

void	texture_init_4(t_mlx_data *mlx)
{
	mlx->explosion[4].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_5.xpm", &mlx->explosion[4].width, \
	&mlx->explosion[4].height);
	mlx->explosion[5].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_6.xpm", &mlx->explosion[5].width, \
	&mlx->explosion[5].height);
	mlx->explosion[6].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_7.xpm", &mlx->explosion[6].width, \
	&mlx->explosion[6].height);
	mlx->explosion[7].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_8.xpm", &mlx->explosion[7].width, \
	&mlx->explosion[7].height);
	mlx->explosion[8].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_9.xpm", &mlx->explosion[8].width, \
	&mlx->explosion[8].height);
	mlx->explosion[9].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_10.xpm", &mlx->explosion[9].width, \
	&mlx->explosion[9].height);
	mlx->explosion[10].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_11.xpm", &mlx->explosion[10].width, \
	&mlx->explosion[10].height);
	mlx->explosion[11].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_12.xpm", &mlx->explosion[11].width, \
	&mlx->explosion[11].height);
	texture_init_5(mlx);
}

void	texture_init_3(t_mlx_data *mlx)
{
	mlx->dog[1].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/god/dog_2.xpm", &mlx->dog[1].width, &mlx->dog[1].height);
	mlx->dog[2].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/god/dog_dance_1.xpm", &mlx->dog[2].width, &mlx->dog[2].height);
	mlx->dog[3].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/god/dog_dance_2.xpm", &mlx->dog[3].width, &mlx->dog[3].height);
	mlx->dog[4].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/god/dog_dance_3.xpm", &mlx->dog[4].width, &mlx->dog[4].height);
	mlx->dog[5].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/god/dog_dance_4.xpm", &mlx->dog[5].width, &mlx->dog[5].height);
	mlx->explosion[0].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_1.xpm", &mlx->explosion[0].width, \
	&mlx->explosion[0].height);
	mlx->explosion[1].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_2.xpm", &mlx->explosion[1].width, \
	&mlx->explosion[1].height);
	mlx->explosion[2].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_3.xpm", &mlx->explosion[2].width, \
	&mlx->explosion[2].height);
	mlx->explosion[3].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/explosion/explosion_4.xpm", &mlx->explosion[3].width, \
	&mlx->explosion[3].height);
	texture_init_4(mlx);
}

void	texture_init_2(t_mlx_data *mlx)
{
	if (mlx->gen->is_door == 3 && mlx->gen->door_two != NULL)
		mlx->door_two.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->gen->door_two, &mlx->door_two.width, &mlx->door_two.height);
	mlx->lancer[0].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/lancer/lancer_1.xpm", &mlx->lancer[0].width, \
	&mlx->lancer[0].height);
	mlx->lancer[1].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/lancer/lancer_2.xpm", &mlx->lancer[1].width, \
	&mlx->lancer[1].height);
	mlx->lancer[2].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/lancer/lancer_3.xpm", &mlx->lancer[2].width, \
	&mlx->lancer[2].height);
	mlx->lancer[3].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/lancer/lancer_4.xpm", &mlx->lancer[3].width, \
	&mlx->lancer[3].height);
	mlx->lancer[4].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/lancer/lancer_5.xpm", &mlx->lancer[4].width, \
	&mlx->lancer[4].height);
	mlx->lancer[5].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/lancer/lancer_6.xpm", &mlx->lancer[5].width, \
	&mlx->lancer[5].height);
	mlx->dog[0].texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/god/dog_1.xpm", &mlx->dog[0].width, &mlx->dog[0].height);
	texture_init_3(mlx);
}

// inizializza le immagini
void	texture_init(t_mlx_data *mlx)
{
	mlx->pew_pew.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
	"./sprites/real_gun_hand.xpm", &mlx->pew_pew.width, &mlx->pew_pew.height);
	mlx->north.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->no, \
	&mlx->north.width, &mlx->north.height);
	mlx->south.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->so, \
	&mlx->south.width, &mlx->south.height);
	mlx->east.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->ea, \
	&mlx->east.width, &mlx->east.height);
	mlx->west.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, mlx->gen->we, \
	&mlx->west.width, &mlx->west.height);
	if (mlx->gen->is_door == 3 && mlx->gen->door_one != NULL)
		mlx->door_one.texture = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		mlx->gen->door_one, &mlx->door_one.width, &mlx->door_one.height);
	texture_init_2(mlx);
	if (!mlx->north.texture || !mlx->south.texture || !mlx->east.texture || \
	!mlx->west.texture || (mlx->gen->is_door == 3 && (!mlx->door_one.texture || \
	!mlx->door_two.texture)))
	{
		destroy_all_textures(mlx);
		free_all(mlx->gen);
		free_display(mlx);
		error_print("Error loading textures");
	}
}

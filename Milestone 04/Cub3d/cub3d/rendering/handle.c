/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 16:56:06 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/10 16:56:27 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_mouse_input(t_mlx_data *mlx)
{
	destroy_all_textures(mlx);
	free_display(mlx);
	free_all(mlx->gen);
	exit(0);
	return (0);
}

int	handle_release(int keysym, t_mlx_data *mlx)
{
	if (keysym == KB_W)
		mlx->player->key_w = false;
	else if (keysym == KB_S)
		mlx->player->key_s = false;
	else if (keysym == KB_A)
		mlx->player->key_a = false;
	else if (keysym == KB_D)
		mlx->player->key_d = false;
	else if (keysym == KB_LEFT)
		mlx->player->key_left = false;
	else if (keysym == KB_RIGHT)
		mlx->player->key_right = false;
	return (0);
}

int	handle_input(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_Escape)
		handle_mouse_input(mlx);
	if (keysym == KB_W)
		mlx->player->key_w = true;
	if (keysym == KB_A)
		mlx->player->key_a = true;
	if (keysym == KB_S)
		mlx->player->key_s = true;
	if (keysym == KB_D)
		mlx->player->key_d = true;
	if (keysym == KB_LEFT)
		mlx->player->key_left = true;
	if (keysym == KB_RIGHT)
		mlx->player->key_right = true;
	return (0);
}

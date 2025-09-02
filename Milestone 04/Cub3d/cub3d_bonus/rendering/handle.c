/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 08:46:59 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 09:28:57 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	handle_mouse_input(t_mlx_data *mlx)
{
	stop_audio(mlx);
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
	if (keysym == KB_MAP)
		mlx->player->key_map = false;
	if (keysym == KB_ACT)
		mlx->player->key_act = false;
	return (0);
}

int	handle_items(int keysym, t_mlx_data *mlx)
{
	if (keysym == XK_1)
		return (play_audio("sprites/audios/Lancer.wav", mlx), mlx->item_one = \
		true, mlx->item_two = false, mlx->item_three = false, 0);
	else if (keysym == XK_2)
		return (play_audio("sprites/audios/Dogsong.wav", mlx), mlx->item_one = \
		false, mlx->item_two = true, mlx->item_three = false, 0);
	else if (keysym == XK_3)
		return (play_audio("sprites/audios/explosion.wav", mlx), \
		mlx->item_one = false, mlx->item_two = false, mlx->item_three = true, \
		0);
	else if (keysym == XK_4)
		return (play_audio("sprites/audios/WELCOME_TO_THE_CITY.wav", mlx), \
		mlx->item_one = false, mlx->item_two = false, mlx->item_three = false, \
		0);
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
	if (keysym == KB_MAP)
		mlx->player->key_map = true;
	if (keysym == KB_ACT)
		mlx->player->key_act = true;
	return (handle_items(keysym, mlx));
}

char	*ft_replace(char *str, char c, char sub, double x)
{
	int		i;
	char	*new;
	int		nx;

	nx = (int)x;
	new = (char *)malloc(ft_strlen(str) * sizeof(char) + 1);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && nx == i)
			new[i++] = sub;
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	free(str);
	return (new);
}

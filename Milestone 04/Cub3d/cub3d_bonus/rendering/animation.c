/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 07:53:39 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 08:41:25 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_tex	explosion_animation_loop(t_mlx_data *mlx)
{
	t_tex		current_frame;
	static int	clock = 0;
	static int	past = 0;
	static int	i = 0;

	clock++;
	if (clock < past + 2 && clock != 34 && i < 17)
		current_frame = get_info(mlx->explosion[i]);
	if (clock == 34)
	{
		clock = 0;
		past = 0;
		i = 0;
		handle_mouse_input(mlx);
	}
	else if (clock == past + 2 && i < 17)
	{
		i++;
		past = clock;
		current_frame = get_info(mlx->explosion[i]);
	}
	return (current_frame);
}

t_tex	annoying_dog_loop_animation(t_mlx_data *mlx)
{
	t_tex		current_frame;
	static int	clock = 0;

	clock++;
	if (mlx->player->key_w || mlx->player->key_a \
	|| mlx->player->key_s || mlx->player->key_d)
	{
		if (clock >= 8)
			clock = 0;
		if (clock <= 4)
			current_frame = get_info(mlx->dog[1]);
		else
			current_frame = get_info(mlx->dog[0]);
	}
	else
	{
		if (clock >= 12)
			clock = 0;
		current_frame = annoying_dog_maracas(mlx, clock);
	}
	return (current_frame);
}

t_tex	lancer_animation_loop(t_mlx_data *mlx)
{
	t_tex		current_frame;
	static int	clock = 0;

	clock++;
	if (clock >= 20 && clock <= 24)
		current_frame = get_info(mlx->lancer[5]);
	else if (clock >= 16 && clock < 20)
		current_frame = get_info(mlx->lancer[4]);
	else if (clock >= 12 && clock < 16)
		current_frame = get_info(mlx->lancer[3]);
	else if (clock >= 8 && clock < 12)
		current_frame = get_info(mlx->lancer[2]);
	else if (clock >= 4 && clock < 8)
		current_frame = get_info(mlx->lancer[1]);
	else
		current_frame = get_info(mlx->lancer[0]);
	if (clock == 24)
		clock = 0;
	return (current_frame);
}

void	draw_pew_pew_2(t_mlx_data *mlx, int start_x, int start_y, int y)
{
	int		tex_x;
	int		tex_y;
	char	*pixel;
	int		color;
	int		x;

	x = 0;
	while (x < mlx->pew_pew.width)
	{
		tex_x = x;
		tex_y = y;
		pixel = mlx->pew_pew.data + \
		(tex_y * mlx->pew_pew.size_line + tex_x * (mlx->pew_pew.bpp / 8));
		color = *(unsigned int *)pixel;
		if (color != 0xFF00FF && color != 0x00000000)
			my_put_pixel(start_x + x, start_y + y, color, mlx);
		x++;
	}
}

void	draw_animation(t_mlx_data *mlx, int start[2], t_tex cur_frame, int y)
{
	int		tex_x;
	int		tex_y;
	char	*pixel;
	int		color;
	int		x;

	x = 0;
	while (x < cur_frame.width)
	{
		tex_x = x;
		tex_y = y;
		pixel = cur_frame.data + \
		(tex_y * cur_frame.size_line + tex_x * (cur_frame.bpp / 8));
		color = *(unsigned int *)pixel;
		if (color != 0xFF00FF && color != 0x00000000)
			my_put_pixel(start[0] + x, start[1] + y, color, mlx);
		x++;
	}
}

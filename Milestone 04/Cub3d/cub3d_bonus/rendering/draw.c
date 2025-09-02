/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/11 07:49:09 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 07:53:22 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_pew_pew(t_mlx_data *mlx)
{
	int		y;
	int		start_x;
	int		start_y;

	mlx->pew_pew.data = mlx_get_data_addr(mlx->pew_pew.texture, \
		&mlx->pew_pew.bpp, &mlx->pew_pew.size_line, &mlx->pew_pew.endian);
	start_x = SCREEN_X - mlx->pew_pew.width - 334;
	start_y = SCREEN_Y - mlx->pew_pew.height - 50;
	y = 0;
	while (y < mlx->pew_pew.height)
	{
		draw_pew_pew_2(mlx, start_x, start_y, y);
		y++;
	}
}

void	draw_explosion(t_mlx_data *mlx)
{
	int			y;
	int			start[2];
	t_tex		current_frame;

	current_frame = explosion_animation_loop(mlx);
	start[0] = (SCREEN_X / 2) - (current_frame.width / 2);
	start[1] = SCREEN_Y - current_frame.height - 0;
	y = 0;
	while (y < current_frame.height)
	{
		draw_animation(mlx, start, current_frame, y);
		y++;
	}
}

void	draw_lancer(t_mlx_data *mlx)
{
	int			y;
	int			start[2];
	t_tex		current_frame;

	current_frame = lancer_animation_loop(mlx);
	start[0] = SCREEN_X - current_frame.width - 334;
	start[1] = SCREEN_Y - current_frame.height - 87;
	y = 0;
	while (y < current_frame.height)
	{
		draw_animation(mlx, start, current_frame, y);
		y++;
	}
}

void	draw_annoying_dog(t_mlx_data *mlx)
{
	int		y;
	int		start[2];	
	t_tex	current_frame;

	current_frame = annoying_dog_loop_animation(mlx);
	start[0] = SCREEN_X - current_frame.width - 334;
	start[1] = SCREEN_Y - current_frame.height - 85;
	y = 0;
	while (y < current_frame.height)
	{
		draw_animation(mlx, start, current_frame, y);
		y++;
	}
}

void	draw_item_chosen(t_mlx_data *mlx)
{
	if (mlx->item_one == true)
		draw_lancer(mlx);
	else if (mlx->item_two == true)
		draw_annoying_dog(mlx);
	else
		draw_pew_pew(mlx);
	if (mlx->item_three == true)
		draw_explosion(mlx);
}

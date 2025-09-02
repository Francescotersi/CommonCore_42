/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_mini.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 15:45:02 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 10:09:16 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_frame(t_mlx_data *mlx, int color)
{
	int	i;
	int	half;
	int	size;
	int	map_width_pixels;
	int	map_height_pixels;

	i = -1;
	size = mlx->gen->mini_size;
	half = size / 2;
	map_width_pixels = mlx->gen->map_width * size + half;
	map_height_pixels = mlx->gen->map_height * size + half;
	while (++i < map_width_pixels / half)
		draw_square(mlx, i * half, 0, color);
	i = -1;
	while (++i < map_width_pixels / half)
		draw_square(mlx, i * half, map_height_pixels, color);
	i = -1;
	while (++i < (map_height_pixels + half) / half)
		draw_square(mlx, 0, i * half, color);
	i = -1;
	while (++i < (map_height_pixels + half) / half)
		draw_square(mlx, map_width_pixels, i * half, color);
}

void	alloc_heart(char *heart_pattern[15])
{
	heart_pattern[0] = "001110000011100";
	heart_pattern[1] = "011111000111110";
	heart_pattern[2] = "111111101111111";
	heart_pattern[3] = "111111101111111";
	heart_pattern[4] = "111111111111111";
	heart_pattern[5] = "111111111111111";
	heart_pattern[6] = "111111111111111";
	heart_pattern[7] = "111111111111111";
	heart_pattern[8] = "111111111111111";
	heart_pattern[9] = "001111111111100";
	heart_pattern[10] = "001111111111100";
	heart_pattern[11] = "000011111110000";
	heart_pattern[12] = "000011111110000";
	heart_pattern[13] = "000000111000000";
	heart_pattern[14] = "000000111000000";
}

void	draw_heart(t_mlx_data *mlx, int x, int y, int color)
{
	int		i;
	int		j;
	char	*heart_pattern[15];

	alloc_heart(heart_pattern);
	i = -1;
	if (mlx->gen->player->key_map)
	{
		while (++i < 15)
		{
			j = -1;
			while (++j < 15)
				if (heart_pattern[i][j] == '1')
					my_mini_put_pixel(x + j, y + i, color, mlx);
		}
	}
}

void	my_mini_put_pixel(int x, int y, int color, t_mlx_data *mlx)
{
	int	index;

	if (y < 0 || y >= SCREEN_Y || x < 0 || x >= SCREEN_X)
		return ;
	index = y * mlx->mini_size_line + x * mlx->mini_bpp / 8;
	mlx->mini_data[index] = color & 0xFF;
	mlx->mini_data[index + 1] = (color >> 8) & 0xFF;
	mlx->mini_data[index + 2] = (color >> 16) & 0xFF;
}

bool	mini_touch(float px, float py, t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = px / mlx->gen->mini_size;
	y = py / mlx->gen->mini_size;
	if (mlx->gen->map[y][x] == '1' || mlx->gen->map[y][x] == 'X')
		return (true);
	return (false);
}

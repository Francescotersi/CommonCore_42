/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 16:15:53 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/11 10:18:03 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// i valori che vengoo dati a mlx->data sono i pixel che vanno a comporre
//  l'immagine e sono messi in colori RGB
// data = R
// data + 1 = G
// data + 2 = B
void	my_put_pixel(int x, int y, int color, t_mlx_data *mlx)
{
	int	index;

	if (y < 0 || y >= SCREEN_Y || x < 0 || x >= SCREEN_X)
		return ;
	index = y * mlx->size_line + x * mlx->bpp / 8;
	mlx->data[index] = color & 0xFF;
	mlx->data[index + 1] = (color >> 8) & 0xFF;
	mlx->data[index + 2] = (color >> 16) & 0xFF;
}

// Converte valori RGB (0-255) al valore int del colore
int	rgb_to_int(int red, int green, int blue)
{
	return (((red & 0xFF) << 16) | ((green & 0xFF) << 8) | (blue & 0xFF));
}

int	hexa_converter(char *str)
{
	int	rgb[3];
	int	i;
	int	count;
	int	num;

	i = 0;
	count = 0;
	num = 0;
	while (str[i] && count < 3)
	{
		if (ft_isdigit(str[i]))
			num = num * 10 + (str[i] - '0');
		else if (str[i] == ',' || str[i] == '\0' || str[i] == '\n')
		{
			rgb[count] = num;
			count++;
			num = 0;
		}
		i++;
	}
	if (count < 3)
		rgb[count] = num;
	return (rgb_to_int(rgb[0], rgb[1], rgb[2]));
}

double	fixed_distance(t_player *player, double x, double y)
{
	double	delta_x;
	double	delta_y;
	float	angle;

	delta_x = (x / B_HEIGHT) - player->x_player;
	delta_y = (y / B_HEIGHT) - player->y_player;
	angle = atan2(delta_y, delta_x) - player->angle;
	return (sqrt(pow(delta_x, 2) + pow(delta_y, 2)) * cos(angle));
}

bool	touch(float px, float py, t_mlx_data *mlx)
{
	int	x;
	int	y;

	x = px / B_HEIGHT;
	y = py / B_HEIGHT;
	if (mlx->gen->map[y][x] == '1' || mlx->gen->map[y][x] == 'X')
		return (true);
	return (false);
}

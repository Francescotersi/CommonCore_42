/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   items.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 08:18:11 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/11 10:33:43 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_tex	get_info(t_tex tex)
{
	t_tex	current_frame;

	current_frame.data = mlx_get_data_addr(tex.texture, \
		&current_frame.bpp, &current_frame.size_line, &current_frame.endian);
	current_frame.width = tex.width;
	current_frame.height = tex.height;
	return (current_frame);
}

void	stop_audio(t_mlx_data *mlx)
{
	if (mlx->audio_playing && mlx->audio_pid > 0)
	{
		kill(mlx->audio_pid, SIGTERM);
		mlx->audio_pid = 0;
		mlx->audio_playing = false;
	}
}

void	play_audio(char *filename, t_mlx_data *mlx)
{
	FILE	*fp;
	char	command[256];

	stop_audio(mlx);
	snprintf(command, sizeof(command), "paplay %s > /dev/null 2>&1 & echo $!", \
	filename);
	fp = popen(command, "r");
	if (fp)
	{
		fscanf(fp, "%d", &mlx->audio_pid);
		pclose(fp);
		mlx->audio_playing = true;
	}
}

t_tex	annoying_dog_maracas(t_mlx_data *mlx, int clock)
{
	if (clock <= 3)
		return (get_info(mlx->dog[2]));
	else if (clock > 3 && clock <= 6)
		return (get_info(mlx->dog[3]));
	else if (clock > 6 && clock <= 9)
		return (get_info(mlx->dog[4]));
	else
		return (get_info(mlx->dog[5]));
}

void	draw_square(t_mlx_data *mlx, int x, int y, int color)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	if (color == 0X00C000)
		size = mlx->gen->mini_size / 2;
	else
		size = mlx->gen->mini_size;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			my_mini_put_pixel(x + i, y + j, color, mlx);
	}
}

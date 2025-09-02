/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersll <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:38:11 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/02 16:10:22 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_frames(t_mlx_data *mlx, t_player *player)
{
	struct timeval	tmp;
	char			str[20];
	long long		present;
	static int		count = 0;
	static int		remember = 0;

	gettimeofday(&tmp, NULL);
	present = tmp.tv_sec;
	if (player->time < present)
	{
		remember = count;
		count = 0;
		player->time = present;
	}
	else
		count += 1;
	sprintf(str, "FPS: %d", remember);
	if ((mlx->gen->map[0][0] == '1' && mlx->gen->map[0][1] == '1' && \
	mlx->gen->map[0][2] == '1') || !player->key_map)
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 11, 20, 0x000000, str);
	else
		mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 11, 20, 0XFFFFFF, str);
}

int	move_mouse(int x, int y, t_mlx_data *mlx)
{
	double	change;

	change = (ROTATION_SPEED / 2) * ((abs(x - SCREEN_X / 2) / 800) + 1);
	if (x < 960)
		mlx->gen->player->angle -= change;
	if (x > 960)
		mlx->gen->player->angle += change;
	if (mlx->gen->player->angle > 2 * PI)
		mlx->gen->player->angle = 0;
	if (mlx->gen->player->angle < 0)
		mlx->gen->player->angle = 2 * PI;
	if (x != 940 || y != 540)
		mlx_mouse_move(mlx->mlx_ptr, mlx->win_ptr, 960, 540);
	return (1);
}

//fraction -> di quanto si deve spostare start_angle ad ogni iterazione, 
//diminuisci il 3 = FOV+
//start_angle -> posizione iniziale da cui iniziare a disegnare i raggi
int	draw_loop(t_mlx_data *mlx)
{
	t_ray		ray;
	double		start_angle;
	int			i;

	start_angle = mlx->player->angle - ((PI / FOV) / 2);
	i = -1;
	init_ray_params(&ray);
	move_player(mlx->player, mlx->gen, mlx);
	clear_image(mlx);
	draw_map(mlx, mlx->gen, mlx->gen->mini_size);
	while (++i < SCREEN_X)
	{
		ray.ray_angle = start_angle + i * ((PI / FOV) / SCREEN_X);
		cast_ray(mlx->player, mlx, &ray, i);
	}
	draw_heart(mlx, (mlx->player->x_player - 0.4f) * mlx->gen->mini_size + \
	(mlx->gen->mini_size / 2), (mlx->player->y_player - 0.4f) * \
	mlx->gen->mini_size + (mlx->gen->mini_size / 2), 0xFF0000);
	draw_item_chosen(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	if (mlx->gen->player->key_map)
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->mini_img, \
		0, 0);
	return (print_frames(mlx, mlx->player), 0);
}

void	cubed(t_mlx_data mlx)
{
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_X, SCREEN_Y, "DeltaDoom");
	mlx_mouse_move(mlx.mlx_ptr, mlx.win_ptr, 960, 540);
	mlx.mini_img = mlx_new_image(mlx.mlx_ptr, mlx.gen->mini_size * \
	mlx.gen->map_width + mlx.gen->mini_size, mlx.gen->mini_size * \
	mlx.gen->map_height + mlx.gen->mini_size);
	mlx.img = mlx_new_image(mlx.mlx_ptr, SCREEN_X, SCREEN_Y);
	texture_init(&mlx);
	play_audio("sprites/audios/WELCOME_TO_THE_CITY.wav", &mlx);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, \
	&mlx.endian);
	mlx.mini_data = mlx_get_data_addr(mlx.mini_img, &mlx.mini_bpp, \
	&mlx.mini_size_line, &mlx.mini_endian);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.mini_img, 0, 0);
	mlx_hook(mlx.win_ptr, 06, 1L << 6, move_mouse, &mlx);
	mlx_hook(mlx.win_ptr, 02, 1L << 0, handle_input, &mlx);
	mlx_hook(mlx.win_ptr, 03, 1L << 1, handle_release, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 3, handle_mouse_input, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, draw_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

int	main(int argc, char *argv[])
{
	t_data		gen;
	t_mlx_data	mlx;
	t_player	player;

	gen_struct_init(&gen);
	parsing(argc, argv, &gen);
	mlx.gen = &gen;
	texture_struct_init(&mlx);
	mlx.player = &player;
	gen.mlx = &mlx;
	init_player(&player, &gen);
	init_mlx_params(&mlx);
	cubed(mlx);
	destroy_all_textures(&mlx);
	free_all(&gen);
	return (0);
}

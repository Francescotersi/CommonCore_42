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

void	check_rgb_values(t_data *gen)
{
	gen->floor = trim_direction_texture_2(gen->floor, 0, 1);
	gen->ceiling = trim_direction_texture_2(gen->ceiling, 0, 1);
	if (gen->ceiling[0] == '\0' || gen->floor[0] == '\0' || \
		!gen->ceiling || !gen->floor)
	{
		free_all(gen);
		error_print("Missing texture address");
	}
}

//fraction -> di quanto si deve spostare start_angle ad ogni iterazione, 
//diminuisci il 3 = FOV+
//start angle -> posizione iniziale da cui iniziare a disegnare i raggi
int	draw_loop(t_mlx_data *mlx)
{
	t_ray		ray;
	double		fov;
	double		fraction;
	double		start_angle;
	int			i;

	fov = PI / FOV;
	fraction = fov / SCREEN_X;
	start_angle = mlx->player->angle - (fov / 2);
	i = 0;
	init_ray_params(&ray);
	move_player(mlx->player, mlx->gen);
	clear_image(mlx);
	while (i < SCREEN_X)
	{
		ray.ray_angle = start_angle + i * fraction;
		cast_ray(mlx->player, mlx, &ray, i);
		i++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img, 0, 0);
	return (0);
}

void	cubed(t_mlx_data mlx)
{
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, SCREEN_X, SCREEN_Y, "DeltaDoom");
	mlx_mouse_move(mlx.mlx_ptr, mlx.win_ptr, 960, 540);
	mlx.img = mlx_new_image(mlx.mlx_ptr, SCREEN_X, SCREEN_Y);
	texture_init(&mlx);
	mlx.data = mlx_get_data_addr(mlx.img, &mlx.bpp, &mlx.size_line, \
	&mlx.endian);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
	mlx_hook(mlx.win_ptr, 02, 1L << 0, handle_input, &mlx);
	mlx_hook(mlx.win_ptr, 03, 1L << 1, handle_release, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 3, handle_mouse_input, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, draw_loop, &mlx);
	mlx_loop(mlx.mlx_ptr);
}

//Inizializza gli elementi della struttura a zero
void	gen_struct_init(t_data *gen)
{
	gen->map = NULL;
	gen->file_name = NULL;
	gen->gen_ptr = NULL;
	gen->no = NULL;
	gen->so = NULL;
	gen->ea = NULL;
	gen->we = NULL;
	gen->floor = NULL;
	gen->ceiling = NULL;
	gen->player_pov = '\0';
	gen->map_height = 0;
	gen->map_width = 0;
	gen->x_player = 0;
	gen->y_player = 0;
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

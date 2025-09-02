/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftersill <ftersill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:38:42 by ftersill          #+#    #+#             */
/*   Updated: 2025/07/23 10:18:43 by ftersill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "Ssj_libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <sys/time.h>
# include <string.h>
# include <math.h>
# include <stdbool.h>

# define BLOCK_HEIGHT 64
# define FOV 3.5f
# define ROTATION_SPEED 0.042f
# define MOVE_SPEED 0.15f

# define SCREEN_X 1920
# define SCREEN_Y 1080
# define PI 3.14159
# define P2 1.570795
# define P3 4.712385
# define KB_W 119
# define KB_S 115
# define KB_A 97
# define KB_D 100
# define KB_ESC 65307
# define KB_UP 65362
# define KB_DOWN 65364
# define KB_LEFT 65361
# define KB_RIGHT 65363

typedef struct s_ray
{
	double		ray_x;
	double		ray_y;
	double		ray_angle;
	double		ray_dist;
	double		sin_angle;
	double		cos_angle;
	double		delta_x;
	double		delta_y;
	int			wall_start;
	int			wall_end;
}	t_ray;

typedef struct s_mlx_data	t_mlx_data;
typedef struct s_player		t_player;

typedef struct s_tex
{
	void	*texture;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_tex;

typedef struct s_data
{
	char		**map;
	char		*file_name;
	char		*gen_ptr;
	char		*no;
	char		*so;
	char		*ea;
	char		*we;
	char		*floor;
	char		*ceiling;
	char		player_pov;
	int			map_width;
	int			map_height;
	int			x_player;
	int			y_player;
	t_player	*player;
	t_mlx_data	*mlx;
}	t_data;

typedef struct s_mlx_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;

	char		*data;
	int			bpp;
	int			size_line;
	int			endian;

	int			column;
	int			floor_color;
	int			ceiling_color;
	t_tex		north;
	t_tex		south;
	t_tex		east;
	t_tex		west;
	t_player	*player;
	t_data		*gen;
}	t_mlx_data;

struct s_player
{
	double	x_player;
	double	y_player;
	double	angle;
	char	pov;

	bool	key_w;
	bool	key_s;
	bool	key_a;
	bool	key_d;
	bool	key_left;
	bool	key_right;
} ;

//----------------------------------------------------------------------------
//in parsing/map_check.c (ft 5/5) ✓

int		fill_struct(t_data *gen, int i, int size);
void	check_map(char *str, int fd, t_data *gen);

//----------------------------------------------------------------------------
//in parsing/map_pars.c (ft 4/5)

void	map_pars(t_data *gen);
bool	xpm_check(char *str);

//----------------------------------------------------------------------------
//in parsing/pars_utils.c (ft 2/5)

int		mem_full(int mem[6]);
int		count_collums(int fd, char *str);

//----------------------------------------------------------------------------
//in parsing/parsing.c (ft 5/5) ✓

char	*trim_direction_texture_2(char *str, int i, int which);
void	parsing(int argc, char *argv[], t_data *gen);

// ----------------------------------------------------------------------------
//in parsing/rgb_parsing.c (ft 3/5)

void	check_rgb(t_data *gen);

//----------------------------------------------------------------------------
//in rendering/handle.c (ft 3/5)

int		handle_mouse_input(t_mlx_data *mlx);
int		handle_release(int keysym, t_mlx_data *mlx);
int		handle_input(int keysym, t_mlx_data *mlx);

//----------------------------------------------------------------------------
//in rendering/inputs.c (ft 4/5)

void	move_player(t_player *player, t_data *gen);

//----------------------------------------------------------------------------
//in rendering/render_utils.c (ft 5/5) ✓

void	my_put_pixel(int x, int y, int color, t_mlx_data *mlx);
int		hexa_converter(char *str);
double	fixed_distance(t_player *player, double x, double y);
bool	touch(float px, float py, t_mlx_data *mlx);

//----------------------------------------------------------------------------
//in rendering/rendering.c (ft 5/5) ✓

void	clear_image(t_mlx_data *mlx);
void	cast_ray(t_player *player, t_mlx_data *mlx, t_ray *ray, int i);

//----------------------------------------------------------------------------
//in rendering/textures.c (ft 5/5) ✓

void	texture_struct_init(t_mlx_data *mlx);
void	destroy_all_textures(t_mlx_data *mlx);
t_tex	*choose_texture(t_mlx_data *mlx, int wall_direction);
void	texture_init(t_mlx_data *mlx);

//----------------------------------------------------------------------------
//in main.c (ft 5/5) ✓

void	check_rgb_values(t_data *gen);

//----------------------------------------------------------------------------
//in utils.c (ft 5/5) ✓

char	*ft_strndup(const char *s, size_t n);
void	print_map(t_data *gen);
void	init_ray_params(t_ray *ray);
void	init_player(t_player *player, t_data *gen);
void	init_mlx_params(t_mlx_data *mlx);

//----------------------------------------------------------------------------
//in utils2.c (ft 5/5) ✓

void	free_elements(t_data *gen);
void	free_all(t_data *gen);
void	free_map(t_data *gen);
void	free_display(t_mlx_data *mlx);
void	error_print(char *str);

//----------------------------------------------------------------------------

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 10:11:12 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/30 16:13:47 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//Segnala se trova uno degli elementi nel file
static int	info_checker(char *str, int mem[6], t_data *gen, size_t i)
{
	while (str[i] > 6 && str[i] < 33)
		i++;
	if (str[0] == '\n' || str[i] == '\n')
		return (1);
	if (str[0] == '1' || (str[1] == '1' && str[0] != 'D') || str[i] == '1' || \
	(i <= (ft_strlen(str) - 1) && str[i + 1] == '1' && str[i] != 'D' ) || \
	str[ft_strlen(str) - 2] == '1')
		return (2);
	if (ft_strncmp(str + i, "NO", 2) == 0)
		return (mem[0]++, 1);
	else if (ft_strncmp(str + i, "SO", 2) == 0)
		return (mem[1]++, 1);
	else if (ft_strncmp(str + i, "WE", 2) == 0)
		return (mem[2]++, 1);
	else if (ft_strncmp(str + i, "EA", 2) == 0)
		return (mem[3]++, 1);
	else if (ft_strncmp(str + i, "F", 1) == 0)
		return (mem[4]++, 1);
	else if (ft_strncmp(str + i, "C", 1) == 0)
		return (mem[5]++, 1);
	else if (ft_strncmp(str + i, "D1", 2) == 0)
		return (gen->is_door += 1, 1);
	else if (ft_strncmp(str + i, "D2", 2) == 0)
		return (gen->is_door += 2, 1);
	return (0);
}

// Controlla che ci siano tutti gli elementi nel file .cub
static void	read_file(int fd, t_data *gen)
{
	int		i;
	int		mem[6];
	char	*str;

	i = 0;
	while (i < 6)
		mem[i++] = 0;
	str = get_next_line_bonus(fd);
	while (str != NULL)
	{
		if (info_checker(str, mem, gen, 0) == 2)
			break ;
		if (mem_full(mem) == 1)
			break ;
		free(str);
		str = get_next_line_bonus(fd);
	}
	if (mem_full(mem) == 0 || (gen->is_door > 0 && gen->is_door < 3) || \
	gen->is_door > 3)
	{
		free(str);
		close(fd);
		error_print("Missing or double element in .cub file");
	}
	check_map(str, fd, gen);
}

char	*trim_direction_texture_2(char *str, int i, int which)
{
	char	*tmp;

	tmp = ft_strdup(str);
	free(str);
	while (tmp[i] && (tmp[i] == ' ' || \
		(tmp[i] >= 7 && tmp[i] <= 13)))
		i++;
	i += which;
	while (tmp[i] && (tmp[i] == ' ' || \
		(tmp[i] >= 7 && tmp[i] <= 13)))
		i++;
	str = ft_strdup(tmp + i);
	free(tmp);
	return (str);
}

void	trim_direction_texture(t_data *gen)
{
	gen->no = trim_direction_texture_2(gen->no, 0, 2);
	gen->so = trim_direction_texture_2(gen->so, 0, 2);
	gen->ea = trim_direction_texture_2(gen->ea, 0, 2);
	gen->we = trim_direction_texture_2(gen->we, 0, 2);
	if (gen->is_door == 3 && gen->door_one != NULL)
		gen->door_one = trim_direction_texture_2(gen->door_one, 0, 2);
	if (gen->is_door == 3 && gen->door_two != NULL)
		gen->door_two = trim_direction_texture_2(gen->door_two, 0, 2);
	if (gen->no[0] == '\0' || gen->so[0] == '\0' || gen->ea[0] == '\0' || \
	gen->we[0] == '\0' || (gen->is_door == 3 && (gen->door_one[0] == '\0' || \
	gen->door_two[0] == '\0')))
	{
		free_all(gen);
		error_print("Missing texture address");
	}
	if (!xpm_check(gen->no) || !xpm_check(gen->so) || !xpm_check(gen->ea) || \
	!xpm_check(gen->we) || (gen->door_two && !xpm_check(gen->door_two)) || \
	(gen->door_one && !xpm_check(gen->door_one)))
	{
		free_all(gen);
		error_print("Texture is not an .xpm file");
	}
}

// Inizio del parsing, controlla il numero degli argomenti dati 
//al programma, che il file sia .cun e che sia apribile
void	parsing(int argc, char *argv[], t_data *gen)
{
	int	fd;
	int	len;

	if (argc != 2)
		error_print("Invalid number of arguments");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || !argv[1])
	{
		close(fd);
		error_print("File is not usable");
	}
	len = ft_strlen(argv[1]);
	if (argv[1][len - 4] != '.' || argv[1][len - 3] != 'c' || \
		argv[1][len - 2] != 'u' || argv[1][len - 1] != 'b' || \
		argv[1][len] != '\0')
	{
		close(fd);
		error_print("File is not of a .cub file");
	}
	gen->file_name = argv[1];
	read_file(fd, gen);
	fill_struct(gen, -1, 0);
	check_rgb(gen);
	map_pars(gen, -1, -1);
	trim_direction_texture(gen);
}

//print_map(gen);
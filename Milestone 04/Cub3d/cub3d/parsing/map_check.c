/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfanelli <mfanelli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 12:23:55 by mfanelli          #+#    #+#             */
/*   Updated: 2025/07/10 16:41:05 by mfanelli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	struct_full(t_data *gen)
{
	if (gen->ea && gen->no && gen->so && gen->we \
		&& gen->floor && gen->ceiling)
		return (1);
	return (0);
}

//Compila la struct se trova uno degli elementi nel file
void	struct_check(t_data *gen, char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n' || str[0] == '1')
		return ;
	while (str[i] > 6 && str[i] < 33)
		i++;
	if (ft_strncmp(str + i, "NO", 2) == 0)
		gen->no = ft_strndup(str + i, ft_strlen(str + i) - 1);
	else if (ft_strncmp(str + i, "SO", 2) == 0)
		gen->so = ft_strndup(str + i, ft_strlen(str + i) - 1);
	else if (ft_strncmp(str + i, "WE", 2) == 0)
		gen->we = ft_strndup(str + i, ft_strlen(str + i) - 1);
	else if (ft_strncmp(str + i, "EA", 2) == 0)
		gen->ea = ft_strndup(str + i, ft_strlen(str + i) - 1);
	else if (ft_strncmp(str + i, "F", 1) == 0)
		gen->floor = ft_strndup(str + i, ft_strlen(str + i) - 1);
	else if (ft_strncmp(str + i, "C", 1) == 0)
		gen->ceiling = ft_strndup(str + i, ft_strlen(str + i) - 1);
	return ;
}

//Riempie la struct con le informazioni trovate nel file e
//alloca e compila la mappa
int	fill_struct(t_data *gen, int i, int size)
{
	int		fd;
	char	*str;

	fd = open(gen->file_name, O_RDONLY);
	str = get_next_line_bonus(fd);
	while (str != NULL && ft_strncmp(str, gen->gen_ptr, ft_strlen(str)) != 0)
	{
		if (struct_full(gen) == 0)
			struct_check(gen, str);
		free(str);
		str = get_next_line_bonus(fd);
	}
	while (i < gen->map_height && str)
	{
		if ((int)(ft_strlen(str) - 1) > size)
			size = ft_strlen(str) - 1;
		gen->map[i] = ft_strndup(str, ft_strlen(str));
		free(str);
		str = get_next_line_bonus(fd);
		i++;
	}
	gen->map_width = size;
	return (free(str), close(fd), 1);
}

//Alloca la matrice e conta il numero di colonne della mappa
char	**alloc_map(int fd, char *str2, t_data *gen)
{
	char	**temp;
	int		column_num;

	column_num = count_collums(fd, str2);
	gen->map_height = column_num;
	temp = (char **)ft_calloc(sizeof(char *), column_num);
	fd = open(gen->file_name, O_RDONLY);
	str2 = get_next_line_bonus(fd);
	while (ft_strncmp(str2, gen->gen_ptr, ft_strlen(str2)) != 0)
	{
		free(str2);
		str2 = get_next_line_bonus(fd);
	}
	free(str2);
	close(fd);
	return (temp);
}

//Scorre per tutto il file fino a raggiungere l'inizio della mappa
void	check_map(char *str, int fd, t_data *gen)
{
	char	*str2;

	free(str);
	str = get_next_line_bonus(fd);
	while (ft_strncmp(str, "\n", 1) == 0)
	{
		free(str);
		str = get_next_line_bonus(fd);
	}
	close(fd);
	fd = open(gen->file_name, O_RDONLY);
	str2 = get_next_line_bonus(fd);
	while (ft_strncmp(str2, str, ft_strlen(str2)) != 0)
	{
		free(str2);
		str2 = get_next_line_bonus(fd);
		if (!str2)
		{
			free_all(gen);
			error_print("Map is missing");
		}
	}
	gen->gen_ptr = ft_strdup(str);
	gen->map = alloc_map(fd, str2, gen);
	free(str);
}

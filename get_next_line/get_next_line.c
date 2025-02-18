/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lparolis <lparolis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 17:57:58 by lparolis          #+#    #+#             */
/*   Updated: 2024/12/21 17:57:58 by lparolis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_new(char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\n')
		return ((char *) &s[i]);
	return (NULL);
}

char	*ft_check_read(int fd, char *statik, char *buffer)
{
	ssize_t	read_bytes;
	char	*temp;

	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes == -1)
		{
			free(statik);
			return (NULL);
		}
		if (read_bytes == 0)
			break ;
		buffer[read_bytes] = '\0';
		if (!statik)
			statik = ft_strdup("");
		temp = statik;
		statik = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr_new(buffer))
			break ;
	}
	return (statik);
}

char	*ft_roll_and_print(char *result)
{
	char	*leftover;
	size_t	counter;

	counter = 0;
	while (result[counter] != '\n' && result[counter] != '\0')
		counter++;
	if (result[counter] == 0 || result[counter + 1] == 0)
		return (NULL);
	leftover = ft_substr(result, counter + 1, ft_strlen(result) - counter);
	if (*leftover == 0)
	{
		free(leftover);
		leftover = NULL;
	}
	result[counter + 1] = 0;
	return (leftover);
}

char	*get_next_line(int fd)
{
	static char	*statik[MAX_FD];
	char		*result;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(statik[fd]);
		statik[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	result = ft_check_read(fd, statik[fd], buffer);
	free(buffer);
	buffer = NULL;
	if (!result)
		return (NULL);
	statik[fd] = ft_roll_and_print(result);
	return (result);
}

//int main ()
//{
//	char	*line;
//	int		fd;
//	int		i = 1;  
//
//	fd = open("test.txt", O_RDONLY);
//	line = get_next_line(fd);
//	printf("%s", line);	
//	while (1)
//	{
//		if (line == NULL)
//		{
//			printf("	[FINE]");
//			break ;
//		}
//		printf("riga %d: %s", i, line);
//		free(line);
//		line = get_next_line(fd);
//		i++;
//	}
//	free(line);
//	close(fd);
//	return (0);
//}

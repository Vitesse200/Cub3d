/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:05:12 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/26 11:48:48 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_file_type(char *s, char *end)
{
	int	s_len;
	int	end_len;

	s_len = ft_strlen(s);
	end_len = ft_strlen(end);
	if (s_len <= end_len)
		return (0);
	s += s_len - end_len;
	while (*s)
	{
		if (*s != *end)
			return (0);
		s++;
		end++;
	}
	return (1);
}

int	ft_file_linecount(char *file)
{
	char	c;
	int		read_bytes;
	int		line_count;
	int		fd;

	fd = open (file, O_RDONLY);
	if (!fd)
		return (-1);
	line_count = 1;
	while (fd)
	{
		read_bytes = read(fd, &c, 1);
		if (read_bytes == 0)
			break ;
		if (read_bytes < 1)
			return (-1);
		if (c == '\n')
			line_count++;
	}
	close (fd);
	return (line_count);
}

t_map	ft_alloc_lines(char *file, t_map *game)
{
	int		linecount;

	linecount = ft_file_linecount(file);
	if (linecount <= 0)
		error(NULL);
	game->size.y = linecount;
	game->map = malloc(sizeof(char *) * (linecount + 1));
	if (!game->map)
		error (NULL);
	return (*game);
}

int	ft_valid_file(char *file)
{
	if (!ft_file_type(file, ".cub"))
		return (0);
	return (1);
}

void	ft_get_map(t_map *map, char *file)
{
	int	fd;
	int	i;

	i = 0;
	ft_alloc_lines(file, map);
	if (!map->map)
		return ;
	fd = open (file, O_RDONLY);
	while (fd)
	{
		map->map[i] = gnl(fd);
		if (!map->map[i])
			break ;
		i++;
	}
	close (fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exctract_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:21:30 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 17:34:24 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	map_start_y(int i, t_map *map)
{
	int	j;

	j = i + 1;
	while (map->map[j])
	{
		if (ft_strchr(map->map[j], '1') != 0)
		{
			map->start_y = j;
			break ;
		}
		j++;
	}
	j = map->start_y;
	while (map->map[j])
		j++;
	map->max_y = j;
}

int	ft_map_data(t_map *map)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (map->map[i] && count < 6)
	{
		if (map->map[i])
		{
			if (ft_match(map->map[i], map) == 1)
				count++;
		}
		i++;
	}
	if (count < 6)
		return (error("Wrong number of game data \n"));
	map_start_y(i, map);
	return (1);
}

int	get_play_map(t_map *map)
{
	int	y;
	int	x;
	int	z;

	x = 0;
	y = map->start_y;
	while (map->map[y])
	{
		z = 0;
		while (map->map[y][z] != '\n')
		{
			map->play_map[x][z] = map->map[y][z];
			z++;
			if (map->map[y][z] == '\0')
				break ;
		}
		if (y < map->max_y)
			map->play_map[x][z] = '\n';
		else
			map->play_map[x][z] = '\0';
		y++;
		x++;
	}
	map->play_map[x] = NULL;
	return (0);
}

void	malloc_text(t_map *map)
{
	map->north = malloc(sizeof(t_texture));
	map->south = malloc(sizeof(t_texture));
	map->west = malloc(sizeof(t_texture));
	map->east = malloc(sizeof(t_texture));
}

int	ft_extract(t_map *map)
{
	malloc_text(map);
	init_map(map);
	init_window(map);
	if (!ft_map_data(map))
		return (error("Data extraction issue"));
	if (!get_max_value(map))
		return (error("Issue with max value extraction\n"));
	ft_malloc_play_map(map);
	get_play_map(map);
	if (!map->play_map)
		return (error("Map malloc did not work"));
	if (!get_max_value_play(map))
		return (error("Issue with max value extraction\n"));
	if (ft_texture_data(map) != 1)
		exit (0);
	init_all_text(map);
	return (1);
}

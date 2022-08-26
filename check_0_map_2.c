/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_0_map_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:33:30 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 14:43:45 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_last_border(t_map map, int y, int x)
{
	while (map.play_map[y][x])
	{
		if ((map.play_map[y][x] != '1' && map.play_map[y][x] != ' ') && y == 0)
			return (0);
		x++;
	}
	return (1);
}

int	check_borders(t_map map)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < map.max_y)
	{
		while (map.play_map[y][x] != '\n')
		{
			if ((map.play_map[y][x] != '1' && map.play_map[y][x] != ' '
			&& map.play_map[y][x] != '\n') && y == 0)
				return (0);
			x++;
		}
		if (map.play_map[y][x - 1] != '1' && map.play_map[y][x - 1] != ' ')
			return (0);
		x = 0;
		y++;
		if (map.play_map[y][x] != '1' && map.play_map[y][x] != ' ')
			return (0);
	}
	if (check_last_border(map, y, x) == 0)
		return (0);
	return (1);
}

int	player_pos(t_map *s_map, char **map)
{
	int	y;
	int	count;

	count = 0;
	y = 0;
	while (map[y])
	{
		count = ft_find_player(count, map, y, s_map);
		y++;
	}
	if (count == 1)
		return (1);
	else
		return (error ("Player issue\n"));
	return (0);
}

int	check_valid_char(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x] != '\n' && map[y][x] != '\0')
		{
			if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '\n'
			&& map[y][x] != '\0' && map[y][x] != 'N' && map[y][x] != 'S'
			&& map[y][x] != 'E' && map[y][x] != 'W' && map[y][x] != ' ')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

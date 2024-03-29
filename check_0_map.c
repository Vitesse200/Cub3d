/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_0_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:16:33 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/26 15:20:22 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_find_player(int count, char **map, int y, t_map *s_map)
{
	int	x;

	x = 0;
	while (map[y][x] != '\n' && map[y][x] != '\0')
	{
		if (map[y][x] == 'W' || map[y][x] == 'E'
		|| map[y][x] == 'N' || map[y][x] == 'S')
		{
			count += 1;
			s_map->player.x = x * TILE_SIZE + TILE_SIZE / 2;
			s_map->player.y = y * TILE_SIZE + TILE_SIZE / 2;
			s_map->orientation = map[y][x];
			if (s_map->orientation == 'N')
				s_map->player.angle = 90;
			if (s_map->orientation == 'S')
				s_map->player.angle = 270;
			if (s_map->orientation == 'E')
				s_map->player.angle = 0;
			if (s_map->orientation == 'W')
				s_map->player.angle = 180;
		}
		x++;
	}
	return (count);
}

int	check_zero_2(char **map, int y, int x)
{
	if (map[y][x] == '0' || map[y][x] == 'W' || map[y][x] == 'E'
	|| map[y][x] == 'N' || map[y][x] == 'S')
	{
		if (map[y][x + 1] == '\0' || map[y][x + 1] == ' '
		|| map[y][x + 1] == '\n')
			return (0);
		if (map[y][x - 1] == '\0' || map[y][x - 1] == ' '
		|| map[y][x - 1] == '\n')
			return (0);
		if (map[y + 1][x] == '\0' || map[y + 1][x] == ' '
		|| map[y + 1][x] == '\n')
			return (0);
		if (map[y - 1][x] == '\0' || map[y - 1][x] == ' '
		|| map[y - 1][x] == '\n')
			return (0);
	}
	return (1);
}

int	check_zero(char **map, int y)
{
	int	x;

	x = 0;
	while (map[y][x] != '\n' && map[y][x] != '\0')
	{
		if (map[y + 1])
		{
			if (check_zero_2(map, y, x) == 0)
				return (0);
		}
		else if (map[y][x] == '0' || map[y][x] == 'W' || map[y][x] == 'E'
		|| map[y][x] == 'N' || map[y][x] == 'S')
			return (0);
		x++;
	}
	return (1);
}

void	ft_fill_map(t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (map->play_map[y])
	{
		x = 0;
		while (map->play_map[y][x] != '\n' && map->play_map[y][x] != '\0')
		{
			x++;
		}
		if (x < map->max_x)
		{
			while (x < map->max_x)
			{
				map->play_map[y][x] = '1';
				x++;
			}
			if (y < map->max_y)
				map->play_map[y][x] = '\n';
			else
				map->play_map[y][x] = '\0';
		}
		y++;
	}
}

int	ft_check_map(t_map *s_map)
{
	char	**map;
	int		y;

	map = s_map->play_map;
	if (!check_valid_char(map))
		return (0);
	if (!player_pos(s_map, map))
		return (error("Player is not valid"));
	if (!check_borders(*s_map))
		return (error("Map is not valid"));
	y = 0;
	while (map[y])
	{
		if (!check_zero(map, y))
			return (error("Map is not valid"));
		y++;
	}
	ft_fill_map(s_map);
	return (1);
}

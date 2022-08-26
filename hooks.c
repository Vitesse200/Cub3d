/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:43:15 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 17:45:31 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move(int key, t_map *map)
{
	if (key == 2)
		ft_move_r(&map->player, map);
	else if (key == 0)
		ft_move_l(&map->player, map);
	else if (key == 13)
		ft_move_up(&map->player, map);
	else
		ft_move_d(&map->player, map);
}

void	ft_camera(int key, t_map *map)
{
	if (key == 123)
	{
		map->player.angle += 10;
		if (map->player.angle == 360)
			map->player.angle += 0;
		if (map->player.angle > 360)
			map->player.angle -= 360;
	}
	else if (key == 124)
	{
		map->player.angle -= 10;
		if (map->player.angle < 0)
			map->player.angle += 360;
		if (map->player.angle > 360)
			map->player.angle -= 360;
	}
	else
	{
		exit(0);
	}	
}

int	ft_input(int key, void *param)
{
	t_map		*map;

	map = (t_map *)param;
	if (key == 2 || key == 0 || key == 13 || key == 1)
		ft_move(key, map);
	else if (key == 123 || key == 124 || key == 53)
		ft_camera(key, map);
	else
		return (0);
		draw_map(&map->winp, map);
	return (0);
}

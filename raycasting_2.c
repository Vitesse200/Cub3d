/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaillar <lgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:25:09 by lgaillar          #+#    #+#             */
/*   Updated: 2022/08/26 17:00:59 by lgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_wall	*get_dist(float dist, t_map map, int v_t, t_wall *wall)
{
	wall->heigth = (TILE_SIZE / dist * PROJ_DIST);
	wall->wall_top = (WINDOW_H / 2) - (wall->heigth / 2);
	if (v_t == 1)
	{		
		if (map.player.angle < 270 && map.player.angle > 90)
			wall->direction = 4;
		else
			wall->direction = 2;
	}
	else
	{
		if (map.player.angle > 180)
			wall->direction = 3;
		else
			wall->direction = 1;
		wall->color = wall->h;
	}
	return (wall);
}

float	get_temp_2(t_map *map)
{
	float	temp;
	int		neg;

	neg = 1;
	temp = map->player.angle / 90;
	if (temp < 1)
		neg = -1;
	if (temp < 3 && temp > 2)
		neg = -1;
	temp = temp - floorf(temp);
	if (neg == -1)
		temp -= 1;
	if (temp == 0 && map->player.angle != 90 && map->player.angle != 270)
		temp = 1;
	return (temp);
}

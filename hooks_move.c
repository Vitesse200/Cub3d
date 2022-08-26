/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaillar <lgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:42:27 by lgaillar          #+#    #+#             */
/*   Updated: 2022/08/26 16:57:14 by lgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_move_r(t_vector *game, t_map *map)
{
	int		x_c;
	int		y_c;
	float	temp;

	x_c = game->x;
	y_c = game->y;
	temp = get_temp(map);
	if ((map->player.angle > 90 && map->player.angle <= 270))
	{
		x_c -= (temp * 16) * 4;
		y_c -= (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x -= (temp * 16);
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y -= (16 - fabs(temp * 16));
	}
	else
	{
		x_c += (temp * 16) * 4;
		y_c += (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x += (temp * 16);
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y += (16 - fabs(temp * 16));
	}
}

float	get_temp(t_map *map)
{
	float	temp;
	int		neg;

	neg = 1;
	temp = map->player.angle / 90;
	if (temp > 1 && temp < 2)
		neg = -1;
	if (temp > 3 && temp < 4)
		neg = -1;
	temp = temp - floorf(temp);
	if (neg == -1)
		temp -= 1;
	if (temp == 0 && (map->player.angle == 90 || map->player.angle == 270))
		temp = 1;
	return (temp);
}

void	ft_move_l(t_vector *game, t_map *map)
{
	float	temp;
	int		x_c;
	int		y_c;

	x_c = game->x;
	y_c = game->y;
	temp = get_temp(map);
	if ((map->player.angle > 90 && map->player.angle <= 270))
	{
		x_c += (temp * 16) * 4;
		y_c += (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x += temp * 16;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y += 16 - fabs(temp * 16);
	}
	else
	{
		x_c -= (temp * 16) * 4;
		y_c -= (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x -= temp * 16;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y -= 16 - fabs(temp * 16);
	}
}

void	ft_move_up(t_vector *game, t_map *map)
{
	float	temp;
	int		x_c ;
	int		y_c;

	x_c = game->x;
	y_c = game->y;
	temp = get_temp_2(map);
	if (map->player.angle <= 180.001)
	{
		x_c -= (temp * 16) * 4;
		y_c -= (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x -= temp * 16;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y -= 16 - fabs(temp * 16);
	}
	else
	{
		x_c += (temp * 16) * 4;
		y_c += (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x += temp * 16;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y += 16 - fabs(temp * 16);
	}
}

void	ft_move_d(t_vector *game, t_map *map)
{
	float	temp;
	int		x_c ;
	int		y_c;

	x_c = game->x;
	y_c = game->y;
	temp = get_temp_2(map);
	if (map->player.angle <= 180.001)
	{
		x_c += (temp * 16) * 4;
		y_c += (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x += temp * 16;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y += 16 - fabs(temp * 16);
	}
	else
	{
		x_c -= (temp * 16) * 4;
		y_c -= (16 - fabs(temp * 16)) * 4;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->x -= temp * 16;
		if (map->play_map[y_c / 64][x_c / 64] != '1')
			game->y -= 16 - fabs(temp * 16);
	}
}

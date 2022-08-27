/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaillar <lgaillar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:42:27 by lgaillar          #+#    #+#             */
/*   Updated: 2022/08/26 16:57:14 by lgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_map(t_winp *win, t_map *map)
{
	t_vector	xpm;

	map->player.angle += 30;
	xpm.x = 0;
	xpm.y = 0;
	draw_2(win, map, xpm);
	if (map->player.angle > 360)
		map->player.angle -= 360;
	map->player.angle += 30;
	if (map->player.angle > 360)
		map->player.angle -= 360;
}

void	draw_2(t_winp *win, t_map *map, t_vector xpm)
{
	t_wall	*wall;
	float	cos;

	map->ray = 0;
	cos = -30;
	while (map->ray < WINDOW_W)
	{
		wall = find_wall_distance(*map, cos);
		if (0 != wall->direction || wall->color == 0)
			xpm.x = 0;
		xpm.x = wall->color;
		xpm.y = 0;
		img_put(win, wall, map, &xpm);
		free(wall);
		xpm.x++;
		map->player.angle -= ANGLE_DIFF;
		if (map->player.angle < 0)
			map->player.angle += 360;
		if (map->player.angle > 360)
			map->player.angle -= 360;
		cos += ANGLE_DIFF;
		map->ray++;
	}
}

void	window_manager(t_map *map)
{
	draw_map(&map->winp, map);
	mlx_hook(map->winp.win, 17, 0, &ft_close, 0);
	mlx_key_hook(map->winp.win, ft_input, map);
	mlx_loop(map->winp.mlx);
	if (map->winp.win == NULL)
		exit(0);
}

double	tan_degrees(double angle)
{
	angle = angle * (M_PI / 180);
	angle = tan(angle);
	return (angle);
}

double	cos_degrees(double angle)
{
	angle = angle * (M_PI / 180);
	angle = cos(angle);
	return (angle);
}

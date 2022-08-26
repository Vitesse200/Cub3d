/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Image_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:45:56 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/26 16:27:51 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_winp *data, int x, int y, int color)
{
	int	*dst;

	dst = NULL;
	if (y < WINDOW_H && x < WINDOW_W && x >= 0 && y >= 0)
	{
		dst = data->addr_canva + (y * (data->size_line / 4) + x);
		*dst = color;
	}
}

t_texture	direction_texture(int dir, t_map *map)
{
	if (dir == 1)
		return (*map->north);
	else if (dir == 2)
		return (*map->east);
	else if (dir == 3)
		return (*map->south);
	else
		return (*map->west);
}

void	pxl_put(t_wall *wall, t_map *map, t_vector *xpm, t_texture *texture)
{
	while (wall->wall_top < wall->heigth + wall->i)
	{
		if (wall->wall_top < WINDOW_H)
		{
			map->ratio = (float )texture->img_width / 64;
			wall->color = jo_pixel_color(xpm->x * map->ratio,
					xpm->y++ / (wall->heigth / texture->img_height), *texture);
			my_mlx_pixel_put(&map->winp, map->ray, wall->wall_top, wall->color);
		}	
		if (xpm->y >= wall->heigth)
			xpm->y = 0;
		wall->wall_top++;
	}
}

void	img_put(t_winp *winp, t_wall *wall, t_map *map, t_vector *xpm)
{
	t_texture	texture;

	wall->i = 0;
	map->ratio = 0;
	if (wall->i < wall->wall_top)
	{
		while (wall->i < wall->wall_top)
			my_mlx_pixel_put(winp, map->ray, wall->i++,
				map->ceiling_rgb.int_hexa);
	}
	texture = direction_texture(wall->direction, map);
	pxl_put(wall, map, xpm, &texture);
	while (wall->wall_top < WINDOW_H)
	{
		my_mlx_pixel_put(winp, map->ray, wall->wall_top,
			map->floor_rgb.int_hexa);
		wall->wall_top++;
	}
	if (map->ray == WINDOW_W - 1)
		mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
}

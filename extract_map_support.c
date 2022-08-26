/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_support.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:20:55 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/26 15:18:05 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map(t_map *map)
{
	map->player.x = 0;
	map->player.y = 0;
	map->start_y = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->tab_floor = 0;
	map->tab_ceiling = 0;
	map->player.angle = 0;
	map->play_map = NULL;
	map->tmp = NULL;
	map->north->extract = NULL;
	map->south->extract = NULL;
	map->west->extract = NULL;
	map->east->extract = NULL;
	map->north->path = NULL;
	map->south->path = NULL;
	map->west->path = NULL;
	map->east->path = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	map->orientation = 0;
}

void	init_window(t_map *map)
{
	map->winp.mlx = mlx_init();
	map->winp.win = mlx_new_window(map->winp.mlx,
			WINDOW_W, WINDOW_H, "Cub3d");
	map->winp.canvas_ptr = mlx_new_image(map->winp.mlx, WINDOW_W, WINDOW_H);
	map->winp.addr_canva = (int *) mlx_get_data_addr(map->winp.canvas_ptr,
			&map->winp.bpp, &map->winp.size_line, &map->winp.endian);
}

char	*ft_malloc_play_map(t_map *s_map)
{
	int	y;

	y = 0;
	s_map->play_map = malloc(sizeof(char *)
			* (2 + (s_map->max_y - s_map->start_y)));
	while (y < 2 + (s_map->max_y - s_map->start_y))
	{
		s_map->play_map[y] = malloc(sizeof(char) * (s_map->max_x + 5));
		y++;
	}
	if (!s_map->play_map)
		return (null_error("malloc error"));
	return (NULL);
}

int	get_max_value(t_map *s_map)
{
	int	y;
	int	len;

	y = s_map->start_y;
	while (s_map->map[y])
	{
		len = ft_strlen(s_map->map[y]);
		if ((len - 1 > s_map->max_x))
			s_map->max_x = len - 1;
		y++;
	}
	s_map->max_y = y - 1;
	if (!s_map->max_y || !s_map->max_x)
		return (0);
	return (1);
}

int	get_max_value_play(t_map *s_map)
{
	int	y;
	int	len;

	y = 0;
	while (s_map->play_map[y])
	{
		len = ft_strlen(s_map->play_map[y]);
		if ((len - 1 > s_map->max_x))
			s_map->max_x = len - 1;
		y++;
	}
	s_map->max_y = y - 1;
	if (!s_map->max_y || !s_map->max_x)
		return (0);
	return (1);
}

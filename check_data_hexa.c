/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_hexa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 14:46:32 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 15:18:28 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	dec2hex(int *rgbd, t_rgbhex *rgbh)
{
	char	*hexvalues;
	int		i0;
	int		i1;

	hexvalues = "0123456789ABCDEF";
	rgbh->rgb[0] = '0';
	rgbh->rgb[1] = 'x';
	i0 = rgbd[0] / 16;
	i1 = rgbd[0] - (16 * i0);
	rgbh->rgb[2] = hexvalues[i0];
	rgbh->rgb[3] = hexvalues[i1];
	i0 = rgbd[1] / 16;
	i1 = rgbd[1] - (16 * i0);
	rgbh->rgb[4] = hexvalues[i0];
	rgbh->rgb[5] = hexvalues[i1];
	i0 = rgbd[2] / 16;
	i1 = rgbd[2] - (16 * i0);
	rgbh->rgb[6] = hexvalues[i0];
	rgbh->rgb[7] = hexvalues[i1];
	rgbh->rgb[8] = '\0';
}

int	color_bitshift(unsigned char a, unsigned char r,
unsigned char g, unsigned char b)
{
	int	rgb;

	rgb = (a << 24);
	rgb = rgb | (r << 16);
	rgb = rgb | (g << 8);
	rgb = rgb | (b);
	return (rgb);
}

int	convert_hexa(t_map *map)
{
	dec2hex(map->tab_floor, &map->floor_rgb);
	map->floor_rgb.int_hexa = color_bitshift(0, map->tab_floor[0],
			map->tab_floor[1], map->tab_floor[2]);
	dec2hex(map->tab_ceiling, &map->ceiling_rgb);
	map->ceiling_rgb.int_hexa = color_bitshift(0, map->tab_ceiling[0],
			map->tab_ceiling[1], map->tab_ceiling[2]);
	return (1);
}

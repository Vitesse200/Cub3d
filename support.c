/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:38:45 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/26 11:49:58 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_match(char *c, t_map *map)
{
	if ((!ft_strncmp(c, "NO", 2) && !map->north->extract)
		|| (!ft_strncmp(c, "WE", 2) && !map->west->extract)
		|| (!ft_strncmp(c, "SO", 2) && !map->south->extract && c[2] == ' ')
		|| (!ft_strncmp(c, "EA", 2) && !map->east->extract))
	{
		if (c[0] == 'N' && c[1] == 'O' && c[2] == ' ')
			map->north->extract = c;
		else if (c[0] == 'W' && c[1] == 'E' && c[2] == ' ')
			map->west->extract = c;
		else if (c[0] == 'E' && c[1] == 'A' && c[2] == ' ')
			map->east->extract = c;
		else
			map->south->extract = c;
		return (1);
	}
	else if ((!ft_strncmp(c, "F", 1) && !map->floor)
		|| (!ft_strncmp(c, "C", 1) && !map->ceiling))
	{
		if (c[0] == 'F')
			map->floor = c;
		else
			map->ceiling = c;
		return (1);
	}
	return (0);
}

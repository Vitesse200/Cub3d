/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 15:19:39 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 16:50:51 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_valid_f_data(t_map *map)
{
	char	*f;
	int		i;

	f = map->floor;
	i = 0;
	while (f[i] != '\n')
	{
		if (i == 0)
		{
			if (f[i] != 'F')
				return (error("should start with F\n"));
			i++;
		}
		if (!ft_check_valid_num(f, i))
			return (0);
		i = ft_check_valid_num(f, i);
	}
	return (1);
}

int	ft_valid_c_data(t_map *map)
{
	char	*c;
	int		i;

	c = map->ceiling;
	i = 0;
	while (c[i] != '\n')
	{
		if (i == 0)
		{
			if (c[i] != 'C')
				return (error("should start with C\n"));
		i++;
		}
		if (!ft_check_valid_num(c, i))
			return (0);
		i = ft_check_valid_num(c, i);
	}
	return (1);
}

int	extract_rgb(int i, char *rgb, char t, t_map *map)
{
	int	*tab;
	int	count;
	int	j;

	count = 0;
	tab = ft_tab(t, map);
	while (rgb[++i] && count < 3)
	{
		if (ft_isnum(rgb[i]))
		{
			j = 0;
			map->tmp = malloc(sizeof(char *));
			if (!map->tmp)
				return (0);
			while (ft_isnum(rgb[i]))
				map->tmp[j++] = rgb[i++];
			if (j < 3)
				while (j < 3)
					map->tmp[j++] = ' ';
			tab[count++] = ft_atoi(map->tmp);
			free(map->tmp);
			tab[count] = '\0';
		}
	}
	return (count);
}

int	ft_extract_f_data(t_map *map)
{
	int		i;
	char	*rgb;
	int		count;

	rgb = map->floor;
	i = -1;
	map->tab_floor = malloc(sizeof(int) * 4);
	if (!map->tab_floor)
		return (0);
	count = extract_rgb(i, rgb, 'f', map);
	if (count != 3)
		return (error("rgb made of 3 numbers\n"));
	return (1);
}

int	ft_extract_data(t_map *map)
{
	int	i;

	i = 0;
	if (!ft_valid_c_data(map))
		return (0);
	if (!ft_valid_f_data(map))
		return (0);
	if (!ft_extract_c_data(map))
		return (0);
	if (!ft_extract_f_data(map))
		return (0);
	if (!ft_check_rgb(map->tab_ceiling) || !ft_check_rgb(map->tab_floor))
		return (0);
	convert_hexa(map);
	while (i < 3)
		i++;
	return (1);
}

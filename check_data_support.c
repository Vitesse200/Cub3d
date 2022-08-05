/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_support.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 16:51:50 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 16:55:40 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_isnum(int c)
{
	if (c > 47 && c < 58)
		return (1);
	else
		return (0);
}

int	*ft_tab(char t, t_map *map)
{
	int	*tab;

	if (t == 'f')
		tab = map->tab_floor;
	if (t == 'c')
		tab = map->tab_ceiling;
	return (tab);
}

int	ft_check_valid_num(char *f, int i)
{
	if (!ft_isnum(f[i]))
	{
		while (f[i] == ' ' || f[i] == ',')
			i++;
		while (f[i] != ' ' && f[i] != ',' && f[i] != '\n')
		{
			if (!ft_isnum(f[i]))
				return (error(" F Should be num\n"));
			i++;
		}
	}
	return (i);
}

int	ft_extract_c_data(t_map *map)
{
	int		i;
	int		count;
	char	*rgb;
	char	*tmp;

	rgb = map->ceiling;
	i = -1;
	count = 0;
	tmp = NULL;
	map->tab_ceiling = malloc(sizeof(int) * 4);
	if (!map->tab_ceiling)
		return (0);
	count = extract_rgb(i, rgb, 'c', map);
	if (count != 3)
		return (error("rgb made of 3 numbers\n"));
	return (1);
}

int	ft_check_rgb(int *tab)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (tab[i] > 255 || tab[i] < 0)
			return (error("wrong rgb value\n"));
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 11:53:54 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/26 11:53:55 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strcmp(&map->map[i][j], " "))
				write(1, " ", 1);
			else
				write(1, &map->map[i][j], 1);
			j++;
		}
		i++;
	}
}

void	ft_print_player_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write (1, "\n", 2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (error("expecting 1 map as argument\n"));
	if (!ft_valid_file(argv[1]))
		return (error("expecting .cub file type\n"));
	ft_get_map(&map, argv[1]);
	if (!ft_extract(&map))
		return (0);
	if (!map.map)
		return (error("no map to extract"));
	if (!ft_check_map(&map))
		return (error("map not valid\n"));
	if (!ft_extract_data(&map))
		return (error("rgb data issue\n"));
	window_manager(&map);
	return (0);
}

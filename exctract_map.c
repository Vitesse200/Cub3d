#include "cub3d.h"

void	map_start_y(int i, t_map *map)
{
	int	j = i + 1;

	while (map->map[j])
	{
		if (ft_strchr(map->map[j], '1') != 0)
		{
			map->start_y = j;
			break ;
		}
		j++;
	}
	j = map->start_y;
	while (map->map[j])
		j++;
	map->max_y = j;
}

int	ft_map_data(t_map *map)
{
	int	i;
	int	count;
	
	i = 0;
	count = 0;
	while (map->map[i] && count < 6)
	{
		if (map->map[i])
		{
			if (ft_match(map->map[i], map) == 1)
				count++;
		}
		i++;
	}
    if (count < 6)
        return (error("Wrong number of game data \n"));
	map_start_y(i, map);
	return (1);
}

int	get_play_map(t_map *map)
{
	int	y;
	int	x = 0;
    int z = 0;
    int w = 0;
    char    *tmp;

	y = map->start_y;
	while (map->map[y])
	{
        x = 0;
        tmp = malloc(sizeof(char) * ft_strlen(map->map[y]) + 1);
        z = 0;
        while (map->map[y][x])
        {
            tmp[z] = map->map[y][x];
            x++;
            z++;
        }
        tmp[z] = 0;
        map->play_map[w] = tmp;
        y++;
        w++;
	}
    map->play_map[w] = 0;
	return (0);
}

int ft_extract(t_map *map)
{
	init_map(map);
	if (!ft_map_data(map))
        return (error("Data extraction issue"));
	map->play_map = ft_malloc_play_map(map);
    if (!map->play_map)
        return (error("Map malloc did not work"));
	get_play_map(map);
    if (!get_max_value(map->play_map, map))
        return (error("Issue with max value extraction\n"));
    return (1);
}
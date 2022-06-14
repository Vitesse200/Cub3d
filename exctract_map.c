# include "cub3d.h"

/* check first 6 lines:
first 4 lines have to be textures with valid identifiant and valid path
2 last line have to be F & C with valid rg content
*/
/*check where is map and details
Where does the map start
check if only valid charactere
check map size
check if closed map
*/

void	init_map(t_map *map)
{
	map->player.x = 0;
	map->player.y = 0;
	map->start_x = 0;
	map->start_y = 0;
	map->max_x = 0;
	map->max_y = 0;
	map->NO = NULL;
	map->SO = NULL;
	map->WE = NULL;
	map->EA = NULL;
	map->F = NULL;
	map->C = NULL;
	map->orientation = 0;
}

int	ft_match(char *c, t_map *map)
{
	if (!ft_strncmp(c, "NO", 2) && !map->NO)
	{
		map->NO = ft_strdup(c);
		return (1);
	}
	if (!ft_strncmp(c, "SO", 2) && !map->SO)
	{
		map->SO = c;
		return (1);
	}	
	if (!ft_strncmp(c, "WE", 2) && !map->WE)
	{
		map->WE = c;
		return (1);
	}
	if (!ft_strncmp(c, "EA", 2) && !map->EA)
	{
		map->EA = c;
		return (1);
	}
	if (!ft_strncmp(c, "F", 1) && !map->F)
	{
		map->F = c;
		return (1);
	}
	if (!ft_strncmp(c, "C", 1) && !map->C)
	{
		map->C = c;
		return (1);
	}
	return (0);
}

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
    {
        printf ("count = %d\n", count);
        return (error("Wrong number of game data, count = %d \n"));
    }
	map_start_y(i, map);
	return (1);
}

char	**ft_malloc_play_map(t_map *s_map)
{
	int	y;
	int	len;
	char	**map;

	y = s_map->start_y;
	map = s_map->map;
	while (map[y])
		y++;
	len = y;
	map = malloc(sizeof(char *) * len + 1);
	if (map == NULL)
		return (null_error("malloc error on ft_alloc_lines"));
	return (map);
}

int	get_play_map(t_map *map)
{
	int	y;
	int	x = 0;

	y = map->start_y;
	while (map->map[y])
	{
		map->play_map[x] = ft_strdup(map->map[y]);
		y++;
		x++;
	}
	return (0);
}

int get_max_value(char **map, t_map *s_map)
{
    int y;
    int x;
    int len;

    y = 0;
    x = 0;
    while (map[y])
    {
        len = ft_strlen(map[y]);
        if ((len - 1 > s_map->max_x))
            s_map->max_x = len - 2;
        y++;
    }
    s_map->max_y = y - 1;
    if (!s_map->max_y || !s_map->max_x)
        return (0);
    printf("Max x = %d\n", s_map->max_x);
    printf("Max y = %d\n", s_map->max_y);
    return (1);
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
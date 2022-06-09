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

void	map_max_x(t_map *map)
{
	int	y;
	int	len;
	int	l;

	y = map->start_y;
	while (map->map[y])
	{
		len = ft_strlen(map->map[y]);
		if ( len > map->max_x)
			map->max_x = len - 1;
		if ((ft_strchr(map->map[y], 'W') != 0) || (ft_strchr(map->map[y], 'E') != 0) || (ft_strchr(map->map[y], 'N') != 0) || (ft_strchr(map->map[y], 'S') != 0))
		{
			map->player.y = y;
			l = 0;
			while (map->map[y][l])
			{
				if (map->map[y][l] == 'W' || map->map[y][l] == 'E' || map->map[y][l] == 'S' || map->map[y][l] == 'N')
				{
					map->orientation = map->map[y][l];
					break;
				}
				l++;
			}
			map->player.x = l;
		}
		y++;
	}
}

int	ft_map_first(t_map *map)
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
	printf ("\nx = %d\n", count);
	printf ("i = %d\n", i);
	map_start_y(i, map);
	printf("map start y= %d\n", map->start_y);
	printf("map end y= %d\n", map->max_y);
	map_max_x(map);
	printf("map max x= %d\n", map->max_x);
	printf("map player y = %d\n", map->player.y);
	printf("map player x = %d\n", map->player.x);
	printf("map orientation = %c\n", map->map[map->player.y][map->player.x]);
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

int	ft_play_map(t_map *map)
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

int	ft_extract(t_map *map)
{
	init_map(map);
	ft_map_first(map);
	map->play_map = ft_malloc_play_map(map);
	ft_play_map(map);
	//ft_print_player_map(map->play_map);
	return (0);
}
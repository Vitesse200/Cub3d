#include "../cub3d.h"

void	init_map(t_map *map)
{
    map->player.x = 0;
    map->player.y = 0;
    map->start_x = 0;
    map->start_y = 0;
    map->max_x = 0;
    map->max_y = 0;
    map->player.angle = 0;
    map->NO = NULL;
    map->SO = NULL;
    map->WE = NULL;
    map->EA = NULL;
    map->F = NULL;
    map->C = NULL;
    map->orientation = 0;
}

char	**ft_malloc_play_map(t_map *s_map)
{
    int	y;
    int	len;
    char	**map;

    y = s_map->start_y;
    map = s_map->map;
	map = malloc(sizeof(char *) *)
    while (map[y])
        y++;
    len = y;
    map = malloc(sizeof(char *) * len + 1);
    if (map == NULL)
        return (null_error("malloc error on ft_alloc_lines"));
    return (map);
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
    return (1);
}

int	ft_match(char *c, t_map *map)
{
    if ((!ft_strncmp(c, "NO", 2) && !map->NO) || (!ft_strncmp(c, "SO", 2) && !map->SO)
    || (!ft_strncmp(c, "WE", 2) && !map->WE) || (!ft_strncmp(c, "EA", 2) && !map->EA))
    {
        if (c[0] == 'N')
            map->NO = c;
        else if (c[0] == 'W')
            map->WE = c;
        else if (c[0] == 'E')
            map->EA = c;
        else
            map->SO = c;
        return (1);
    }
    if ((!ft_strncmp(c, "F", 1) && !map->F) || (!ft_strncmp(c, "C", 1) && !map->C))
    {
        if (c[0] == 'F')
            map->F = c;
        else
            map->C = c;
        return (1);
    }
    return (0);
}

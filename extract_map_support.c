#include "cub3d.h"

void	init_map(t_map *map)
{
    map->player.x = 0;
    map->player.y = 0;
    map->start_y = 0;
    map->max_x = 0;
    map->max_y = 0;
    map->player.angle = 0;
    map->play_map = NULL;
    map->NO->extract = NULL;
    map->SO->extract = NULL;
    map->WE->extract = NULL;
    map->EA->extract = NULL;
    map->NO->path = NULL;
    map->SO->path = NULL;
    map->WE->path = NULL;
    map->EA->path = NULL;
    map->F = NULL;
    map->C = NULL;
    map->orientation = 0;
    map->winp.mlx = mlx_init();
    map->winp.win = mlx_new_window(map->winp.mlx,WINDOW_W, WINDOW_H,"Init_Cub3d");
    map->winp.canvas_ptr = mlx_new_image(map->winp.mlx, WINDOW_W, WINDOW_H);
    map->winp.addr_canva = (int *) mlx_get_data_addr(map->winp.canvas_ptr, &map->winp.bpp, &map->winp.size_line, &map->winp.endian);
}

char	**ft_malloc_play_map(t_map *s_map)
{
    int	y;

    y = 0;
	s_map->play_map = malloc(sizeof(char *) * 15);
	while (y < 1 + s_map->max_y - s_map->start_y)
	{
		s_map->play_map[y] = malloc(sizeof(char) * (s_map->max_x + 1));
		y++;
	}
    if (s_map->play_map == NULL)
        return (null_error("malloc error on ft_alloc_lines"));
    return (NULL);
}

int get_max_value(char **map, t_map *s_map)
{
    int y;
    int x;
    int len;

    len = 0;
    y = s_map->start_y;
    x = 0;
    while (map[y])
    {
        len = ft_strlen(map[y]);
        if ((len - 1 > s_map->max_x))
            s_map->max_x = len - 1;
        y++;
    }
    s_map->max_y = y - 1;
    if (!s_map->max_y || !s_map->max_x)
        return (0);
    return (1);
}

int	ft_match(char *c, t_map *map)
{
    if ((!ft_strncmp(c, "NO", 2) && !map->NO->extract) || (!ft_strncmp(c, "WE", 2) && !map->WE->extract)
        || (!ft_strncmp(c, "SO", 2) && !map->SO->extract) || (!ft_strncmp(c, "EA", 2) && !map->EA->extract))
    {
        if (c[0] == 'N')
            map->NO->extract = c;
        else if (c[0] == 'W')
            map->WE->extract = c;
        else if (c[0] == 'E')
            map->EA->extract = c;
        else
            map->SO->extract = c;
        return (1);
    }
    else if ((!ft_strncmp(c, "F", 1) && !map->F) || (!ft_strncmp(c, "C", 1) && !map->C))
    {
        if (c[0] == 'F')
            map->F = c;
        else
            map->C = c;
        return (1);
    }
    return (0);
}

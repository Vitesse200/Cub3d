#include "cub3d.h"

int ft_find_player(int count, char **map, int y, t_map *s_map)
{
    int x;

    x = 0;
    //s_map->player.angle = 0;
    while (map[y][x])
    {
        if (map[y][x] == 'W' || map[y][x] == 'E' || map[y][x] == 'N' || map[y][x] == 'S') {
            count += 1;
            s_map->player.x = x;
            s_map->player.y = y;
            s_map->orientation = map[y][x];
            if (s_map->orientation == 'N')
                s_map->player.angle = 90;
            if (s_map->orientation == 'S')
                s_map->player.angle = 270;
            if (s_map->orientation == 'E')
                s_map->player.angle = 180;
            if (s_map->orientation == 'W')
                s_map->player.angle = 0;
        }
        x++;
    }
    return (count);
}

int player_pos(t_map *s_map, char **map)
{
    int y;
    int count;

    count = 0;
    y = 0;
    while (map[y])
    {
        count = ft_find_player(count, map, y, s_map);
        y++;
    }
    if (count == 1)
        return (1);
    else
        return (error("Player issue\n"));
    return(0);
}

int check_valid_char(char **map)
{
    int y;
    int x;

    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] != '0' && map[y][x] != '1' && map[y][x] != '\n' && map[y][x] != '\0'
                && map[y][x] != 'N' && map[y][x] != 'S' && map[y][x] != 'E' && map[y][x] != 'W' && map[y][x] != ' '){
                printf("\nINVALID CHAR FOUND '%c' pose %d %d\n",map[y][x], y, x);
                return (0);
            }
            x++;
        }
        y++;
    }
    return (1);
}

int check_zero(char **map, int y)
{
    int x;

    x = 0;
    while (map[y][x])
    {
        if (map[y][x] == '0')
        {
            if (map[y][x+1] == '\0' || map[y][x+1] == ' ' || map[y][x+1] == '\n')
                return (0);
            if (map[y][x-1] == '\0' || map[y][x-1] == ' ' || map[y][x-1] == '\n')
                return (0);
            if (map[y+1][x] == '\0' || map[y+1][x] == ' ' || map[y+1][x] == '\n')
                return (0);
            if (map[y-1][x] == '\0' || map[y-1][x] == ' ' || map[y-1][x] == '\n')
                return (0);
        }
        x++;
    }
    return (1);
}

int ft_check_map(t_map *s_map)
{
    char    **map;
    int     y;

    map = s_map->play_map;
    //ft_print_player_map(map);
    if (!check_valid_char(map))
        return (0);
    if (!player_pos(s_map, map))
        return (error("Player is not valid"));
    y = 0;
    while (map[y])
    {
        if (!check_zero(map, y))
            return (error("Map is not valid"));
        y++;
    }
    return(1);
}

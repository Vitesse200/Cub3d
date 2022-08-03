#include "cub3d.h"

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
        while (map[y][x] != '\n' && map[y][x] != '\0')
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

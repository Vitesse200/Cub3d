
#include "cub3d.h"

int ft_find_1_left(char **map, int y, t_check *check)
{
    int x;

    x = 0;
    //printf("position left %d %d\n", y, x);
    while (map[y][x]){
        if (map[y][x] == '1'){
            if (y == 0){
                check->top_left.x = x;
                check->top_left.y = y;
            }
            return (1);
        }
        else if (map[y][x] == ' ')
            x++;
        else {
            printf("Invalid character found\n");
            return (0);
        }
    }
    return (0);
}

int ft_check_left_wall(char **map, t_check *check)
{
    int y;

    y = 0;
    while (map[y]){
        if (!ft_find_1_left(map, y, check)){
            printf("no 1 on line %d\n", y);
            return (0);
        }
        y++;
    }
    printf("left wall has 1 everywhere\n");
    return (1);
}

int ft_find_1_top(char **map, int x, int y)
{
    //printf("position top %d %d\n", y, x);
    while (map[y]){
        if (map[y][x] == '1')
            return (1);
        else if (map[y][x] == ' ' || map[y][x] == '\n' || !map[y][x])
            y++;
        else {
            printf("Invalid character found %d %d\n", y, x);
            return (0);
        }
    }
    printf("top error position %d %d\n", y, x);
    return (0);
}

int    ft_check_top_wall(char **map, int max_x, t_check *check)
{
    int x;
    int y;

    x = 0;
    y = 0;
    while (x <= max_x - 1){
        if (!ft_find_1_top(map, x, y)){
            printf("no 1 on line %d\n", x);
            return (0);
        }
        x++;
        if (map[y][x] == '\n' || !map[y][x])
            y++;
    }
    printf("top wall has 1 everywhere\n");
    check->top_right.x = x - 1;
    check->top_right.y = y - 1;
    return (1);
}

int ft_check_right_wall(char **map, t_check *check)
{
    int x;
    int y;
    int m;

    x = 0;
    y = 0;
    while (map[y])
        m = y++;
    y = 0;
    while (y <= m)
    {
        if (y == m)
            x = ft_strlen(map[y]) - 1;
        if (y < m)
            x = ft_strlen(map[y]) - 2;
        //printf("right char = %c line %d \n", map[y][x], y);
        if (map[y][x] != '1') {
            printf("line finishes with %c\n", map[y][x]);
            return (0);
        }
        y++;
    }
    printf("right wall has 1 everywhere\n");
    check->btm_right.x = x;
    check->btm_right.y = y - 1;
    return (1);
}

int ft_find_1_btm(char **map, int x, int y, t_check *check)
{
    //printf("position btm %d %d\n", y, x);
    while (map[y]){
        if (map[y][x] == '1'){
            if (x == 0){
                check->btm_left.x = x;
                check->btm_left.y = y;
            }
            return (1);
        }
        else if (map[y][x] == ' ' || map[y][x] == '\n' || !map[y][x])
            y--;
        else {
            printf("Invalid character found %d %d\n", y, x);
            return (0);
        }
    }
    printf("top error position %d %d\n", y, x);
    return (0);
}

int ft_check_bottom_wall(char **map, int max_x, t_check *check)
{
    int     x;
    int     y;

    y = 0;
    x = max_x - 1;
    while (map[y]){
        y++;
    }
    y -= 1;
    while (x >= 0)
    {
        if (!ft_find_1_btm(map, x, y, check)){
            printf("no 1 on line %d\n", x);
            return (0);
        }
        x--;
    }
    printf("bottom wall has 1 everywhere\n");
    return (1);
}

int check_4_sides(char **map, t_map *s_map)
{
    if (!ft_check_left_wall(map, &s_map->map_checker)){
        printf("Left wall not valid\n");
        return (0);
    }
    if (!ft_check_top_wall(map,s_map->max_x, &s_map->map_checker)){
        printf("Top wall not valid\n");
        return (0);
    }
    if (!ft_check_right_wall(map, &s_map->map_checker)){
        printf("Right wall not valid\n");
        return (0);
    }
    if (!ft_check_bottom_wall(s_map->play_map, s_map->max_x, &s_map->map_checker)){
        printf("Bottom wall not valid\n");
        return (0);
    }
    return (1);
}

int	ft_check_map(t_map *struc_map)
{
    if (!check_4_sides(struc_map->play_map, struc_map)) {
        printf("all walls are NOT made of 1\n");
        return (0);
    }
    if (!check_4_sides_holes(struc_map->play_map, struc_map)){
        printf("wall holes are NOT made of 1\n");
        return (0);
    }
    printf("closed wall\n");
    return (1);
}
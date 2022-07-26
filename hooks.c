#include "cub3d.h"

/*
    printf("game.y = %d\n", game->y);
    printf("game.y vector = %d\n", game->y/ TILE_SIZE);
    printf("game.x = %d\n", game->x);
    printf("game.x vector = %d\n", game->x/ TILE_SIZE);
    printf("next tile value = %c\n", map->play_map[(game->y - 86) / TILE_SIZE][game->x / TILE_SIZE]);
 */

long long	ft_time(void)
{
    struct timeval	te;

    gettimeofday(&te, NULL);
    return (te.tv_sec * 1000 + te.tv_usec / 1000);
}

void	ft_move_r(t_vector *game, t_map *map)
{
    if (map->play_map[(game->y) / TILE_SIZE][(game->x + 64) / TILE_SIZE] != '1')
        game->x += 16;

}

void	ft_move_l(t_vector *game, t_map *map)
{
    if (map->play_map[(game->y) / TILE_SIZE][(game->x - 64) / TILE_SIZE] != '1')
        game->x -= 16;
}

void	ft_move_up(t_vector *game, t_map *map)
{
//    double oldTime;
//    double time;
//    double frameTime;
//    double moveSpeed;
//    time = ft_time();
//    oldTime = time;
//    frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
//    moveSpeed = frameTime * 5.0; //the constant value is in squares/second
//    printf("time = %f\n", time);
//    printf("frameTime = %f\n", frameTime);
//    printf("movespeed = %f\n", moveSpeed);
    if (map->play_map[(game->y - 64) / TILE_SIZE][game->x / TILE_SIZE] != '1')
	    game->y -= (16);
}

void	ft_move_d(t_vector *game, t_map *map)
{
    if (map->play_map[(game->y + 64) / TILE_SIZE][game->x / TILE_SIZE] != '1')
        game->y += 16;
}

void    ft_move(int key, t_map *map)
{
    if (key == 2) {
        ft_move_r(&map->player, map);
    }
    else if (key == 0) {
        ft_move_l(&map->player, map);
    }
    else if (key == 13) {
        ft_move_up(&map->player, map);
    }
    else {
        ft_move_d(&map->player, map);
    }
}

void    ft_camera(int key, t_map *map)
{
    if (key == 123) // look on the left
    {
        map->player.angle += 10;
        if (map->player.angle == 360)
            map->player.angle +=  0;
        if (map->player.angle > 360)
            map->player.angle -=  360;
    }
    else if (key == 124) // look on the right
    {
        map->player.angle -=10;
        if (map->player.angle < 0)
            map->player.angle += 360;
        if (map->player.angle > 360)
            map->player.angle -=  360;
    }
    else
        exit(0);
}

int	ft_input(int key, void *param)
{
    t_map		*map;

    map = (t_map *)param;
    printf("angle == %f\n", map->player.angle);
    printf("key = %d\n", key);
    if (key == 2 || key == 0 || key == 13 || key == 1)
        ft_move(key, map);
    else if (key == 123 || key == 124 || key == 53)
        ft_camera(key, map);
    else
        return (0);
    printf("angle == %f\n", map->player.angle);
//	mlx_clear_window(map->winp.mlx, map->winp.win);
	draw_map(&map->winp, map);
    return (0);
}
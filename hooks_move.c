#include "cub3d.h"

void	ft_move_r(t_vector *game, t_map *map)
{
    float temp;
    int neg = 1;

    temp = map->player.angle / 90;
    if(temp > 1 && temp < 2)
        neg = -1;
    if(temp > 3 && temp < 4)
        neg = -1;
    temp = temp - floorf(temp);
    if (neg == -1)
        temp -=1;
    if(temp == 0 && (map->player.angle == 90 || map->player.angle == 270))
        temp = 1;
    if (map->play_map[(int)(game->y + 16 * temp) / TILE_SIZE][(int)(game->x + 16 * temp) / TILE_SIZE] != '1')
    {
        if(map->player.angle > 90 && map->player.angle <= 270)
        {
            game->x -= temp * 16;
            game->y -= 16 - fabs(temp * 16);
        }
        else
        {
            game->x += temp * 16;
            game->y += 16 - fabs(temp * 16);
        }

    }
}

void	ft_move_l(t_vector *game, t_map *map)
{
    float temp;
    int neg = 1;

    temp = map->player.angle / 90;
    if(temp > 1 && temp < 2)
        neg = -1;
    if(temp > 3 && temp < 4)
        neg = -1;
    temp = temp - floorf(temp);
    if (neg == -1)
        temp -=1;
    if(temp == 0 && (map->player.angle == 90 || map->player.angle == 270))
        temp = 1;
    if (map->play_map[(int)(game->y + 16 * temp) / TILE_SIZE][(int)(game->x + 16 * temp) / TILE_SIZE] != '1')
    {
        if ((map->player.angle > 90 && map->player.angle <= 270))
        {
            game->x += temp * 16;
            game->y += 16 - fabs(temp * 16);
        }
        else
        {
            game->x -= temp * 16;
            game->y -= 16 - fabs(temp * 16);
        }
    }
}

void	ft_move_up(t_vector *game, t_map *map)
{
    float temp;
    int neg = 1;

    temp = map->player.angle / 90;
    if(temp < 1)
        neg = -1;
    if (temp < 3 && temp > 2)
        neg = -1;
    temp = temp - floorf(temp);
    if (neg == -1)
        temp -=1;
    if(temp == 0 && map->player.angle != 90 && map->player.angle != 270)
        temp = 1;
    if (map->play_map[(int)(game->y + 16 * temp) / TILE_SIZE][(int)(game->x + 16 * temp) / TILE_SIZE] != '1')
    {
        if(map->player.angle <= 180.001)
        {
            game->x -= temp * 16;
            game->y -= 16 - fabs(temp * 16);
        }
        else
        {
            game->x += temp * 16;
            game->y += 16 - fabs(temp * 16);
        }
    }
}

void	ft_move_d(t_vector *game, t_map *map)
{
    float temp;
    int neg = 1;

    temp = map->player.angle / 90;
    if(temp < 1)
        neg = -1;
    if (temp < 3 && temp > 2)
        neg = -1;
    temp = temp - floorf(temp);
    if (neg == -1)
        temp -=1;
    if(temp == 0 && map->player.angle != 90 && map->player.angle != 270)
        temp = 1;
    if (map->play_map[(int)(game->y + 32 * temp) / TILE_SIZE][(int)(game->x + 32 * temp) / TILE_SIZE] != '1')
    {
        if(map->player.angle <= 180.001)
        {
            game->x += temp * 16;
            game->y += 16 - fabs(temp * 16);
        }
        else
        {
            game->x -= temp * 16;
            game->y -= 16 - fabs(temp * 16);
        }
    }
}

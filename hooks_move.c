#include "cub3d.h"

void	ft_move_r(t_vector *game, t_map *map)
{
	float temp;
	int neg = 1;
	int x_c  = game->x;
	int y_c = game->y;
	
	
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
	
	if ((map->player.angle > 90 && map->player.angle <= 270))
	{
		x_c -= temp * 16;
		y_c -= 16 - fabs(temp * 16);
		if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[game->y / 64][(game->x - 17) /64] != '1')
		{	game->x = x_c;
			game->y = y_c;}
		
	}
	else
	{
		x_c += temp * 16;
		y_c += 16 - fabs(temp * 16);
		if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[game->y / 64][(game->x + 17) /64] != '1')
		{	game->x = x_c;
			game->y = y_c;}
	}
}

void	ft_move_l(t_vector *game, t_map *map)
{
    float temp;
    int neg = 1;
	int x_c  = game->x;
	int y_c = game->y;
	
	
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

        if ((map->player.angle > 90 && map->player.angle <= 270))
        {
            x_c += temp * 16;
            y_c += 16 - fabs(temp * 16);
			if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[game->y / 64][(game->x - 17) /64] != '1')
			{	game->x = x_c;
				game->y = y_c;}
	
		}
        else
        {
            x_c -= temp * 16;
            y_c -= 16 - fabs(temp * 16);
			if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[game->y / 64][(game->x - 17) /64] != '1')
			{	game->x = x_c;
				game->y = y_c;}
        }
}

void	ft_move_up(t_vector *game, t_map *map)
{
    float	temp;
    int neg	= 1;
	int x_c  = game->x;
	int y_c = game->y;

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
        if(map->player.angle <= 180.001)
        {
			
			x_c -= temp * 16;
            y_c -= 16 - fabs(temp * 16);
				if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[(game->y - 17) / 64][game->x /64] != '1')
				{	game->x = x_c;
				game->y = y_c;}
        }
        else
        {
			x_c += temp * 16;
			y_c += 16 - fabs(temp * 16);
			if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[(game->y + 17) / 64][game->x /64] != '1')
			{	game->x = x_c;
				game->y = y_c;}
}}

void	ft_move_d(t_vector *game, t_map *map)
{
    float temp;
    int neg = 1;
	int x_c  = game->x;
	int y_c = game->y;

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
    
        if(map->player.angle <= 180.001)
        {
            x_c += temp * 16;
            y_c += 16 - fabs(temp * 16);
			if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[(game->y + 17) / 64][game->x /64] != '1')
			{
				game->x = x_c;
				game->y = y_c;}
        }
        else
        {
			x_c -= temp * 16;
			y_c -= 16 - fabs(temp * 16);
			if (map->play_map[y_c / 64][x_c / 64] != '1' && map->play_map[(game->y - 17) / 64][game->x /64] != '1')
			{	game->x = x_c;
				game->y = y_c;}
        }
    
}

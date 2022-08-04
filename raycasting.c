#include "cub3d.h"

int	check_inbound(t_map map, t_intersection inter)
{
	if (inter.hitx < 0 || inter.hity < 0)
		return (0);
	if (inter.hity / 64 > map.max_y || inter.hitx / 64 > map.max_x)
		return (0);
	return (1);
}

float	wall_find(t_map map, t_intersection inter, t_wall *wall)
{
	if (check_inbound(map, inter))
	{
		while (map.play_map[(int)inter.hity / TILE_SIZE][(int)inter.hitx / TILE_SIZE] != '1')
		{
			inter.hity += inter.delta_y;
			inter.hitx += inter.delta_x;
			if (!check_inbound(map, inter))
				return (-1);
		}
		if (wall->color == 1)
			wall->color = (int)inter.hity % 64;
		else
			wall->h = (int)inter.hitx % 64;
		return (sqrt(pow(map.player.x - inter.hitx, 2) + pow(map.player.y - inter.hity, 2)));
	}
	return (-1);
}

float	find_vert_wall(t_map map, t_wall *wall)
{
	t_intersection	inter;

	wall->color = 1;
	if (map.player.angle < 90 || map.player.angle > 270)
	{
		inter.hitx = ((int)((map.player.x / 64) * TILE_SIZE)) + TILE_SIZE;
		inter.hity = map.player.y + ((map.player.x - inter.hitx) * tan_degrees(map.player.angle));
		inter.delta_x = 64;
		inter.delta_y = 64 * fabs(tan_degrees(map.player.angle));
		if (map.player.angle < 90)
			inter.delta_y *= -1;
	}
	else
	{
		inter.hitx = ((int)((map.player.x / TILE_SIZE) * TILE_SIZE)) - 0.001;
		inter.hity = map.player.y + ((inter.hitx - map.player.x) * -1 * tan_degrees(map.player.angle));
		inter.delta_x = -64;
		inter.delta_y = 64 * tan_degrees(map.player.angle);
	}
	return (wall_find(map, inter, wall));
}

float	find_hor_wall(t_map map, t_wall *wall)
{
	t_intersection	inter;

	if (map.player.angle < 180)
	{
		inter.hity = (int)((map.player.y / TILE_SIZE) * TILE_SIZE) - 0.01;
		inter.hitx = map.player.x + (map.player.y - inter.hity)
			/ tan_degrees(map.player.angle);
		inter.delta_y = -64;
		inter.delta_x = 64 / tan_degrees(map.player.angle);
	}
	else
	{
		inter.hity = ((int)((map.player.y / 64) * TILE_SIZE)) + TILE_SIZE;
		inter.hitx = map.player.x + -1 * ((inter.hity - map.player.y)
				/ tan_degrees(map.player.angle));
		inter.delta_y = 64;
		inter.delta_x = inter.delta_y / tan_degrees(map.player.angle);
		inter.delta_x *= -1;
	}
	return (wall_find(map, inter, wall));
}

t_wall	*find_wall_distance(t_map map, float cos)
{
	t_wall			*wall;
	float			horizontal_dist;
	float			vertical_dist;

	wall = malloc(sizeof(t_wall));
	wall->color = 0;
	horizontal_dist = find_hor_wall(map, wall);
	vertical_dist = find_vert_wall(map, wall);
	if ((vertical_dist < horizontal_dist && vertical_dist > 0) || horizontal_dist < 0)
	{
		vertical_dist *= cos_degrees(cos);
		wall->heigth = (TILE_SIZE / vertical_dist * PROJ_DIST);
		wall->wall_top = (WINDOW_H / 2) - (wall->heigth / 2);
		if (map.player.angle < 270 && map.player.angle > 90)
			wall->direction = 4;
		else
			wall->direction = 2;
	}
	else {
		horizontal_dist *= cos_degrees(cos);
		wall->heigth = (TILE_SIZE / horizontal_dist * PROJ_DIST);
		wall->wall_top = (WINDOW_H / 2) - (wall->heigth / 2);
		if (map.player.angle > 180)
			wall->direction = 3;
		else
			wall->direction = 1;
		wall->color = wall->h;
	}
	return (wall);
}

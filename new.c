//
// Created by Leonard Gaillard on 7/11/22.
//
#include "cub3d.h"

t_wall find_wall_distance(t_map map, float cos)
{
	t_wall			wall;
	t_intersection	intersection;
	float 	horizontal_distance;
	float 	vertical_distance;
	//maybe abs value on tan when calculating deltal;
	//hor_wall looking up
	if (map.player.angle == 180 || map.player.angle == 90 || map.player.angle == 270 || map.player.angle == 0)
		map.player.angle += 0.001;
	if (map.player.angle > 0 && map.player.angle < 180)
	{
		intersection.wall_hity = ((int)((map.player.y / TILE_SIZE) * TILE_SIZE)) - 0.001;
		intersection.wall_hitx = map.player.x - ((map.player.y - intersection.wall_hity) / tan_degrees(map.player.angle));
		intersection.delta_y = -64
		intersection.delta_x = intersection.delta_y / tan_degrees(map.player.angle);
	}
	// hor wall looking down
	else if (map.player.angle > 180)
	{
		intersection.wall_hity = ((int)((map.player.y / 64) * TILE_SIZE)) + TILE_SIZE;
		intersection.wall_hitx = map.player.x - ((intersection.wall_hity - map.player.y) * tan_degrees(map.player.angle));
		intersection.delta_y = 64;
		intersection.delta_x = intersection.delta_y / tan_degrees(map.player.angle);
	}
	while(map.play_map[(int)wall_hit_y / TILE_SIZE][(int)wall_hit_x / TILE_SIZE] != 1)
	{
		intersection.wall_hity += intersection.delta_y
		intersection.wall_hitx += intersection.delta_x
	}
	//what if no wall found ??
	horizontal_distance = sqrt(pow(map.player.x - intersection.wall_hitx, 2) + pow(map.player.y - intersection.wall_hity, 2));
	// vert wal looking rigth
	if(map.player.angle < 90 || map.player.angle > 270)
	{
		intersection.wall_hitx = ((int)((map.player.x / 64) * TILE_SIZE)) + TILE_SIZE;
		intersection.wall_hity = map.player.y + ((intersection.wall_hitx - map.player.x) * fabs(tan_degrees(map.player.angle)));
		intersection.delta_x = 64;
		intersection.delta_y = intersection.delta_x * fabs(tan_degrees(map.player.angle));
	}
	else if (map.player.angle < 270|| map.player.angle > 90)
	{
		intersection.wall_hitx = ((int)((map.player.x / TILE_SIZE) * TILE_SIZE)) - 0.001;
		intersection.wall_hity = (map.player.x - intersection.wall_hitx) / tan_degrees(map.player.angle);
		intersection.delta_x = -64;
		intersection.delta_y = intersection.delta_x * fabs(tan_degrees(map.player.angle));
	}
	while(map.play_map[(int)wall_hit_y / TILE_SIZE][(int)wall_hit_x / TILE_SIZE] != 1)
	{
		intersection.wall_hity += intersection.delta_y
		intersection.wall_hitx += intersection.delta_x
	}
	vertical_distance = sqrt(pow(map.player.x - intersection.wall_hitx, 2) + pow(map.player.y - intersection.wall_hity, 2));
	if (vertical_distance < horizontal_distance)
	{
		vertical_distance *= cos_degrees(cos);
		wall.heigth = (TILE_SIZE / vertical_distance * PROJ_DIST);
		wall.wall_top = (WINDOW_H / 2) - (wall.heigth / 2);
		wall.color = 0x0000FF;
		wall.direction = -1;
		return (wall);
	}
	else
	{
		horizontal_distance *= cos_degrees(cos);
		wall.heigth = (TILE_SIZE / horizontal_distance * PROJ_DIST);
		wall.wall_top = (WINDOW_H / 2) - (wall.heigth / 2);
		wall.color = 0x00FF00;
		wall.direction = 1;
		return (wall);
	}
}
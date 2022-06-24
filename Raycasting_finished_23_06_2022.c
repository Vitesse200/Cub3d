//
// Created by Leonard Gaillard on 6/23/22.
//
#include "cub3d.h"

//calcule la plus courte distance jusqu'a un mur
// to maybe do : change tan to atan so we can multiply instead of dividing
t_wall find_wall_distance(t_map map, float cos)
{
	//horizontal wall
	float	wall_hit_x;
	float	wall_hit_y;
	float 	delta_x;
	float	delta_y;
	float 	horizontal_distance;
	float 	vertical_distance;
	t_wall	wall;
	//looking up
	horizontal_distance = 0;
	delta_y = TILE_SIZE;
	wall_hit_y = 0;
	wall_hit_x = 0;
	delta_x = 0;
	delta_y = 0;
	if (map.player.angle > 0 && map.player.angle < 180)
	{
		wall_hit_y = ((int)(map.player.y / TILE_SIZE) * TILE_SIZE) - 0.001;
		wall_hit_x = (map.player.y - wall_hit_y) / tan_degrees(map.player.angle) + map.player.x; //maybe -posx instead
		delta_y = -64;
		delta_x = delta_y / tan_degrees(map.player.angle);
	}
	// looking down
	else if (map.player.angle != 0 && map.player.angle > 180)
	{
		wall_hit_y = ((int)(map.player.y / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		wall_hit_x = (map.player.y - wall_hit_y) / tan_degrees(map.player.angle) + map.player.x; //maybe -posx instead
		delta_y = +64;
		delta_x = delta_y / tan_degrees(map.player.angle);
	}
	else
		horizontal_distance = 10000000;
	while(map.play_map[(int)wall_hit_y / TILE_SIZE][(int)wall_hit_x / TILE_SIZE] != 1 && (wall_hit_y / TILE_SIZE) < map.max_y && (wall_hit_x / TILE_SIZE) < map.max_x
	&& wall_hit_y / TILE_SIZE > 0 && wall_hit_x / TILE_SIZE > 0 && horizontal_distance == 0)
	{
		if(map.play_map[(int)wall_hit_y / TILE_SIZE][(int)wall_hit_x / TILE_SIZE])
			horizontal_distance = sqrt(pow(map.player.x - wall_hit_x, 2) + pow(map.player.y - wall_hit_y, 2));
		wall_hit_y += delta_y;
		wall_hit_x += delta_x;
	}
	//vertical wall
	vertical_distance = 0;
	//looking right
	if(map.player.angle < 90 || map.player.angle > 270)
	{
		wall_hit_x = ((int)(map.player.x / TILE_SIZE) * TILE_SIZE) + TILE_SIZE;
		wall_hit_y = (map.player.x - wall_hit_x) / (-1 * tan_degrees(map.player.angle)) + map.player.y; //maybe -posx instead
		delta_x = +64;
		delta_y = delta_x / (-1 * tan_degrees(map.player.angle));
	}
	//looking left
	else if (map.player.angle < 270|| map.player.angle > 90)
	{
		wall_hit_x = ((int)(map.player.x / TILE_SIZE) * TILE_SIZE) - 0.001;
		wall_hit_y = (map.player.x - wall_hit_x) / (-1 * tan_degrees(map.player.angle)) + map.player.y; //maybe -posx instead
		delta_x = -64;
		delta_y = delta_x / (-1 * tan_degrees(map.player.angle));
	}
	else
		vertical_distance = 10000000;
	while(map.play_map[(int)wall_hit_y / TILE_SIZE][(int)wall_hit_x / TILE_SIZE] != 1 && (wall_hit_y / TILE_SIZE) < map.max_y && (wall_hit_x / TILE_SIZE) < map.max_x
		  && wall_hit_y / TILE_SIZE > 0 && wall_hit_x / TILE_SIZE > 0 && vertical_distance == 0)
	{
		if(map.play_map[(int)wall_hit_y / TILE_SIZE][(int)wall_hit_x / TILE_SIZE])
		vertical_distance = sqrt(pow(map.player.x - wall_hit_x, 2) + pow(map.player.y - wall_hit_y, 2));
		wall_hit_y += delta_y;
		wall_hit_x += delta_x;
	}
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

void	draw_map(t_winp win, t_map *map)
{
	int		ray;
	t_wall	wall;
	float	cos;
	t_data	img;
	
	ray = 0;
	cos = -30;
	map->player.angle +=30;
	img.img = mlx_new_image(win.mlx, 1, WINDOW_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (ray < WINDOW_W)
	{
		wall = find_wall_distance(*map, cos);
		img_put(win, ray, wall, img);
		map->player.angle -= ANGLE_DIFF;
		cos += ANGLE_DIFF;
		ray++;
	}
}

void	window_manager(t_map *map)
{
	t_winp	winp;
	
	winp.mlx = mlx_init();
	winp.win = mlx_new_window(winp.mlx,WINDOW_W, WINDOW_H,"Cub3d");
	map->winp = winp;
	draw_map(winp, map);
	mlx_hook(winp.win, 17, 0, &ft_close, 0);
	mlx_key_hook(winp.win, *ft_input, map);
	mlx_loop(winp.mlx);
	if (winp.win == NULL)
		exit(0);
}

double tan_degrees(double angle)
{
	angle = angle * (M_PI / 180);
	angle = tan(angle);
	return (angle);
}
double cos_degrees(double angle)
{
	angle = angle * (M_PI / 180);
	angle = cos(angle);
	return (angle);
}
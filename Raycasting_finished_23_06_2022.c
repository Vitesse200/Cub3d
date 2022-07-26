//
// Created by Leonard Gaillard on 6/23/22.
//
#include "cub3d.h"

t_wall find_wall_distance(t_map map, float cos)
{
	t_wall			wall;
	t_intersection	intersection;
	float 	horizontal_distance = 1000001;
	float 	vertical_distance = 1000000;
	//maybe abs value on tan when calculating deltal;
	//hor_wall looking up
	if (map.player.angle == 180 || map.player.angle == 90 || map.player.angle == 270 || map.player.angle == 0 || map.player.angle == 360)
		map.player.angle += 0.001;
	if (map.player.angle < 180)
	{
		intersection.wall_hity = ((int)((map.player.y / TILE_SIZE) * TILE_SIZE)) - 0.001;
		intersection.wall_hitx = map.player.x + ((map.player.y - intersection.wall_hity) / tan_degrees(map.player.angle));
		intersection.delta_y = -64;
		intersection.delta_x = 64 / tan_degrees(map.player.angle);

	}
		// hor wall looking down
	else if (map.player.angle > 180)
	{
		intersection.wall_hity = ((int)((map.player.y / 64) * TILE_SIZE)) + TILE_SIZE;
		intersection.wall_hitx = map.player.x + -1 * ((intersection.wall_hity - map.player.y) / tan_degrees(map.player.angle));
		intersection.delta_y = 64;
		intersection.delta_x = intersection.delta_y / tan_degrees(map.player.angle);
		intersection.delta_x *= -1;
	}
	if (intersection.wall_hitx < 0 || intersection.wall_hity / 64 > map.max_y || intersection.wall_hity < 0)
		intersection.wall_hity = map.max_y * 64;
	if (intersection.wall_hitx / 64 > map.max_x || intersection.wall_hitx < 0)
		intersection.wall_hitx = 0;
	if (intersection.delta_x > -2000 && intersection.delta_x < 2000){
	while( map.play_map[(int)intersection.wall_hity / TILE_SIZE][(int)intersection.wall_hitx / TILE_SIZE] != '1')
	{
        //printf("%f %f\n", intersection.wall_hity, intersection.wall_hitx);
		if (intersection.wall_hitx < 0 || intersection.wall_hity / 64 > map.max_y || intersection.wall_hity < 0)
			break;
		intersection.wall_hity += intersection.delta_y;
		intersection.wall_hitx += intersection.delta_x;
		if (intersection.wall_hitx < 0 || intersection.wall_hity / 64 > map.max_y || intersection.wall_hity < 0)
			break;
		if (intersection.wall_hitx / 64 > map.max_x)
			break;
	}}
	//what if no wall found ??
	horizontal_distance = sqrt(pow(map.player.x - intersection.wall_hitx, 2) + pow(map.player.y - intersection.wall_hity, 2));
	if (map.player.angle < 180)
		wall.color = 0xF0F0F0;
	else
		wall.color = 0x00FFA0;
	if((int)intersection.wall_hitx % 64 == 0)
		wall.color = 0x00FF00;
	// vert wal looking rigth
	if(map.player.angle < 90 || map.player.angle > 270)
	{
		intersection.wall_hitx = ((int)((map.player.x / 64) * TILE_SIZE)) + TILE_SIZE;
		intersection.wall_hity = map.player.y + ((map.player.x - intersection.wall_hitx) * tan_degrees(map.player.angle));
		intersection.delta_x = 64;
		intersection.delta_y = 64 * fabs(tan_degrees(map.player.angle));
		if (map.player.angle < 90)
			intersection.delta_y *= -1;
	}
	else if (map.player.angle < 270 || map.player.angle > 90)
	{
		intersection.wall_hitx = ((int)((map.player.x / TILE_SIZE) * TILE_SIZE)) - 0.001;
		intersection.wall_hity = map.player.y + ((intersection.wall_hitx- map.player.x) * -1 * tan_degrees(map.player.angle));
		intersection.delta_x = -64;
		intersection.delta_y = 64 * tan_degrees(map.player.angle);
	}
	if (intersection.wall_hitx < 0 || intersection.wall_hity / 64 > map.max_y || intersection.wall_hity < 0)
		intersection.wall_hity = 0;
	if (intersection.wall_hitx / 64 > map.max_x)
		intersection.wall_hitx = map.max_x * 64;
	while(map.play_map[(int)intersection.wall_hity / TILE_SIZE][(int)intersection.wall_hitx / TILE_SIZE] != '1')
	{
		intersection.wall_hity += intersection.delta_y;
		intersection.wall_hitx += intersection.delta_x;
		if (intersection.wall_hitx < 0 || intersection.wall_hity / 64 > map.max_y || intersection.wall_hity < 0)
			break;
		if (intersection.wall_hitx / 64 > map.max_x)
			break;
	}
		vertical_distance = sqrt(pow(map.player.x - intersection.wall_hitx, 2) + pow(map.player.y - intersection.wall_hity, 2));
	if (vertical_distance < horizontal_distance)
	{
		vertical_distance *= cos_degrees(cos);
		wall.heigth = (TILE_SIZE / vertical_distance * PROJ_DIST);
		wall.wall_top = (WINDOW_H / 2) - (wall.heigth / 2);
		if (map.player.angle > 90 && map.player.angle < 270)
			wall.color = 0x0000FF;
		else
			wall.color = 0xA000FF;
		if((int)intersection.wall_hity  % 64 == 0)
			wall.color = 0x00FF00;
		return (wall);
	}
	else
	{
		horizontal_distance *= cos_degrees(cos);
		wall.heigth = (TILE_SIZE / horizontal_distance * PROJ_DIST);
		wall.wall_top = (WINDOW_H / 2) - (wall.heigth / 2);

		return (wall);
	}
}

void	draw_map(t_winp *win, t_map *map)
{
	int		ray;
	t_wall	wall;
	float	cos;
	t_data	img;
	
	ray = 0;
	cos = -30;
	map->player.angle +=30;
	if(map->player.angle > 360)
		map->player.angle -= 360;
	img.img = mlx_new_image(map->winp.mlx, WINDOW_W, WINDOW_H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								 &img.endian);
	while (ray < WINDOW_W)
	{
		
		wall = find_wall_distance(*map, cos);
		if (wall.wall_top < 0)
			wall.wall_top = 0;
		img_put(win, ray, &wall, &img);
		map->player.angle -= ANGLE_DIFF;
		if (map->player.angle < 0)
			map->player.angle +=360;
		cos += ANGLE_DIFF;
		ray++;
	}
	map->player.angle +=30;
}

void	window_manager(t_map *map)
{
	//t_winp	winp;
//	winp.mlx = mlx_init();
//	winp.win = mlx_new_window(winp.mlx,WINDOW_W, WINDOW_H,"Cub3d");
//	map->winp = winp;
	draw_map(&map->winp, map);
	mlx_hook(map->winp.win, 17, 0, &ft_close, 0);
	mlx_key_hook(map->winp.win, *ft_input, map);
	mlx_loop(map->winp.mlx);
	if (map->winp.win == NULL)
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
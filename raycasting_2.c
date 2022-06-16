#include "cub3d.h"
//char **init_map()
//{
//	char **map;
//	int i = 0;
//
//	map = malloc(sizeof(char *) * 6);
//	while (i < 6) {
//		map[i] = malloc(sizeof(char) * 6);
//		i++;
//	}
//	i = 0;
//	while (i < 6)
//	{
//		map[0][i] = '1';
//		map[5][i] = '1';
//		i++;
//	}
//	i = 1;
//	while (i < 5)
//	{
//		map[i][0] = '1';
//		map[i][i] = '0';
//		map[i][5] = '1';
//		i++;
//	}
//	map[3][3] = '1';
//	return(map);
//}

double find_close_wall(char **map, int x, int y, double angle)
{
	double wall_distance;
	double wall_heigth;
	
	if (find_first_hor(map, x, y, angle) > find_first_vert(map, x, y , angle))
	{
		wall_distance = find_first_vert(map, x, y, angle);
		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
		return (wall_heigth);
	}
	else
	{
		wall_distance = find_first_hor(map, x, y , angle);
		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
		return (wall_heigth);
	}
}

double find_first_hor(char **map, int posx, int posy, double angle)
{
	//if up
	double grid_hit_x;
	double grid_hit_y;
	
	posx = posx * TILE_SIZE + (TILE_SIZE / 2);
	posy = posy * TILE_SIZE + (TILE_SIZE / 2);
	grid_hit_x = posy / TILE_SIZE * TILE_SIZE - 1;
	grid_hit_y = posx + ((posy - grid_hit_x) / fabs(tan_degrees(angle)));
	while (map[(int)grid_hit_x / TILE_SIZE][(int)grid_hit_y / TILE_SIZE] != '1')
	{
		grid_hit_y -= TILE_SIZE;
		grid_hit_x += TILE_SIZE / fabs(tan_degrees(angle));
	}
	return (sqrt(pow(posx - grid_hit_x, 2) + pow(posy - grid_hit_y, 2)));
}
double find_first_vert(char **map, int posx, int posy, double angle)
{
	//if right
	double grid_hit_x;
	double grid_hit_y;
	
	posx = posx * TILE_SIZE + (TILE_SIZE / 2);
	posy = posy * TILE_SIZE + (TILE_SIZE / 2);
	if(angle < 90) {
		grid_hit_x = posx / TILE_SIZE * TILE_SIZE + TILE_SIZE;
		grid_hit_y = posy + ((grid_hit_x - posx) * fabs(tan_degrees(angle)));
	}
	else if (angle > 90)
	{
		grid_hit_x = posx / TILE_SIZE * TILE_SIZE - 1;
		grid_hit_y = posy + ((grid_hit_x - posx) * fabs(tan_degrees(angle)));
	}
	else {
		grid_hit_x = posx;
		grid_hit_y = posy;
	}
	while (map[(int)grid_hit_x / TILE_SIZE][(int)grid_hit_y / TILE_SIZE] != '1')
	{
		if (angle != 90) {
			grid_hit_x += TILE_SIZE;
			grid_hit_y -= TILE_SIZE * fabs(tan_degrees(angle));
		}
		else
		{
			grid_hit_x += TILE_SIZE;
			grid_hit_y -= TILE_SIZE;
		}
		if (grid_hit_y < 0)
			grid_hit_y = 0;
	}
	return (sqrt(pow(posx - grid_hit_x, 2) + pow(posy - grid_hit_y, 2)));
}
double tan_degrees(double angle)
{
	angle = angle * (M_PI / 180);
	angle = tan(angle);
	return (angle);
}
int	draw_map(t_winp winp, t_map *map) {
	int i;
	int j;
	int k;
	int wall_heigth;
	int wall_top;
	double angle;
	int c = 0;
	int color = 100500;
	
	j = 0;
	i = 0;
	k = 0;
	angle = 120;
	while (i < 120) {
		wall_heigth = find_close_wall(map->play_map, map->player.x, map->player.y, angle);
		wall_top = wall_heigth / 2 - WINDOW_H / 2;
		while (c < 6) {
			while (k < wall_heigth) {
				if (wall_top > WINDOW_H)
					wall_top = 0;
				mlx_pixel_put(winp.mlx, winp.win, j, wall_top + k, color);
				k++;
			}
			k = 0;
			c++;
			j++;
		}
		color +=10;
		i++;
		angle += ANGLE_DIFF;
		printf("angle is = %f\n", angle);
		c = 0;
	}
	return (0);
}

void	window_manager(t_map *map)
	{
		t_winp	winp;
		
		winp.mlx = mlx_init();
		winp.win = mlx_new_window(winp.mlx,1920, 1200,"Cub3d");
		draw_map(winp, map);
        mlx_hook(winp.win, 17, 0, &ft_close, 0);
        mlx_key_hook(winp.win, *ft_input, map);
        mlx_loop(winp.mlx);
		if (winp.win == NULL)
			exit(0);
	}
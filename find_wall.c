#include "cub3d.h"

double find_first_hor(char **map, int posx, int posy, double angle)
{
	//if up
	double grid_hit_x;
	double grid_hit_y;
	posx = posx * TILE_SIZE + (TILE_SIZE / 2);
	posy = posy * TILE_SIZE + (TILE_SIZE / 2);
	grid_hit_y = (posy / TILE_SIZE) * TILE_SIZE - 1;
		if(angle < 90){
			grid_hit_x = posx - (posy - grid_hit_y) / tan_degrees(angle);
			while (map[(int)grid_hit_y / TILE_SIZE][(int)grid_hit_x / TILE_SIZE] != '1')
	{
		grid_hit_y -= TILE_SIZE;
		grid_hit_x += TILE_SIZE / fabs(tan_degrees(angle));
		if (grid_hit_y < 0)
			grid_hit_y = 0;
	}
	return (sqrt(pow(posx - grid_hit_x, 2) + pow(posy - grid_hit_y, 2)));}
	else
	{
		grid_hit_x = posx + (posy - grid_hit_y) / tan_degrees(angle);
		while (map[(int)grid_hit_y / TILE_SIZE][(int)grid_hit_x / TILE_SIZE] != '1')
		{
			grid_hit_y -= TILE_SIZE;
			grid_hit_x -= TILE_SIZE / fabs(tan_degrees(angle));
			if (grid_hit_y < 0)
				grid_hit_y = 0;
		}
		return (sqrt(pow(posx - grid_hit_x, 2) + pow(posy - grid_hit_y, 2)));
		
	}
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
		grid_hit_y = posy + ((posx - grid_hit_x) * fabs(tan_degrees(angle)));
	}
	else if (angle > 90)
	{
		grid_hit_x = posx / TILE_SIZE * TILE_SIZE - 1;
		grid_hit_y = posy + ((grid_hit_x - posx) * fabs(tan_degrees(angle)));
	}
	else {
		grid_hit_x = posx - TILE_SIZE / 2;
		grid_hit_y = posy - TILE_SIZE / 2;
	}
	if (grid_hit_y < 0)
		grid_hit_y = 0;
	//printf("y= %f\n x = %f\n", grid_hit_y / TILE_SIZE, grid_hit_x /TILE_SIZE);
	while (map[(int)grid_hit_y / TILE_SIZE][(int)grid_hit_x / TILE_SIZE] != '1')
	{
		if (angle != 90) {
			grid_hit_x += TILE_SIZE;
			grid_hit_y -= TILE_SIZE * fabs(tan_degrees(angle));
		}
		else
		{
			grid_hit_y -= TILE_SIZE;
		}
		if (grid_hit_y < 0)
			grid_hit_y = 0;
	}
	printf("wall vert at y%d x%d\n", (int)(grid_hit_y / TILE_SIZE), (int)(grid_hit_x / TILE_SIZE));
	return (sqrt(pow(posx - grid_hit_x, 2) + pow(posy - grid_hit_y, 2)));
}
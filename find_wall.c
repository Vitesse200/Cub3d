//#include "cub3d.h"
//
//double find_first_hor(t_map map, int i)
//{
//	//if up
//	double grid_hit_x;
//	double grid_hit_y;
//	//double wall_dist;
//	(void) i;
//	grid_hit_y = (map.player.y / TILE_SIZE) * TILE_SIZE - 0.001;
//	if (map.player.angle < 90){
//		grid_hit_x = map.player.x - (map.player.y - grid_hit_y) / tan_degrees(map.player.angle);
//		while (map.play_map[(int)(grid_hit_y / TILE_SIZE)][(int)(grid_hit_x / TILE_SIZE)] != '1')
//		{
//			grid_hit_x += TILE_SIZE / fabs(tan_degrees(map.player.angle));
//			if (map.play_map[(int)(grid_hit_y / TILE_SIZE)][(int)(grid_hit_x / TILE_SIZE)] != '1')
//			grid_hit_y -= TILE_SIZE;
//			if (grid_hit_y < 0)
//				grid_hit_y = 0;}
//	//		printf("Wall found at %d %d\n", (int)grid_hit_y / TILE_SIZE, (int)grid_hit_x / TILE_SIZE);
//	//	printf ("distance is for hor :%f\n",sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2)) );
//	//	printf("Wall found at %d %d\n", (int)grid_hit_y / TILE_SIZE, (int)grid_hit_x / TILE_SIZE);
//		//wall_dist = sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2));
//	//	wall_dist *= cos_degrees(i);
//		return (sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2)));}
//	else
//	{
//		grid_hit_x = map.player.x + (map.player.y - grid_hit_y) / tan_degrees(map.player.angle);
//		while (map.play_map[(int)(grid_hit_y / TILE_SIZE)][(int)(grid_hit_x / TILE_SIZE)] != '1')
//		{
//			grid_hit_x -= TILE_SIZE / fabs(tan_degrees(map.player.angle));
//				grid_hit_y -= TILE_SIZE;
//			if (grid_hit_y < 0)
//				grid_hit_y = 0;
//		}
//		//wall_dist =sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2));
//		//wall_dist *= cos_degrees(i);
//
//		return (sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2)));
//	}
//}
//
//
//
////
//double find_first_vert(t_map map)
//{
//	//if right
//	double grid_hit_x;
//	double grid_hit_y;
//
////	map.player.x = map.player.x * TILE_SIZE + (TILE_SIZE / 2);
////	map.player.y = map.player.y * TILE_SIZE + (TILE_SIZE / 2);
//	if(map.player.angle < 90) {
//		grid_hit_x = map.player.x /TILE_SIZE * TILE_SIZE + TILE_SIZE;
//		grid_hit_y = map.player.y + ((map.player.x - grid_hit_x) * fabs(tan_degrees(map.player.angle)));
//	}
//	else if (map.player.angle > 90)
//	{
//		grid_hit_x = map.player.x / TILE_SIZE * TILE_SIZE - 0.001;
//		grid_hit_y = map.player.y + ((grid_hit_x - map.player.x) * fabs(tan_degrees(map.player.angle)));
//		//	printf("y= %d\n x = %d\n", (int)grid_hit_y / TILE_SIZE, (int)grid_hit_x /TILE_SIZE);
//	}
//	else {
//		grid_hit_x = map.player.x - TILE_SIZE / 2;
//		grid_hit_y = map.player.y - TILE_SIZE / 2;
//	}
//	if (grid_hit_y < 0)
//		grid_hit_y = 0;
//	//printf("y= %f\n x = %f\n", grid_hit_y / TILE_SIZE, grid_hit_x /TILE_SIZE);
//	while (map.play_map[(int)(grid_hit_y / TILE_SIZE)][(int)(grid_hit_x / TILE_SIZE)] != '1')
//	{	//	printf("y= %d\n x = %d\n", (int)grid_hit_y / TILE_SIZE, (int)grid_hit_x /TILE_SIZE);
//
//		if (map.player.angle < 90) {
//			grid_hit_x += TILE_SIZE;
//			grid_hit_y -= TILE_SIZE * fabs(tan_degrees(map.player.angle));
//		}
//		else if( map.player.angle > 90){
//
//			grid_hit_x -= TILE_SIZE;
//			}
//		else
//		{
//			grid_hit_y -= TILE_SIZE;
//		}
//		if (grid_hit_y < 0)
//			grid_hit_y = 0;}
//	if (map.player.angle > 115){
//		printf("Wall vertfound at %d %d\n", (int)grid_hit_y / TILE_SIZE, (int)grid_hit_x / TILE_SIZE);
//		printf("wall vertdistance is%f\n",sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2)));
//	}
//	return (sqrt(pow(map.player.x - grid_hit_x, 2) + pow(map.player.y - grid_hit_y, 2)));
//}

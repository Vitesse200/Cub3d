#include "cub3d.h"

//t_test find_close_wall(t_map map, double i, t_test test)
//{
//	double	wall_distance_hort;
//	double	wall_distance_vert;
//
//	wall_distance_hort = find_first_hor(map, i);
//	wall_distance_vert = find_first_vert(map);
//	if (wall_distance_hort > wall_distance_vert )//|| (find_first_vert(map) - find_first_hor(map) < 5 && test.last == 1))
//	{
//		//if (angle == 120 || angle == 90 || angle == 60.1875) {
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//			printf("%f\n", cos_degrees(i));
//
//		wall_distance_vert *= cos_degrees(i);
//		test.height = TILE_SIZE / wall_distance_vert * PROJ_DIST;
//		test.color = 0x0000FF;	//	if (angle == 120 || angle == 90 || angle == 60.1875)
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		return (test);
//	}
//	else
//	{
//	//	if (angle == 120 || angle == 90 || angle == 60.1875) {
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		//	printf("%f\n", fabs(cos_degrees(i)));
//	//	}
//		wall_distance_hort *= cos_degrees(i);
//		test.height = TILE_SIZE / wall_distance_hort * PROJ_DIST;
//		test.color = 0x00FF00;
//
//		//if (angle == 120 || angle == 90 || angle == 60.1875)
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		return (test);
//	}
//}

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


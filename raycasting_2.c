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

float tan_degrees(float angle)
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
//int	draw_map(t_winp winp, t_map *map) {
//	int i;
//	t_test test;
//	double wall_top;
//	double cos;
//	t_data	img;
//
//	img.img = mlx_new_image(winp.mlx, 1, WINDOW_H);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								 &img.endian);
//	i = 0;
//	cos = -30;
//	map->player.angle += 30;
//	while (i < WINDOW_W) {
//		test = find_close_wall(*map, cos, test);
//		wall_top = (WINDOW_H * 0.5) - (test.height * 0.5);
////	//	printf("wall top is %f\n", wall_top);
////		while (c < 1) {
////			while (k < test.height)
//							if (wall_top < 0)
//								wall_top = 0;
////				while (l < wall_top) {
////					mlx_pixel_put(winp.mlx, winp.win, j, l, 0x0FFFF0);
////					l++;
////				}
//			//	mlx_pixel_put(winp.mlx, winp.win, j, k + l, test.color);
//	//			k++;
//	//		}
//	//		while (k + l < WINDOW_H)
//	//		{
//			//	mlx_pixel_put(winp.mlx, winp.win, j, k + l, 0xFF0D00);
//	//			k++;
//	//		}
//	//		l = 0;
//	//		k = 0;
//	//		c++;
//	//		j++;
//	//	}
//	//	i++;
//		map->player.angle -= ANGLE_DIFF;
//		cos += ANGLE_DIFF;
//	//	c = 0;
//	//}
//	//printf("XX%dXX\n", WINDOW_W);
//	img_put(winp, i, wall_top, test, img);
//	i++;
//	}
//
//	return (0);
//}
//
//void	window_manager(t_map *map)
//	{
//		t_winp	winp;
//
//		winp.mlx = mlx_init();
//		winp.win = mlx_new_window(winp.mlx,WINDOW_W, WINDOW_H,"Cub3d");
//		map->winp = winp;
//		draw_map(winp, map);
//        mlx_hook(winp.win, 17, 0, &ft_close, 0);
//        mlx_key_hook(winp.win, *ft_input, map);
//        mlx_loop(winp.mlx);
//		if (winp.win == NULL)
//			exit(0);
//	}
#include "cub3d.h"

//double find_close_wall(char **map, int x, int y, double angle, double i)
//{
//	double wall_distance;
//	double wall_heigth;
//
//	if (find_first_hor(map, x, y, angle) > find_first_vert(map, x, y , angle))
//	{
//		wall_distance = find_first_vert(map, x, y, angle);
////		if (angle == 120 || angle == 90 || angle == 60.1875) {
////		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
////		//	printf("%f\n", cos_degrees(i));
////		}
//		wall_distance *= cos_degrees(i);
//		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
//	//	if (angle == 120 || angle == 90 || angle == 60.1875)
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		return (wall_heigth);
//	}
//	else
//	{
//		wall_distance = find_first_hor(map, x, y , angle);
////		if (angle == 120 || angle == 90 || angle == 60.1875) {
////		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
////		//	printf("%f\n", fabs(cos_degrees(i)));
////		}
//		wall_distance *= cos_degrees(i);
//		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
//		//if (angle == 120 || angle == 90 || angle == 60.1875)
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		return (wall_heigth);
//	}
//}

t_test find_close_wall(t_map map, double i)
{
	double	wall_distance;
	t_test	test;
	if (find_first_hor(map) > find_first_vert(map))
	{
		wall_distance = find_first_vert(map);
		//if (angle == 120 || angle == 90 || angle == 60.1875) {
		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
		//	printf("%f\n", cos_degrees(i));
		
		wall_distance *= cos_degrees(i);
		test.height = TILE_SIZE / wall_distance * PROJ_DIST;
		test.color = 0x0000FF;	//	if (angle == 120 || angle == 90 || angle == 60.1875)
		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
		return (test);
	}
	else
	{
		wall_distance = find_first_hor(map);
//		if (angle == 120 || angle == 90 || angle == 60.1875) {
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		//	printf("%f\n", fabs(cos_degrees(i)));
//		}
		wall_distance *= cos_degrees(i);
		test.height = TILE_SIZE / wall_distance * PROJ_DIST;
		test.color = 0x00FF00;
		
		//if (angle == 120 || angle == 90 || angle == 60.1875)
		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
		return (test);
	}
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
int	draw_map(t_winp winp, t_map *map) {
	int i;
	int j;
	int k;
	t_test test;
	int wall_top;
	int c = 0;
	double cos;
	int l = 0;
	
	
	j = 0;
	i = 0;
	k = 0;
	cos = -30;
	map->player.angle += 30;
	while (i < WINDOW_W) {
		test = find_close_wall(*map, cos);
		wall_top = WINDOW_H / 2 - test.height / 2;
		//printf("wall top is %d\n", wall_heigth);
		while (c < 6) {
			while (k < test.height) {
				if (wall_top < 0)
					wall_top = 0;
				while (l < wall_top)
					l++;
				mlx_pixel_put(winp.mlx, winp.win, j, k + l, test.color);
				k++;
			}
			l = 0;
			k = 0;
			c++;
			j++;
		}
		i++;
		map->player.angle -= ANGLE_DIFF;
		cos += ANGLE_DIFF;
		c = 0;
		printf("angle is %f\n", map->player.angle);
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
#include "cub3d.h"

double find_close_wall(char **map, int x, int y, double angle, double i)
{
	double wall_distance;
	double wall_heigth;
	
	if (find_first_hor(map, x, y, angle) > find_first_vert(map, x, y , angle))
	{
		wall_distance = find_first_vert(map, x, y, angle);
//		if (angle == 120 || angle == 90 || angle == 60.1875) {
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		//	printf("%f\n", cos_degrees(i));
//		}
		wall_distance *= cos_degrees(i);
		wall_heigth = 200 / wall_distance * PROJ_DIST;
	//	if (angle == 120 || angle == 90 || angle == 60.1875)
		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
		return (wall_heigth);
	}
	else
	{
		wall_distance = find_first_hor(map, x, y , angle);
//		if (angle == 120 || angle == 90 || angle == 60.1875) {
//		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
//		//	printf("%f\n", fabs(cos_degrees(i)));
//		}
		wall_distance *= cos_degrees(i);
		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
		//if (angle == 120 || angle == 90 || angle == 60.1875)
		//	printf("at angle : %f wall_distance is = %f\n", angle, wall_distance);
		return (wall_heigth);
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
	int wall_heigth;
	int wall_top;
	double angle;
	int c = 0;
	int color = 100500;
	double cos;
	int l = 0;
	
	
	j = 0;
	i = 0;
	k = 0;
	cos = -30;
	angle = 120;
	while (i < 1) {
		wall_heigth = find_close_wall(map->play_map, map->player.x, map->player.y, angle, cos);
		wall_top = wall_heigth / 2 - WINDOW_H / 2;
		//printf("wall top is %d\n", wall_heigth);
		while (c < 6) {
			while (k < wall_heigth) {
				if (wall_top < 0)
					wall_top = 0;
				while (l < wall_top)
					l++;
				mlx_pixel_put(winp.mlx, winp.win, j, k + l, color);
				k++;
			}
			l = 0;
			k = 0;
			c++;
			j++;
		}
		color +=10;
		i++;
		angle -= 10;//ANGLE_DIFF;
		cos += ANGLE_DIFF;
	//	printf("angle is = %f\n", angle);
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
		mlx_loop(winp.mlx);
		if (winp.win == NULL)
			exit(0);
	}
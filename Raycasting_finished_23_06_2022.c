
#include "cub3d.h"

//void	draw_map(t_winp *win, t_map *map)
//{
//	int		ray;
//	t_wall	wall;
//	float	cos;
//	t_data	img;
//
//	ray = 0;
//	cos = -30;
//	map->player.angle +=30;
//	if(map->player.angle > 360)
//		map->player.angle -= 360;
//	img.img = mlx_new_image(map->winp.mlx, WINDOW_W, WINDOW_H);
//	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
//								 &img.endian);
//	while (ray < WINDOW_W)
//	{
//
//		wall = find_wall_distance(*map, cos);
//		if (wall.wall_top < 0)
//			wall.wall_top = 0;
//		img_put(win, ray, &wall, &img);
//		map->player.angle -= ANGLE_DIFF;
//		if (map->player.angle < 0)
//			map->player.angle +=360;
//		cos += ANGLE_DIFF;
//		ray++;
//	}
//	map->player.angle +=30;
//	if (map->player.angle > 360)
//		map->player.angle -=360;
//}

void	draw_map(t_winp *win, t_map *map)
{
    int		ray;
    t_wall	wall;
    float	cos;
    t_vector    xpm;
    int i;

    ray = 0;
    i = 0;
    cos = -30;
    map->player.angle +=30;
    xpm.x = 0;
    xpm.y = 0;
    if(map->player.angle > 360)
        map->player.angle -= 360;
    while (ray < WINDOW_W)
    {

        wall = find_wall_distance(*map, cos);
        if (i != wall.direction || wall.color == 0)
            xpm.x = 0;
        i = wall.direction;
		xpm.x = wall.color;
		if (xpm.x >= 320)
			xpm.x = 0;
        xpm.y = 0;
        img_put(win, ray, &wall, map, &xpm);
        xpm.x++;
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

double sin_degrees(double angle)
{
	angle = angle * (M_PI / 180);
	angle = sin(angle);
	return (angle);
}
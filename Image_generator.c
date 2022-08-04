#include "cub3d.h"

void	my_mlx_pixel_put(t_winp *data, int x, int y, int color)
{
	int	*dst;

	dst = NULL;
	if (y < WINDOW_H && x < WINDOW_W && x >= 0 && y >= 0)
	{
		dst = data->addr_canva + (y * (data->size_line / 4) + x);
		*dst = color;
	}
}

//t_texture	direction_texture(int dir, t_map *map)
//{
//    dst = NULL;
//    if (y < WINDOW_H && x < WINDOW_W && x >= 0 && y >= 0)
//    {
//        dst = data->addr_canva + (y * (data->size_line / 4) + x);
//        *dst = color;
//    }
//}

t_texture    direction_texture(int dir, t_map *map)
{
	if (dir == 1)
		return (*map->north);
	else if (dir == 2)
		return (*map->east);
	else if (dir == 3)
		return (*map->south);
	else
		return (*map->west);
}

void	img_put(t_winp *winp, int x, t_wall *wall, t_map *map, t_vector *xpm)
{
	int			i;
	t_texture	texture;
	float		ratio;

	i = 0;
	ratio = 0;
	if (i < wall->wall_top)
	{
		while (i < wall->wall_top)
		{
			my_mlx_pixel_put(winp, x, i, map->ceiling_rgb.int_hexa);
			i++;
		}
	}
	texture = direction_texture(wall->direction, map);
	while (wall->wall_top < wall->heigth + i)
	{
		if (wall->wall_top < WINDOW_H)
		{
			ratio = (float )texture.img_width / 64;
			wall->color = jo_pixel_color(xpm->x * ratio, xpm->y++ / (wall->heigth / texture.img_height), texture);
			my_mlx_pixel_put(winp, x, wall->wall_top, wall->color);
		}
		if (xpm->y >= wall->heigth)
			xpm->y = 0;
		wall->wall_top++;
	}
	if (wall->wall_top < WINDOW_H)
	{
		while (wall->wall_top < WINDOW_H)
		{
			my_mlx_pixel_put(winp, x, wall->wall_top, map->floor_rgb.int_hexa);
			wall->wall_top++;
		}
	}
	if (x == WINDOW_W - 1)
		mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
}

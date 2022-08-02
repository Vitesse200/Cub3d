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

int    *direction_texture(int dir, t_map *map)
{
    if (dir == 1)
        return (map->NO->addr_img);
    else if (dir == 2)
        return (map->EA->addr_img);
    else if (dir == 3)
        return (map->SO->addr_img);
    else
        return (map->WE->addr_img);
}

void	img_put(t_winp *winp, int x, t_wall *wall, t_map *map, t_vector *xpm)
{
    int i;
    int    *texture;

    i = 0;
    if (i < wall->wall_top)
    {
        while(i < wall->wall_top){
            my_mlx_pixel_put(winp, x, i, map->F_RGBhex.int_hexa);
            i++;
        }
    }
    texture = direction_texture(wall->direction, map);
    while(wall->wall_top < wall->heigth + i){
        if(wall->wall_top < WINDOW_H) {
            wall->color = jo_pixel_color(xpm->x, xpm->y++/(wall->heigth/64), texture);
            my_mlx_pixel_put(winp, x, wall->wall_top, wall->color);
        }
        if (xpm->y >= wall->heigth)
            xpm->y = 0;
        wall->wall_top++;
    }
    if (wall->wall_top < WINDOW_H)
    {
        while(wall->wall_top < WINDOW_H){
            my_mlx_pixel_put(winp, x, wall->wall_top, map->C_RGBhex.int_hexa);
            wall->wall_top++;
        }
    }
    if (x == WINDOW_W - 1)
        mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
}


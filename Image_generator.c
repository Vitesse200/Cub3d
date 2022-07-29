#include "cub3d.h"

void	my_mlx_pixel_put(t_winp *data, int x, int y, int color)
{
    int	*dst;

    dst = NULL;
    if (y < WINDOW_H && x < WINDOW_W && x >= 0 && y >= 0)
    {
        //printf("IS IN MY_MLX\n");
        dst = data->addr_canva + (y * (data->size_line / 4) + x);
        *dst = color;
    }
}


void	img_put(t_winp *winp, int x, t_wall *wall, t_map *map, t_vector *xpm)
{
    int i;

    i = 0;
    if (wall->wall_top < 0)
        wall->wall_top = 0;
    if (i < wall->wall_top)
    {
        while(i < wall->wall_top){
            my_mlx_pixel_put(winp, x, i, 0x00FF0011);
            i++;
        }
    }
    while(wall->wall_top < wall->heigth + i){
        if(wall->wall_top < WINDOW_H) {
            wall->color = jo_pixel_color(xpm->x/5, xpm->y++/5, map->NO->addr_img);
            my_mlx_pixel_put(winp, x, wall->wall_top, wall->color);
        }
        if (xpm->y >= 320)
            xpm->y = 0;
        wall->wall_top++;
    }
    if (wall->wall_top < WINDOW_H)
    {
        while(wall->wall_top < WINDOW_H){
            my_mlx_pixel_put(winp, x, wall->wall_top, 0x00FF00DD);
            wall->wall_top++;
        }
    }
    if (x == WINDOW_W - 1)
        mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
}

void	draw_map(t_winp *win, t_map *map)
{
    int		ray;
    t_wall	wall;
    float	cos;
    t_vector    xpm;
    //t_data	img;

    ray = 0;
    cos = -30;
    map->player.angle +=30;
    xpm.x = 0;
    xpm.y = 0;
    if(map->player.angle > 360)
        map->player.angle -= 360;
    while (ray < WINDOW_W)
    {

        wall = find_wall_distance(*map, cos);
        if (wall.wall_top < 0)
            wall.wall_top = 0;
        // xpm is the position of x in the xpm file
        // the position of x and y needs to be proportioned to the actual position on the tile and
        // the wall real size
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
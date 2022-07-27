#include "cub3d.h"

void    print_texture(t_winp *winp, t_texture *text, t_wall *wall)
{
    int x = 0;
    int i = 0;

    while (i < wall->wall_top)
    {
        x = 0;
        while (x < wall->wall_top)
        {
            winp->addr_canva[i * (winp->size_line / 4) + x] = text->addr_img[i * (text->size_line / 4) + x];
            x++;
            //printf("color = %d\n", color);
        }
        i++;
    }
}

int init_texture(t_winp *winp, t_texture *text)
{
    text->img_ptr = mlx_xpm_file_to_image(winp->mlx, text->path, &text->img_width, &text->img_height);
    if (!text->img_ptr)
        return(error("***issue with texture loading\n"));
    text->addr_img = (int *) mlx_get_data_addr(text->img_ptr, &text->bpp, &text->size_line, &text->endian);
//    print_texture(winp, text);
//    mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
    return (1);
}

int init_all_text(t_map *map)
{
    init_texture(&map->winp, map->NO);
    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->NO->path, map->NO->img_width, map->NO->img_height, map->NO->size_line);
    init_texture(&map->winp, map->SO);
    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->SO->path, map->SO->img_width, map->SO->img_height, map->SO->size_line);
    init_texture(&map->winp, map->EA);
    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->EA->path, map->EA->img_width, map->EA->img_height, map->EA->size_line);
    init_texture(&map->winp, map->WE);
    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->WE->path, map->WE->img_width, map->WE->img_height, map->WE->size_line);
    return (1);
}

#include "cub3d.h"

void    print_texture(t_winp *winp, t_texture *text)
{
    int x = 0;
    int i = 0;

    while (i < WINDOW_H)
    {
        x = 0;
        while (x < WINDOW_W)
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
    printf("img wid = %d, img heig = %d\n", text->img_width, text->img_height);
    text->addr_img = (int *) mlx_get_data_addr(text->img_ptr, &text->bpp, &text->size_line, &text->endian);
    //print_texture(winp, text);
    //mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
    return (1);
}

int init_all_text(t_map *map)
{
    init_texture(&map->winp, &map->NO);
    init_texture(&map->winp, &map->SO);
    init_texture(&map->winp, &map->EA);
    init_texture(&map->winp, &map->WE);
    return (1);
}

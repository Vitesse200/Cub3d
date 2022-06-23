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
//    winp->win = mlx_new_window(winp->mlx, 1920, 1080, "Cub3d");
//    text->canvas_ptr = mlx_new_image(winp->mlx, WINDOW_W, WINDOW_H);
    printf("path = %s\n", text->path);
    text->img_ptr = mlx_xpm_file_to_image(winp->mlx, text->path, &text->img_width, &text->img_height);
    if (!text->img_ptr)
        error("***issue with texture loading\n");
    printf("img wid = %d, img heig = %d\n", text->img_width, text->img_height);
    text->addr_img = (int *) mlx_get_data_addr(text->img_ptr, &text->bpp, &text->size_line, &text->endian);
//    text->addr_canva = (int *) mlx_get_data_addr(text->canvas_ptr, &text->bpp, &text->size_line_canva, &text->endian);
//    print_texture(winp, text);
//    mlx_put_image_to_window(winp->mlx, winp->win, winp->canvas_ptr, 0, 0);
    return (1);
}

int init_all_text(t_map *map)
{
    printf("path = %s\n", map->NO.path);
    init_texture(&map->winp, &map->NO);
    return (1);
}

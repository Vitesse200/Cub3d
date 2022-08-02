#include "cub3d.h"


int    jo_pixel_color(int x, int y, int *firstpixel)
{
    int    *fp;

    if (x > 64)
        x = 0;
    if (y > 64)
        y = 0;
    fp = firstpixel;
    return (fp[y * 64 + x]);
}

int init_texture(t_winp *winp, t_texture *text)
{
    text->img_ptr = mlx_xpm_file_to_image(winp->mlx, text->path, &text->img_width, &text->img_height);
    if (!text->img_ptr)
        return(error("***issue with texture loading\n"));
    text->addr_img = (int*)mlx_get_data_addr(text->img_ptr, &text->bpp, &text->size_line, &text->endian);
    return (1);
}

int init_all_text(t_map *map)
{
    init_texture(&map->winp, map->NO);
//    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->NO->path, map->NO->img_width, map->NO->img_height, map->NO->size_line);
    init_texture(&map->winp, map->SO);
//    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->SO->path, map->SO->img_width, map->SO->img_height, map->SO->size_line);
    init_texture(&map->winp, map->EA);
//    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->EA->path, map->EA->img_width, map->EA->img_height, map->EA->size_line);
    init_texture(&map->winp, map->WE);
//    printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->WE->path, map->WE->img_width, map->WE->img_height, map->WE->size_line);
    return (1);
}

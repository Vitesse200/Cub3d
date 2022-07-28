# include "cub3d.h"


void	jo_mlx_pixel_put(t_data *back, t_vector *xpm, t_vector *pos_pix, int pixel)
{
    if (pos_pix->y > WINDOW_H || pos_pix->x > WINDOW_W)
        return ;
    back->addr[(xpm->y + pos_pix->y) * (back->line_length / 4) + (xpm->x + pos_pix->x)] = pixel;
}

int    jo_pixel_color(int x, int y, int *firstpixel)
{
    int    *fp;

    fp = firstpixel;
    return (fp[y * 64 + x]);
}

void    jo_print_texture(t_map *map)
{
    //char        *path = "./cub3d_pics/bluestone.xpm";
    int pixel;
    t_data      data;
    t_data back;
    t_vector pos_pix;
    t_vector xpm;

    // initialise window
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, WINDOW_W, WINDOW_H, "my_cub3D");
    // get the texture
    data.img = mlx_xpm_file_to_image(data.mlx, map->NO->path, &data.img_width, &data.img_height);
    data.addr = (int *) mlx_get_data_addr(data.img, &data.bpp, &data.line_length,
                                          &data.endian);
    // print the empty canvas
    back.img = mlx_new_image(data.mlx, WINDOW_W, WINDOW_H);
    back.addr = (int *) mlx_get_data_addr(back.img, &back.bpp, &back.line_length,
                                          &back.endian);
    // get the pixels and save in addr[]
    pos_pix.x = 0;
    pos_pix.y = 0;
    while (pos_pix.x < WINDOW_W) {
        printf("pos_pix.x = %d\n", pos_pix.x);
        xpm.x = 0;
        while (xpm.x < 256) {
            xpm.y = 0;
            while (xpm.y < 320) {
                pixel = jo_pixel_color(xpm.x / 4, xpm.y / 4, data.addr);
                //                struct {
                //                    int x;
                //                    int y;
                //                } t_point;
                //                map((t_point){.x=5, .y=4})
                jo_mlx_pixel_put(&back, &xpm, &pos_pix, pixel);
                xpm.y++;
            }
            xpm.x++;
        }
        pos_pix.x += 256;
    }
    // print the pixel all at once
    mlx_put_image_to_window(data.mlx, data.mlx_win, back.img, 0, 0);
    mlx_loop(data.mlx);
}

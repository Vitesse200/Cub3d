#include "cub3d.h"

/*We need to find the wall orientation based on the player position
 *
 * ie :
 * if vert wall pos y < than player y, wall is north of player
 * if vert wall pos y > than player y, wall is south of player
 * if horz wall pos x < then player x, wall is west of player
 * if horz wall pos x > then player x, wall is east of player
 *
 *
void	my_mlx_pixel_put(t_texture *data, int x, int y, int color)
{
    int	*dst;

    dst = data->addr_canva + (y * data->size_line + x * (data->bpp / 8));
    *(unsigned int*)dst = color;
}
I need to first draw the canvas, and save the image pixel in an array, depending on distance
 * i will need to jump some pixels*/
//int 	main(void)
//{
//    t_winp	winp;
//    t_texture text;
//    //int color;
//
//    winp.mlx = mlx_init();
//    text.img = "./cub3d_pics/greystone.xpm";
//    text.width = 1920;
//    text.height = 1080;
//    winp.win = mlx_new_window(winp.mlx,1920, 1080,"Cub3d");
//    text.canvas_ptr = mlx_new_image(winp.mlx, text.width, text.height);
//    text.img_ptr = mlx_xpm_file_to_image(winp.mlx,text.img, &text.img_width, &text.img_height);
//    if (!text.img_ptr)
//        error("issue with texture loading\n");
//    text.img_height = (TILE_SIZE - text.img_height) + text.img_height;
//    text.img_width = (TILE_SIZE - text.img_width) + text.img_width;
//    text.addr_img = (int *)mlx_get_data_addr(text.img_ptr, &text.bpp, &text.size_line, &text.endian);
//    text.addr_canva = (int *)mlx_get_data_addr(text.canvas_ptr, &text.bpp, &text.size_line_canva, &text.endian);
//    int x = 0;
//    int i = 0;
//    while (i < text.height) {
//        x = 0;
//        while (x < text.width) {
//            text.addr_canva[i * (text.size_line_canva/4) + x] = text.addr_img[i * (text.size_line/4) + x];
//            x++;
//            //printf("color = %d\n", color);
//        }
//        i++;
//    }
//    i = 0;
////    while (i < 400) {
////        //my_mlx_pixel_put(&text, 64, 64, 0xFFFF00);
////        my_mlx_pixel_put(&text, 50, i, color);
////        //mlx_put_image_to_window(winp.mlx, winp.win, text.img_ptr, i, i);
////        i++;
////    }
//    mlx_put_image_to_window(winp.mlx, winp.win, text.canvas_ptr, 0, 0);
//    mlx_hook(winp.win, 17, 0, &ft_close, 0);
//    //mlx_key_hook(winp.win, *ft_input, map);
//    mlx_loop(winp.mlx);
//    if (winp.win == NULL)
//        exit(0);
//}
#include "cub3d.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	int	*dst;

//	printf("%p, %d %d\n", data->addr, x, y);
	dst = (int *)data->addr + (y * data->line_length/4) + x; /* (data->bits_per_pixel / 8));*/
	*dst = color;
}

void	img_put(t_winp *winp, int x, t_wall *wall, t_data *img)
{
	int i;
	
	i = 0;
	if (wall->wall_top < 0)
		wall->wall_top = 0;
	while(i < wall->wall_top){
		my_mlx_pixel_put(img, x, i, 0x00FF0011);
		i++;
	}
	while(wall->wall_top < wall->heigth + i){
		if(wall->wall_top < WINDOW_H)
			my_mlx_pixel_put(img, x, wall->wall_top, wall->color);
		wall->wall_top++;
	}
	while(wall->wall_top < WINDOW_H){
		my_mlx_pixel_put(img, x, wall->wall_top, 0x00FF00DD);
		wall->wall_top++;
	}
	if (x == WINDOW_W - 1)
		mlx_put_image_to_window(winp->mlx, winp->win, img->img, 0, 0);
}

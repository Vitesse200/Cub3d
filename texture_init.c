#include "cub3d.h"

int	jo_pixel_color(float x, int y, t_texture texture)
{
	int	*fp;

	if (x > texture.img_width)
		x = 0;
	if (y > texture.img_height)
		y = 0;
	fp = texture.addr_img;
	return (fp[y * texture.img_width + (int)x]);
}

int	init_texture(t_winp *winp, t_texture *text)
{
	text->img_ptr = mlx_xpm_file_to_image(winp->mlx, text->path, &text->img_width, &text->img_height);
	if (!text->img_ptr)
		return (error("***issue with texture loading\n"));
	text->addr_img = (int *)mlx_get_data_addr(text->img_ptr, &text->bpp, &text->size_line, &text->endian);
	return (1);
}

int	init_all_text(t_map *map)
{
	init_texture(&map->winp, map->north);
	printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->north->path, map->north->img_width, map->north->img_height, map->north->size_line);
	init_texture(&map->winp, map->south);
	printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->south->path, map->south->img_width, map->south->img_height, map->south->size_line);
	init_texture(&map->winp, map->east);
	printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->east->path, map->east->img_width, map->east->img_height, map->east->size_line);
	init_texture(&map->winp, map->west);
	printf("text path = %s, text width = %d, text height = %d, text line size = %d\n", map->west->path, map->west->img_width, map->west->img_height, map->west->size_line);
	return (1);
}

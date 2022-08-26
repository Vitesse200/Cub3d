/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 18:11:11 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 18:13:55 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	text->img_ptr = mlx_xpm_file_to_image(winp->mlx,
			text->path, &text->img_width, &text->img_height);
	if (!text->img_ptr)
		return (error("Texture loading issue\n"));
	text->addr_img = (int *)mlx_get_data_addr(text->img_ptr,
			&text->bpp, &text->size_line, &text->endian);
	return (1);
}

int	init_all_text(t_map *map)
{
	init_texture(&map->winp, map->north);
	init_texture(&map->winp, map->south);
	init_texture(&map->winp, map->east);
	init_texture(&map->winp, map->west);
	return (1);
}

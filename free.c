/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:41:12 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 17:42:41 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_texture(t_texture *text)
{
	free(text->path);
}

void	ft_free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
}

void	ft_free_tab(int *tab)
{
	free(tab);
}

void	ft_free_all(t_map *map)
{
	ft_free_texture((*map).north);
	ft_free_texture((*map).south);
	ft_free_texture((*map).west);
	ft_free_texture((*map).east);
	free((*map).north);
	free((*map).south);
	free((*map).east);
	free((*map).west);
	ft_free_map((*map).play_map);
}

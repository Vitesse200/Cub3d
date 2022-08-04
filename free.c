#include "cub3d.h"

void    ft_free_texture(t_texture *text)
{
    free(text->path);
    //free(text->extract);
}

void    ft_free_map(char **map)
{
    int y;

    y = 0;
    while (map[y])
    {
        free(map[y]);
        y++;
    }
    free(map);
}

void    ft_free_tab(int *tab)
{
    free(tab);
}

void    ft_free_all(t_map *map)
{
    ft_free_texture((*map).north);
    ft_free_texture((*map).south);
    ft_free_texture((*map).west);
    ft_free_texture((*map).east);
    free((*map).north);
    free((*map).south);
    free((*map).east);
    free((*map).west);
    //free(map->ceiling_rgb.rgb);
    //free(map->floor_rgb.rgb);
//    free(map->tab_ceiling);
//    free(map->tab_floor);
    ft_free_map((*map).map);
    ft_free_map((*map).play_map);
    //free(map);
}
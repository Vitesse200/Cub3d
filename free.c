#include "cub3d.h"

void	ft_free(void **ptr)
{
    if (*ptr != NULL)
        free(*ptr);
    *ptr = NULL;
}

void	ft_free_first_map(t_map *map)
{
    int	i;

    ft_free((void **)&map->NO.path);
    ft_free((void **)&map->SO.path);
    ft_free((void **)&map->EA.path);
    ft_free((void **)&map->WE.path);
    i = 0;
    while (map->map != NULL && map->map[i] != NULL)
    {
        ft_free((void **)&map->map[i]);
        i++;
    }
    ft_free((void **)&map->map);
}

void	ft_free_play_map(t_map *map)
{
    int	i;

    ft_free((void **)&map->NO.extract);
    ft_free((void **)&map->SO.extract);
    ft_free((void **)&map->EA.extract);
    ft_free((void **)&map->WE.extract);
    ft_free((void **)&map->F);
    ft_free((void **)&map->C);
    i = 0;
    while (map->play_map != NULL && map->play_map[i] != NULL)
    {
        ft_free((void **)&map->play_map[i]);
        i++;
    }
    ft_free((void **)&map->play_map);
}

int	ft_free_all(t_map *map)
{
    ft_free_first_map(map);
    ft_free_play_map(map);
    ft_free((void **)&map->orientation);
    ft_free((void **)&map->F_RGBhex.rgb);
    ft_free((void **)&map->C_RGBhex.rgb);
    ft_free((void **)&map->tab_C);
    ft_free((void **)&map->tab_F);
    exit(0);
}


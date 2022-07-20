#include "cub3d.h"

void    get_texture_path(char *extract, t_texture *text)
{
    char    *tmp;
    char    *tmp2;
    int     i;

    tmp = ft_memchr(text->extract, '.', ft_strlen(text->extract));
    tmp2 = malloc(sizeof (char) * (ft_strlen(extract)));
    i = 0;
    while ( tmp[i] != '\n')
    {
        tmp2[i] = tmp[i];
        i++;
    }
    tmp2[i] = '\0';
    text->path = tmp2;
}

int valid_text(char *path)
{
    FILE *file;
    file = fopen(path, "r");
    if (file)
        printf("FILE OK\n");
    else
        return(error("XPM FILE not OK\n"));
    return (1);
}

int ft_texture_data(t_map *map)
{
    get_texture_path(map->NO.extract, &map->NO);
    if (valid_text(map->NO.path) != 1)
        return (error("path to texture not valid\n"));
    get_texture_path(map->SO.extract, &map->SO);
    if (valid_text(map->SO.path) != 1)
        return (error("path to texture not valid\n"));
    get_texture_path(map->EA.extract, &map->EA);
    if (valid_text(map->EA.path) != 1)
        return (error("path to texture not valid\n"));
    get_texture_path(map->WE.extract, &map->WE);
    if (valid_text(map->WE.path) != 1)
        return (error("path to texture not valid\n"));
    return (1);
}

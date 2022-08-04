# include "cub3d.h"

int ft_valid_F_data(t_map *map)
{
    char    *f;
    int     i;

    f = map->floor;
    i = 0;
    while (f[i] != '\n')
    {
        if (i == 0)
        {
            if (f[i] != 'F')
                return (error("should start with F\n"));
            i++;
        }
        if (!ft_check_valid_num(f, i))
            return (0);
        i = ft_check_valid_num(f, i);
    }
    return (1);
}

int ft_valid_C_data(t_map *map)
{
    char    *c;
    int     i;

    c = map->ceiling;
    i = 0;
    while (c[i] != '\n')
    {
        if (i == 0)
        {
            if (c[i] != 'C')
                return (error("should start with C\n"));
            i++;
        }
        if (!ft_check_valid_num(c, i))
            return (0);
        i = ft_check_valid_num(c, i);
    }
    return (1);
}

int	extract_rgb(int i, char *rgb, char t, t_map *map, int count)
{
    int *tab;
    int j;

    if (t == 'f')
        tab = map->tab_floor;
    if (t == 'c')
        tab = map->tab_ceiling;
    while (rgb[++i] && count < 3)
        if (ft_isnum(rgb[i]))
        {
            j = 0;
            map->tmp = malloc(sizeof(char *));
            if (!map->tmp)
                return (0);
            while (ft_isnum(rgb[i]))
                map->tmp[j++] = rgb[i++];
            if (j < 3)
                while (j < 3)
                    map->tmp[j++] = ' ';
            tab[count++] = ft_atoi(map->tmp);
            free(map->tmp);
            map->tmp = NULL;
            tab[count] = '\0';
        }
    if (t == 'f')
        map->tab_floor = tab;
    if (t == 'c')
        map->tab_ceiling = tab;
    return (count);
}


int ft_extract_F_data(t_map *map)
{
    int     i;
    int     count;
    char    *rgb;

    rgb = map->floor;
    printf("rgb F= %s\n", rgb);
    i = -1;
    count = 0;
    map->tab_floor = malloc(sizeof(int) * 4);
    if (!map->tab_floor)
        return (0);
    count = extract_rgb(i, rgb, 'f', map, count);
    if (count != 3)
        return (error("rgb made of 3 numbers\n"));
    return (1);
}

int ft_extract_data(t_map *map)
{
    int i;
    i = 0;
    if (!ft_valid_C_data(map))
        return (0);
    if (!ft_valid_F_data(map))
        return (0);
    if (!ft_extract_C_data(map))
        return (0);
    if (!ft_extract_F_data(map))
        return (0);
    if (!ft_check_rgb(map->tab_ceiling) || !ft_check_rgb(map->tab_floor))
        return (0);
    convert_hexa(map);
    while (i < 3)
        i++;
    return (1);
}
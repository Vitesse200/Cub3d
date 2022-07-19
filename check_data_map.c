# include "cub3d.h"

int ft_valid_F_data(t_map *map)
{
    char    *f;
    int     i;

    f = map->F;
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

    c = map->C;
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

int ft_extract_rgb(int i, char *tmp, char *rgb, char t, t_map *map, int count)
{
    int *tab;
    int j;

    if (t == 'f')
        tab = map->tab_F;
    if (t == 'c')
        tab = map->tab_C;
	printf("rgb bug = %s i = %d\n", rgb, i);
    while (rgb[++i] && count < 3)
        if (ft_isnum(rgb[i]))
        {
            tmp = (char *)malloc(3 * 3);
            j = 0;
            while (ft_isnum(rgb[i]))
                tmp[j++] = rgb[i++];
            tab[count++] = ft_atoi(tmp);
            tmp = NULL;
        }
    if (t == 'f')
        map->tab_F = tab;
    if (t == 'c')
        map->tab_C = tab;
    return (count);
}


int ft_extract_F_data(t_map *map)
{
    int     i;
    int     count;
    char    *rgb;
    char    *tmp;

    rgb = map->F;
    i = -1;
    count = 0;
    tmp = NULL;
    map->tab_F = malloc(sizeof(int) * 4);
    count = ft_extract_rgb(i, tmp, rgb, 'f', map, count);
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
    if (!ft_check_rgb(map->tab_C) || !ft_check_rgb(map->tab_F))
        return (0);
    convert_hexa(map);
    while (i < 3)
    {
        printf("tabf[%d] = %d\n", i, map->tab_F[i]);
        printf("tabc[%d] = %d\n", i, map->tab_C[i]);
        i++;
    }
    printf("player pos y = %d\n", map->player.y);
    printf("player pos x = %d\n", map->player.x);
    return (1);
}
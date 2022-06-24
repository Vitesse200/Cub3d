#include "cub3d.h"

void dec2hex(int *rgbd, RGBhex *rgbh)
{
    char hexvalues[] = "0123456789ABCDEF";
    int i0;
    int i1;

    rgbh->rgb = malloc(sizeof(char) * 9);
    rgbh->rgb[0] = '0';
    rgbh->rgb[1] = 'x';
    i0 = rgbd[0] / 16;
    i1 = rgbd[0] - (16 * i0);
    rgbh->rgb[2] = hexvalues[i0];
    rgbh->rgb[3] = hexvalues[i1];
    i0 = rgbd[1] / 16;
    i1 = rgbd[1] - (16 * i0);
    rgbh->rgb[4] = hexvalues[i0];
    rgbh->rgb[5] = hexvalues[i1];
    i0 = rgbd[2] / 16;
    i1 = rgbd[2] - (16 * i0);
    rgbh->rgb[6] = hexvalues[i0];
    rgbh->rgb[7] = hexvalues[i1];
    rgbh->rgb[8] = '\0';
}

int convert_hexa(t_map *map)
{
    dec2hex(map->tab_F, &map->F_RGBhex);
    printf("***rgb F %s\n", map->F_RGBhex.rgb);
    dec2hex(map->tab_C, &map->C_RGBhex);
    printf("***rgb C %s\n", map->C_RGBhex.rgb);
    printf("angle = %d\n", map->player.angle);
    return (1);
}

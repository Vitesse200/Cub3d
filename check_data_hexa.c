#include "cub3d.h"

void dec2hex(int *rgbd, t_rgbhex *rgbh)
{
    char hexvalues[] = "0123456789ABCDEF";
    int i0;
    int i1;

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

//unsigned long createRGB(int r, int g, int b)
//{
//    return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
//}

int	color_bitshift(unsigned char a, unsigned char r, unsigned char g, unsigned char b)
{
    int RGB;

    RGB = (a << 24);
    RGB = RGB | (r << 16);
    RGB = RGB | (g << 8);
    RGB = RGB | (b);
    return (RGB);
}

int convert_hexa(t_map *map)
{
    dec2hex(map->tab_floor, &map->floor_rgb);
    printf("***rgb F %s\n", map->floor_rgb.rgb);
    map->floor_rgb.int_hexa = color_bitshift(0, map->tab_floor[0], map->tab_floor[1], map->tab_floor[2]);
    printf("***rgb Hexa F strol = %d\n", map->floor_rgb.int_hexa);
    dec2hex(map->tab_ceiling, &map->ceiling_rgb);
    printf("***rgb C %s\n", map->ceiling_rgb.rgb);
    map->ceiling_rgb.int_hexa = color_bitshift(0, map->tab_ceiling[0], map->tab_ceiling[1], map->tab_ceiling[2]);
    printf("***rgb Hexa C strol = %d\n", map->ceiling_rgb.int_hexa);
    printf("angle = %f\n", map->player.angle);
    return (1);
}

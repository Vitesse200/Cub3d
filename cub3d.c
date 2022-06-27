#include "cub3d.h"

void	ft_print_map(t_map *map)
{
	int i, j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j])
		{
			if (!ft_strcmp(&map->map[i][j], " "))
				write(1, " ", 1);
			else
				write(1, &map->map[i][j], 1);
			j++;
		}
		i++;
	}
    write(1, "\n", 1);
}

void	ft_print_player_map(char **map)
{
	int i, j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			write(1, &map[i][j], 1);
			j++;
		}
		i++;
	}
    write (1, "\n", 2);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (error("expecting 1 map as argument\n"));
	if (!ft_valid_file(argv[1]))
		return (error("expecting .cub file type\n"));
	ft_get_map(&map, argv[1]);
        if (!map.map)
            return (error("No map to extract"));
	if (!ft_extract(&map))
        return (0);
    printf("///*****/////*CUB3D*///***///****\n");
	if (!ft_check_map(&map))
		return (error("map is not valid\n"));
    if (!ft_extract_data(&map))
        return (error("Expected rgb data\n"));
	//init_all_text(&map);
	draw_map(&map.winp, &map);
//   	init_all_text(&map);
    mlx_hook(map.winp.win, 17, 0, &ft_close, 0);
    mlx_key_hook(map.winp.win, *ft_input, &map);
    mlx_loop(map.winp.mlx);
   	ft_free_all(&map);
	return (1);
}
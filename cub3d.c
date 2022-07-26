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
}

void	ft_print_player_map(char **map)
{
	int i, j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			write(1, &map[i][j], 1);
			j++;
		}
		write (1, "\n", 2);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc != 2)
		return (error("expecting 1 map as argument\n"));
	if (!ft_valid_file(argv[1]))
		return (error("expecting .cub file type\n"));
	ft_get_map(&map, argv[1]);
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
	printf("Max x = %d\n", map.max_x);
	printf("Max y = %d\n", map.max_y);
	window_manager(&map);
    printf("Max x = %d\n", map.max_x);
    printf("Max y = %d\n", map.max_y);
	return (0);
}
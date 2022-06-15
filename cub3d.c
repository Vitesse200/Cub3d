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

void	ft_print_player_map(t_map *map)
{
	int i, j;

	i = 0;
	while (map->play_map[i])
	{
		j = 0;
		while (map->play_map[i][j])
		{
			write(1, &map->play_map[i][j], 1);
			j++;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	//t_map	map;
	char	**HARD_MAP;

//	if (find_first_horizontal_wall(HARD_MAP, 2, 2) > find_first_vertical_wall(HARD_MAP, 2, 2))
//	{
//		wall_distance = find_first_vertical_wall(HARD_MAP, 2, 2);
//		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
//		printf("Closest wall is vertical\n");
//		printf("Wall distance is %f\n", wall_distance);
//		printf("Wall heigth is : %d\n", wall_heigth);
//		printf("Stard drawing at : %d	until : %d\n", (WINDOW_H / 2) + (wall_heigth / 2), ((WINDOW_H / 2) - (wall_heigth / 2)));
//	}
//	else
//	{
//		wall_distance = find_first_horizontal_wall(HARD_MAP, 2, 2);
//		wall_heigth = TILE_SIZE / wall_distance * PROJ_DIST;
//		printf("Closest wall is horizontal\n");
//		printf("Wall distance is %f\n", wall_distance);
//		printf("Wall heigth is : %d\n", wall_heigth);
//		printf("Stard drawing at : %d	until : %d\n", (WINDOW_H / 2) + (wall_heigth / 2), ((WINDOW_H / 2) - (wall_heigth / 2)));
//	}
	HARD_MAP = init_map();
	window_manager(HARD_MAP);
	if (argc != 2)
		return (error("expecting 1 map as argument\n"));
	(void ) argv;
//	if (!ft_valid_file(argv[1]))
//		return (error("expecting .cub file type\n"));
//	ft_get_map(&map, argv[1]);
//	//ft_print_map(&map);
//	ft_extract(&map);
//	if (!ft_check_map(&map))
//	{
//		// printf("NO = %s\n", map.NO);
//		// printf("SO = %s\n", map.SO);
//		// printf("WE = %s\n", map.WE);
//		// printf("EA = %s\n", map.EA);
//		// printf("F = %s\n", map.F);
//		// printf("C = %s\n", map.C);
//		return (error("map is not valid\n"));
//	}
	return (0);
}
# include "cub3d.h"

int	move_right(char **map, int y, int x)
{
	while (map[y][x+1] == '1')
	{
		map[y][x] = '2';
		x++;
	}
	return (x);
}

int	move_down(char **map, int y, int x)
{
	while (map[y+1][x] == '1')
	{
		map[y][x] = '2';
		y++;
	}
	return (y);
}

int	move_left(char **map, int y, int x)
{
	while (map[y][x-1] == '1')
		x--;
	return (x);
}


int	move_up(char **map, int y, int x)
{
	while (map[y-1][x] == '1')
		y--;
	return (y);
}

// boucle avec right / down / left / up 
// si 1 aller retour activé la case doit etre remplace par un 2

int	ft_check_top(t_map *s_map)
{
	int	x;
	int	y;
	char	**map;
	int		vert;
	int		horz;

	x = 0;
	y = 0;
	s_map->check_map = s_map->play_map;
	map = s_map->check_map;
	vert = 0;
	horz = 0;
	if (map[y][x] == ' ')
		while (map[y][x] == ' ')
		{
			x++;
			s_map->x_1_1 = x;
			s_map->y_1_1 = y;
		}
	//printf("x2 = %d\n", x);
	while (y < 4)
	{
		//ft_print_player_map(map);
		if ((map[y][x] == '1' || map[y][x] == '2') && map[y][x+1] == '1')
		{
			x = move_right(map, y, x);
			printf("move right x = %d\n", x);
		}
		else if ((map[y][x] == '1' || map[y][x] == '2') && map[y+1][x] == '1')
		{
			y = move_down(map, y, x);
			printf("move down y = %d\n", y);
		}
		else if ((map[y][x] == '1' || map[y][x] == '2') && (map[y][x-1] == '1' || map[y][x-1] == '2'))
		{
			x = move_left(map, y, x);
			printf("move left x = %d\n", x);
		}
	// 	else if (map[y][x] == '1' && map[y-1][x] == '1')
	// 	{
	// 		y--;
	// 		printf("move up y = %d\n", y);
	// 	}
	// 	else
	// 		return (0);
	// 	if ((y == s_map->y_1_1) && (x == s_map->x_1_1))
	// 		break;
	}
	printf("final x = %d\n", x);
	return (1);
}

int	ft_check_right(t_map *s_map)
{
	int	x;
	int	y;
	char	**map;
	//int		len;

	x = s_map->x_1_1;
	y = 0;
	map = s_map->play_map;
	printf("start x = %d\n", s_map->x_1_1);
	printf("start pos = %d %d\n", y, x);
	printf("pos %d %d = %c\n", y, x, map[y][x]);
	while (map[y])
	{
		while ((map[y][x] == '1') && map[y+1][x] == '1')
			y++;
		printf("test 1 = y %d x %d\n", y, x);
		if (map[y+1][x] != '1')
		{
			if (map[y][x-1] == '1')
			{
				printf("test 2 = y %d x %d\n", y, x);
				while (map[y][x] == '1')
					x--;
			}
			else 
				return (0);
			printf("test 3 = y %d x %d\n", y, x);
			printf("value y x = %c\n", map[y][x]);
		}
	}
	printf("scan finished %d %d\n", y, x);
	return (1);
}

int	ft_check_map(t_map *struc_map)
{
	printf("\n*****************\n");
	if (!ft_check_top(struc_map))
	{
		error("top wall not valid\n");
		return (0);
	}
	// if (!ft_check_right(struc_map))
	// {
	// 	error("right wall not valid\n");
	// 	return (0);
	// }
	printf("TOP WALL VALID\n");
	return (1);
}
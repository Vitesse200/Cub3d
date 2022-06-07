# include "cub3d.h"

int	move_right(char **map, int y, int x)
{
	while (map[y][x+1] == '1')
		x++;
	return (x);
}

int	move_left(char **map, int y, int x)
{
	while (map[y][x-1] == '1')
		x--;
	return (x);
}

int	move_down(char **map, int y, int x)
{
	while (map[y+1][x] == '1')
		y++;
	return (y);
}

int	move_up(char **map, int y, int x)
{
	while (map[y-1][x] == '1')
		y--;
	return (y);
}

int	ft_check_top(t_map *s_map)
{
	int	x;
	int	y;
	char	**map;
	int		len;

	x = 0;
	y = 0;
	map = s_map->play_map;
	len = ft_strlen(map[y]) - 1;
	printf("len = %d\n", len);
	while (map[y][x+1] != '\n')
	{
		printf("x1 = %d\n", x);
		if (map[y][x] == ' ')
			while (map[y][x] == ' ')
			{
				x++;
				s_map->y_1_1 = x;
			}
		printf("x2 = %d\n", x);
		if (map[y][x] == '1' && map[y][x+1] == '1')
			x = move_right(map, y, x);
		printf("x3 = %d\n", x);	
		if (map[y][x + 1] != '1' && x != len)
		{
			printf("test a y = %d\n", y);
			if (map[y+1][x] == '1')
			{
				printf("test b y = %d\n", y);
				y = move_up(map, y, x);
				printf("test c y = %d\n", y);
			}
			else if (map[y-1][x] == '1')
			{
				printf("test A y = %d\n", y);
				y = move_up(map, y, x);
				printf("test B y = %d\n", y);
				printf("test B x = %d\n", x);
			}
			if (map[y][x+1] == '\n')
			{
				printf("FINAL y = %d\n", y);
				printf("FINAL x = %d\n", x);
				s_map->x_1_1 = x;
				return (1);
			}
		}
		else
			return (0);
	}
	printf("len = %d\n", len);
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
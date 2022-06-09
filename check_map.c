# include "cub3d.h"

int	move_down(char **map, int y, int x);
int	move_up(char **map, int y, int x);


// new approach --- go through each side and when I find a space instead of a 1 i send the 1 check function
// if I find a 0 on the outside lines I break
int	move_right(char **map, int y, int x)
{
	while ((map[y][x+1] == '1' || map[y][x+1] == '2') && map[y][x+1] != '\n')
	{
		if (map[y][x+1] == '2')
			map[y][x] = '3';
		else
			map[y][x] = '2';
        if ((map[y][x+1] == '3' || map[y][x+1] == '2') && map[y-1][x] == '1')
        {
            move_up(map, y, x);
            printf(" R move up y = %d\n", y);
            break ;
        }
        else if ((map[y][x+1] == '2' || map[y][x+1] == '3') && map[y+1][x] == '1')
        {
            move_down(map, y, x);
            printf(" R move down y = %d\n", y);
            break ;
        }
		x++;
	}
//    if (map[y][x+1] == '3')
//    {
//        while (map[y][x+1] == '3' && map[y][x] != '\n')
//            x--;
//    }
	return (x);
}

int	move_down(char **map, int y, int x)
{
	while (map[y+1][x] == '1' || map[y+1][x] == '2')
	{
		if (map[y+1][x] == '2')
			map[y][x] = '3';
		else
			map[y][x] = '2';
		y++;
        if (map[y][x+1] == '1')
            x++;
	}
	return (y);
}

int	move_left(char **map, int y, int x)
{
	while (map[y][x-1] == '1' || map[y][x-1] == '2')
	{
		if (map[y][x-1] == '2')
			map[y][x] = '3';
		else 
			map[y][x] = '2';
        if ((map[y][x-1] == '2' && map[y-1][x] == '1') || (map[y][x-1] == '2' && map[y+1][x] == '1'))
            break ;
		x--;
	}
	return (x);
}


int	move_up(char **map, int y, int x)
{
	while ((map[y-1][x] == '1'  || map[y-1][x] == '2'))
	{
		printf("move up y = %d\n", y);
		if (map[y-1][x] == '2')
			map[y][x] = '3';
		else
			map[y][x] = '2';
		ft_print_player_map(map);
		y--;
		if (y == 0)
			break ;
	}
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
	while (y <= 14)
	{
        printf("////////////////Max x = %d\n", s_map->max_x);
		ft_print_player_map(map);
        write(1, "\n", 1);
        if ((map[y][x] == '2' || map[y][x] == '3') && (map[y+1][x] == '1'))
        {
            y = move_down(map, y, x);
            printf("move down y = %d\n", y);
        }
        else if ((map[y][x] == '2' || map[y][x] == '3') && (map[y-1][x] == '1'))
        {
            y = move_up(map, y, x);
            printf("move up y = %d\n", y);
        }
        else if (x == s_map->max_x)
        {
            x = move_left(map, y, x);
            printf("move left x = %d\n", x);
        }
		else if ((map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3') && (map[y][x+1] == '1' || map[y][x+1] == '2'))
		{
			x = move_right(map, y, x);
			printf("move right x = %d\n", x);
//            if (y > 0 && map[y-1][x] < map[y][x-1]){
//                y = move_up(map, y, x);
//                printf("move up y = %d\n", y);
//            }
		}
//        else if ((map[y][x] == '2' || map[y][x] == '3') && (map[y-1][x] == '1'))
//        {
//            y = move_up(map, y, x);
//            printf("move up y = %d\n", y);
//        }
		else if ((map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3') && (map[y+1][x] == '1' || map[y+1][x] == '2'))
		{
			y = move_down(map, y, x);
			printf("move down y = %d\n", y);
		}
		else if ((map[y][x] == '1' || map[y][x] == '2' || map[y][x] == '3') && (map[y][x-1] == '1' || map[y][x-1] == '2'))
		{
			x = move_left(map, y, x);
			printf("move left x = %d\n", x);
		}
		else if ((map[y][x] == '1' || map[y][x] == '2'|| map[y][x] == '3') && (map[y-1][x] == '1' || map[y-1][x] == '2'))
		{
			ft_print_player_map(map);
			y = move_up(map, y, x);
			printf("move up y = %d\n", y);
		}
		else
			return (0);
		if ((y == s_map->y_1_1) && (x == s_map->x_1_1))
			break;
	}
	printf("final x = %d\n", x);
	return (1);
}

//int	ft_check_map(t_map *struc_map)
//{
//	printf("\n*****************\n");
////	if (!ft_check_top(struc_map))
////	{
////		error("top wall not valid\n");
////		ft_print_player_map(struc_map->check_map);
////		return (0);
////	}
//	// if (!ft_check_right(struc_map))
//	// {
//	// 	error("right wall not valid\n");
//	// 	return (0);
//	// }
//    ft_check_all_sides()
//	printf("TOP WALL VALID\n");
//	return (1);
//}


#include "cub3d.h"

void    ft_move(int key, t_map *map)
{
	if (key == 2) {
		ft_move_r(&map->player, map);
	}
	else if (key == 0) {
		ft_move_l(&map->player, map);
	}
	else if (key == 13) {
		ft_move_up(&map->player, map);
	}
	else {
		ft_move_d(&map->player, map);
	}
}

void    ft_camera(int key, t_map *map)
{
	if (key == 123) // look on the left
	{
		map->player.angle += 10;
		if (map->player.angle == 360)
			map->player.angle +=  0;
		if (map->player.angle > 360)
			map->player.angle -=  360;
	}
	else if (key == 124) // look on the right
	{
		map->player.angle -=10;
		if (map->player.angle < 0)
			map->player.angle += 360;
		if (map->player.angle > 360)
			map->player.angle -=  360;
	}
	else // esc key 53
	{
		printf("key = %d = get to free **********\n", key);
        ft_free_map(map->play_map);
        free(map->play_map);
        //ft_free_map(map->map);
		//ft_free_all(map);
		while (1)
			;
		exit(0);
	}
}

int	ft_input(int key, void *param)
{
	t_map		*map;
	
	map = (t_map *)param;
	if (key == 2 || key == 0 || key == 13 || key == 1)
		ft_move(key, map);
	else if (key == 123 || key == 124 || key == 53)
		ft_camera(key, map);
	else
		return (0);
	draw_map(&map->winp, map);
	return (0);
}
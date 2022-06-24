#include "cub3d.h"

void	ft_move_r(t_vector *game)
{
    if (game->map->play_map[game->y][game->x + 1] != '1')
    {
        game->x++;
//        mlx_put_image_to_window(game->mlx, game->window, game->image.player,
//                                game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
//        mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
//                                (game->player.x - 1) * IMG_SIZE, game->player.y * IMG_SIZE);
    }
}

void	ft_move_l(t_vector *game)
{
    if (game->map->play_map[game->y][game->x - 1] != '1')
        game->x--;
//        mlx_put_image_to_window(game->mlx, game->window, game->image.player,
//                                game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
//        mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
//                                (game->player.x + 1) * IMG_SIZE, game->player.y * IMG_SIZE);
}

void	ft_move_up(t_vector *game)
{
    if (game->map->play_map[game->y - 1][game->x] != '1')
    {
        game->y--;
//        mlx_put_image_to_window(game->mlx, game->window, game->image.player,
//                                game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
//        mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
//                                game->player.x * IMG_SIZE, (game->player.y + 1) * IMG_SIZE);
    }
}

void	ft_move_d(t_vector *game)
{
    if (game->map->play_map[game->y + 1][game->x] != '1')
    {
        game->y++;
//        mlx_put_image_to_window(game->mlx, game->window, game->image.player,
//                                game->player.x * IMG_SIZE, game->player.y * IMG_SIZE);
//        mlx_put_image_to_window(game->mlx, game->window, game->image.empty,
//                                game->player.x * IMG_SIZE, (game->player.y - 1) * IMG_SIZE);
    }
}

int	ft_input(int key, void *param)
{
    t_map		*map;

    map = (t_map *)param;
    printf("angle == %f\n", map->player.angle);
    printf("key = %d\n", key);
    if (key == 2)
        ft_move_r(&map->player);
    if (key == 0)
        ft_move_l(&map->player);
    if (key == 13)
        ft_move_up(&map->player);
    if (key == 1)
        ft_move_d(&map->player);
    if (key == 123) // look on the left
    {
        map->player.angle += 31;
        if (map->player.angle > 360)
            map->player.angle =  0;
    }
    if (key == 124) // look on the right
    {
        map->player.angle += 29;
        if (map->player.angle < 0)
            map->player.angle =  360;
    }
    if (key == 53)
        exit(0);
    printf("angle == %f\n", map->player.angle);
	mlx_clear_window(map->winp.mlx, map->winp.win);
	draw_map(map->winp, map);
//    draw_scoreboard(game, 3, 2);
    return (0);
}
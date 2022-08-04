#include "cub3d.h"

void	get_texture_path(char *extract, t_texture *text)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	tmp = ft_memchr(text->extract, '.', ft_strlen(text->extract));
	tmp2 = malloc(sizeof (char) * (ft_strlen(extract)));
	i = 0;
	while (tmp[i] != '\n')
	{
		tmp2[i] = tmp[i];
		i++;
	}
	tmp2[i] = '\0';
	text->path = tmp2;
}

int	valid_text(char *path)
{
	int	file;

	file = open(path, O_WRONLY);
	if (file != -1)
		printf("FILE OK\n");
	else
		return (error("XPM FILE not OK\n"));
    close (file);
	return (1);
}

int	ft_texture_data(t_map *map)
{
	get_texture_path(map->north->extract, map->north);
	if (valid_text(map->north->path) != 1)
		return (error("path to texture not valid\n"));
	get_texture_path(map->south->extract, map->south);
	if (valid_text(map->south->path) != 1)
		return (error("path to texture not valid\n"));
	get_texture_path(map->east->extract, map->east);
	if (valid_text(map->east->path) != 1)
		return (error("path to texture not valid\n"));
	get_texture_path(map->west->extract, map->west);
	if (valid_text(map->west->path) != 1)
		return (error("path to texture not valid\n"));
	return (1);
}

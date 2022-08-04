/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaillar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 14:39:49 by lgaillar          #+#    #+#             */
/*   Updated: 2022/03/01 09:49:11 by lgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_line(char **line);
char	*cp_line(char *buff, char *line, int rv, int *i);
char	*gnl_return(char **buff, char *line);
char	*get_remain(char *line, char *buff, int i);

char	*gnl(int fd)
{
	static char	*buff;
	char		*line;
	static int	i;
	int			rv;

	rv = 1;
	init_line(&line);
	if (!line)
		return (NULL);
	if (buff)
		line = get_remain(line, buff, i++);
	else
		buff = malloc(sizeof(char) * (42 + 1));
	if (!buff)
		return (NULL);
	if (ft_strchri(line, '\n') != 0 || line[0] == '\n')
		return (line);
	while (rv > 0)
	{
		rv = read(fd, buff, 42);
		line = cp_line(buff, line, rv, &i);
		if (ft_strchri(buff, '\n') != 0 || buff[0] == '\n')
			return (line);
	}
	return (gnl_return(&buff, line));
}

void	init_line(char **line)
{
	*line = malloc(sizeof(char));
	if (!(*line))
		return ;
	(*line)[0] = '\0';
}

char	*cp_line(char *buff, char *line, int rv, int *i)
{
	*i = 0;
	if (rv < 0)
		rv = 0;
	buff[rv] = '\0';
	if (ft_strchri(buff, '\n') != 0 || buff[0] == '\n')
		line = ft_strljoin(&line, buff, ft_strchri(buff, '\n'));
	else
		line = ft_strljoin(&line, buff, 42);
	return (line);
}

char	*gnl_return(char **buff, char *line)
{
	free(*buff);
	*buff = NULL;
	if (line[0] != '\0')
		return (line);
	free(line);
	return (NULL);
}

char	*get_remain(char *line, char *buff, int i)
{
	free(line);
	line = ft_next(buff, i);
	return (line);
}

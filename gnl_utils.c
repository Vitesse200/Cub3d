/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgaillar <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 15:04:55 by lgaillar          #+#    #+#             */
/*   Updated: 2022/03/01 09:51:30 by lgaillar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_strchri(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strljoin(char **s1, char *s2, int l)
{
	int		i;
	char	*res;
	int		j;

	res = malloc (sizeof(char) * (ft_strlen(*s1) + l + 2));
	i = 0;
	j = 0;
	while ((*s1)[i])
	{
		res[i] = (*s1)[i];
		i++;
	}
	while (j <= l && s2[j])
	{
		res[i] = s2[j];
		i++;
		j++;
	}
	if (*s1)
		free(*s1);
	res[i] = '\0';
	return (res);
}

char	*ft_next(char *s, int c)
{
	int		l;
	int		i;
	int		j;
	char	*res;

	i = 0;
	l = 0;
	while (s[i] && l <= c)
	{
		if (s[i] == '\n')
			l++;
		i++;
	}
	l = 0;
	j = i;
	while (s[j] && s[j] != '\n')
		j++;
	res = malloc(sizeof(char) * (j - i + 2));
	while (i <= j && s[i])
	{
		res[l++] = s[i];
		i++;
	}
	res[l] = '\0';
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <jhermon-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 17:02:51 by jhermon-          #+#    #+#             */
/*   Updated: 2022/08/05 17:03:05 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	exit (1);
}

void	*null_error(char *message)
{
	printf("\033[0;31m" " Error\n %s\n" "\033[0m", message);
	exit (1);
}

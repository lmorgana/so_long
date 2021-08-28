/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 14:31:01 by lmorgana          #+#    #+#             */
/*   Updated: 2021/06/13 14:31:03 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_cell (char *ch)
{
	if (ch)
	{
		if (*ch == '1')
			return (0);
		else if (*ch == 'E')
		{
			return (-1);
		}
		else if (*ch == 'C')
		{
			*ch = '0';
			return (1);
		}
		return (1);
	}
	return (0);
}

int	ft_move_cell (char **arr, t_hero *hero, int i, int j)
{
	(void) arr;
	hero->i = i;
	hero->j = j;
	return (1);
}

int	ft_search(char **arr, char ch)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == ch)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

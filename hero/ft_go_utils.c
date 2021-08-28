/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_go_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 03:21:08 by lmorgana          #+#    #+#             */
/*   Updated: 2021/06/13 03:21:10 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_go_right(t_vars *vars, char **arr, t_hero *hero, t_map map)
{
	int	x;
	int	h_i;
	int	h_j;

	h_i = hero->i;
	h_j = hero->j + 1;
	if (hero->j >= map.j)
		return (0);
	x = ft_cell(&arr[h_i][h_j]);
	if (x > 0 || (x == -1 && ft_search(arr, 'C') != 0))
	{
		ft_move_cell(arr, hero, hero->i, hero->j + 1);
		return (1);
	}
	if (x == -1 && ft_search(arr, 'C') == 1)
		ft_close_all(vars);
	return (0);
}

int	ft_go_left(t_vars *vars, char **arr, t_hero *hero, t_map map)
{
	int	x;
	int	h_i;
	int	h_j;

	(void) map;
	if (hero->j <= 0)
		return (0);
	h_i = hero->i;
	h_j = hero->j - 1;
	x = ft_cell(&arr[h_i][h_j]);
	if (x > 0 || (x == -1 && ft_search(arr, 'C') != 0))
	{
		ft_move_cell(arr, hero, hero->i, hero->j - 1);
		return (1);
	}
	if (x == -1 && ft_search(arr, 'C') == 0)
		ft_close_all(vars);
	return (0);
}

int	ft_go_up(t_vars *vars, char **arr, t_hero *hero, t_map map)
{
	int	x;
	int	h_i;
	int	h_j;

	(void) map;
	if (hero->i <= 0)
		return (0);
	h_i = hero->i - 1;
	h_j = hero->j;
	x = ft_cell(&arr[h_i][h_j]);
	if (x > 0 || (x == -1 && ft_search(arr, 'C') != 0))
	{
		ft_move_cell(arr, hero, hero->i - 1, hero->j);
		return (1);
	}
	if (x == -1 && ft_search(arr, 'C') == 0)
		ft_close_all(vars);
	return (0);
}

int	ft_go_down(t_vars *vars, char **arr, t_hero *hero, t_map map)
{
	int	x;
	int	h_i;
	int	h_j;

	if (hero->i >= map.i - 1)
		return (0);
	h_i = hero->i + 1;
	h_j = hero->j;
	x = ft_cell(&arr[h_i][h_j]);
	if (x > 0 || (x == -1 && ft_search(arr, 'C') != 0))
	{
		ft_move_cell(arr, hero, hero->i + 1, hero->j);
		return (1);
	}
	if (x == -1 && ft_search(arr, 'C') == 0)
		ft_close_all(vars);
	return (0);
}

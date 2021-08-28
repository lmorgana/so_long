/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 16:13:33 by lmorgana          #+#    #+#             */
/*   Updated: 2021/06/11 16:13:34 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_vars *vars)
{
	int	h;
	int	w;

	vars->sprite.wall = mlx_xpm_file_to_image(vars->mlx, \
		"./source/tileset/wall.xpm", &h, &w);
	vars->sprite.ground = mlx_xpm_file_to_image(vars->mlx, \
		"./source/tileset/ground2.xpm", &h, &w);
	vars->sprite.hero = mlx_xpm_file_to_image(vars->mlx, \
		"./source/hero.xpm", &h, &w);
	vars->sprite.colect = mlx_xpm_file_to_image(vars->mlx, \
		"./source/colect.xpm", &h, &w);
	vars->sprite.door = mlx_xpm_file_to_image(vars->mlx, \
		"./source/door.xpm", &h, &w);
}

void	init_hero(t_vars *vars, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == 'P')
			{
				vars->hero.i = i;
				vars->hero.j = j;
			}
			j++;
		}
		i++;
	}
}

void	ft_vars_win(t_vars *v, char *sp, int j, int i)
{
	mlx_put_image_to_window(v->mlx, v->win, sp, j * 50, i * 50);
}

int	ft_close_all(t_vars *vars)
{
	if (vars->count > 0)
		vars->count++;
	mlx_destroy_image(vars->mlx, vars->sprite.wall);
	mlx_destroy_image(vars->mlx, vars->sprite.ground);
	mlx_destroy_image(vars->mlx, vars->sprite.hero);
	mlx_destroy_image(vars->mlx, vars->sprite.colect);
	mlx_destroy_image(vars->mlx, vars->sprite.door);
	mlx_destroy_window(vars->mlx, vars->win);
	ft_putnbr_fd(vars->count, 0);
	ft_putchar_fd('\n', 0);
	ft_clear_arr(vars->arr);
	exit(0);
	return (0);
}

int	ft_error_msg(char *str)
{
	ft_putstr_fd(str, 0);
	return (0);
}

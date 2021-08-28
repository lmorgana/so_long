/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 20:05:07 by lmorgana          #+#    #+#             */
/*   Updated: 2021/06/07 20:05:10 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_hooks(int keycode, t_vars *vars)
{
	int	step;

	step = 50;
	if (keycode == 53 || vars->count == 2147483647)
		ft_close_all(vars);
	else if (keycode == 0)
		vars->count += ft_go_left(vars, vars->arr, &vars->hero, vars->map);
	else if (keycode == 13)
		vars->count += ft_go_up(vars, vars->arr, &vars->hero, vars->map);
	else if (keycode == 2)
		vars->count += ft_go_right(vars, vars->arr, &vars->hero, vars->map);
	else if (keycode == 1)
		vars->count += ft_go_down(vars, vars->arr, &vars->hero, vars->map);
	return (0);
}

void	ft_print_hero(t_vars *vars, t_hero *hero)
{
	ft_vars_win(vars->mlx, vars->sprite.hero, hero->j, hero->i);
}

int	ft_print_map(t_vars *vars, char **arr, t_sprite *spr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i] != NULL)
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (arr[i][j] == '0' || arr[i][j] == 'P' || \
			 arr[i][j] == 'C' || arr[i][j] == 'E')
				ft_vars_win(vars, spr->ground, j, i);
			if (arr[i][j] == '1')
				ft_vars_win(vars, spr->wall, j, i);
			if (arr[i][j] == 'P')
				arr[i][j] = '0';
			if (arr[i][j] == 'C')
				ft_vars_win(vars, spr->colect, j, i);
			if (arr[i][j] == 'E')
				ft_vars_win(vars, spr->door, j, i);
			j++;
		}
		i++;
	}
	return (0);
}

int	render_next_frame(t_vars *vars)
{
	ft_print_map(vars, vars->arr, &vars->sprite);
	ft_print_hero(vars, &vars->hero);
	return (0);
}

int	main(int argc, char **argv)
{
	t_vars	vars;

	if (argc <= 1)
		return (ft_error_msg("Error \nmap is invalid\n"));
	vars.arr = ft_get_map(ft_ch_nm_file(argv[1]));
	if (vars.arr == NULL || !ft_check_map(vars.arr))
		return (ft_error_msg("Error \nmap is invalid\n"));
	vars.count = 0;
	vars.map.i = ft_arrlen(vars.arr);
	vars.map.j = ft_strlen(vars.arr[0]);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, vars.map.j * 50, \
		vars.map.i * 50, "so_long");
	init_sprite(&vars);
	init_hero(&vars, vars.arr);
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_hook(vars.win, 2, 1L << 0, ft_hooks, &vars);
	mlx_hook(vars.win, 17, 7L << 0, ft_close_all, &vars);
	mlx_loop(vars.mlx);
	ft_clear_arr(vars.arr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 23:04:58 by lmorgana          #+#    #+#             */
/*   Updated: 2021/06/12 23:05:00 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*ft_ch_nm_file(char *name)
{
	char	*str;

	str = ft_strnstr(name, ".ber", ft_strlen(name));
	if (str && ft_strlen(str) == 4)
		return (name);
	return (NULL);
}

static	int	ft_check_el(char ch, char *stat)
{
	if (ch == 'C')
		*stat = (*stat | (1));
	else if (ch == 'E')
		*stat = (*stat | (1 << 1));
	else if (ch == 'P')
	{
		if ((*stat | (0 << 2)) >> 2)
			return (0);
		*stat = (*stat | (1 << 2));
	}
	else if (ch != '1' && ch != '0')
		return (0);
	return (1);
}

static	int	ft_ckeck_cl(char **arr, int l_i, int l_j)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= l_i)
	{
		if (arr[i][0] != '1' || arr[i][l_j] != '1')
			return (0);
		i++;
	}
	while (j <= l_j)
	{
		if (arr[0][j] != '1' || arr[l_i][j] != '1')
			return (0);
		j++;
	}
	return (1);
}

int	ft_check_map(char **arr)
{
	int		i;
	int		j;
	int		l_j;
	char	stat;

	i = 0;
	l_j = ft_strlen(arr[0]);
	stat = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j] != '\0')
		{
			if (!ft_check_el(arr[i][j], &stat))
				return (0);
			j++;
		}
		if (j != l_j)
			return (0);
		i++;
	}
	return ((stat == 7) && ft_ckeck_cl(arr, i - 1, l_j - 1));
}

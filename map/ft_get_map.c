/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 21:23:43 by lmorgana          #+#    #+#             */
/*   Updated: 2021/06/12 21:23:44 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_clear_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int	ft_arrlen(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static	char	**ft_get_arr(t_list *lst)
{
	int		i;
	char	**arr;

	i = 0;
	lst = lst->next;
	if (lst)
	{
		arr = malloc (sizeof(char *) * ft_lstsize(lst) + 1);
		if (!arr)
			return (NULL);
		while (lst)
		{
			arr[i] = lst->content;
			lst = lst->next;
			i++;
		}
		arr[i] = NULL;
		return (arr);
	}
	return (NULL);
}

static	void	ft_lstclr(t_list *lst)
{
	t_list	*bf;

	while (lst)
	{
		bf = lst;
		lst = lst->next;
		free(bf);
	}
}	

char	**ft_get_map(char *file)
{
	int		fd;
	char	*buff;
	char	**arr;
	t_list	*lst;
	int		x;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	lst = ft_lstnew(NULL);
	x = get_next_line(fd, &buff);
	while (x > 0)
	{
		ft_lstadd_back(&lst, ft_lstnew(buff));
		x = get_next_line(fd, &buff);
	}
	if (x < 0)
	{
		ft_lstclear(&lst, free);
		return (NULL);
	}
	ft_lstadd_back(&lst, ft_lstnew(buff));
	arr = ft_get_arr(lst);
	ft_lstclr(lst);
	return (arr);
}

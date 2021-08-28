/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmorgana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:28:15 by lmorgana          #+#    #+#             */
/*   Updated: 2021/04/17 13:28:19 by lmorgana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*u_dst;
	unsigned char	*u_src;

	u_dst = (unsigned char *) dst;
	u_src = (unsigned char *) src;
	i = 0;
	if (dst || src)
	{
		while (i < n)
		{
			u_dst[i] = u_src[i];
			i++;
		}
		return (dst);
	}
	return (NULL);
}

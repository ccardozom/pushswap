/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 11:17:59 by ccardozo          #+#    #+#             */
/*   Updated: 2021/05/25 21:12:50 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t	i;
	char	*pdst;
	char	*psrc;

	pdst = (void *)dst;
	psrc = (void *)src;
	if (src == dst)
		return (dst);
	if (src < dst)
	{
		i = len;
		while (i-- > 0)
			pdst[i] = psrc[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			pdst[i] = psrc[i];
			i++;
		}
	}
	return (dst);
}

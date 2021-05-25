/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 13:17:38 by ccardozo          #+#    #+#             */
/*   Updated: 2021/05/25 09:13:12 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ps;

	ps = 0;
	while (*s)
	{
		if (*s == c)
			ps = (char *)s;
		++s;
	}
	if (ps)
		return (ps);
	if (c == '\0')
		return ((char *)s);
	return (0);
}

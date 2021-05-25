/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 08:58:33 by ccardozo          #+#    #+#             */
/*   Updated: 2021/05/25 10:19:13 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_segment(char const *s, char c)
{
	size_t	counter;
	int		i;

	counter = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			i++;
			continue ;
		}
		counter++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (counter);
}

static char	*ft_strndup(const char *s1, size_t n)
{
	char	*clone;
	size_t	i;

	clone = (char *)malloc(sizeof(char *) * (n + 1));
	if (!clone)
		return (NULL);
	i = 0;
	while (i < n)
	{
		clone[i] = s1[i];
		i++;
	}
	clone[i] = '\0';
	return (clone);
}

static void	*destroy_strs(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	size_t	tab_counter;
	size_t	i;
	size_t	j;

	tab_counter = count_segment(s, c);
	str = (char **)malloc(sizeof(char *) * (tab_counter + 1));
	if (!str || !s)
		return (NULL);
	tab_counter = 0;
	j = -1;
	while (s[++j])
	{
		if (s[j] == c)
			continue ;
		i = 0;
		while (s[j + i] && s[j + i] != c)
			i++;
		str[tab_counter] = ft_strndup(&s[j], i);
		if (!str[tab_counter++])
			return (destroy_strs(str));
		j += i - 1;
	}
	str[tab_counter] = NULL;
	return (str);
}

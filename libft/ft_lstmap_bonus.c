/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccardozo <ccardozo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 09:21:53 by ccardozo          #+#    #+#             */
/*   Updated: 2021/05/25 21:55:41 by ccardozo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *ls, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*aux;

	if (!ls && !del)
		return (NULL);
	aux = ls;
	new = ft_lstnew(f(aux->content));
	if (!new)
		return (NULL);
	aux = aux->next;
	while (aux)
	{
		tmp = ft_lstnew(f(aux->content));
		if (!tmp)
			return (NULL);
		ft_lstadd_back(&new, tmp);
		aux = aux->next;
	}
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 13:18:08 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/04 14:44:39 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*prev;
	t_list	*start;

	start = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content);
		if (!new)
		{
			ft_lstclear(&start, del);
			return (NULL);
		}
		if (start != NULL)
			prev->next = new;
		else
			start = new;
		new->content = (*f)(new->content);
		prev = new;
		lst = lst->next;
	}
	return (start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 09:17:06 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/01 15:11:49 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*tab;

	if (nmemb > INT_MAX && size > INT_MAX)
		return (NULL);
	if (size == 0 || nmemb == 0)
	{
		tab = malloc(0);
		return (tab);
	}
	if ((size_t)(nmemb * size) / nmemb != size)
		return (NULL);
	tab = malloc(nmemb * size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, nmemb * size);
	return (tab);
}

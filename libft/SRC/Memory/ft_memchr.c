/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:32:23 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/04 11:51:57 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)s;
	c = (unsigned char)c;
	i = -1;
	while (++i < n)
		if (tmp[i] == c)
			return (tmp + i);
	return (0);
}

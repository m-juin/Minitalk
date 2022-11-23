/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 11:53:11 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/01 13:54:37 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	pos1;
	size_t	pos2;
	size_t	dstsize;

	if ((src == NULL || dst == NULL) && size == 0)
		return (0);
	pos2 = ft_strlen(src);
	pos1 = ft_strlen(dst);
	dstsize = pos1;
	if (size == 0)
		return (pos2);
	if (pos1 >= size)
		return (pos2 + size);
	pos2 = 0;
	while (src[pos2] && dstsize + pos2 < size - 1)
	{
		dst[pos1] = src[pos2];
		pos1++;
		pos2++;
	}
	dst[pos1] = '\0';
	return (dstsize + ft_strlen(src));
}

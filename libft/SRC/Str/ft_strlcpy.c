/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 11:34:19 by mjuin             #+#    #+#             */
/*   Updated: 2022/09/28 12:10:45 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	y;

	i = 0;
	y = 0;
	while (src[i] != '\0')
		i++;
	if (size == 0)
		return (i);
	while (src[y] != '\0' && y < size - 1)
	{
		dst[y] = src[y];
		y++;
	}
	dst[y] = '\0';
	return (i);
}

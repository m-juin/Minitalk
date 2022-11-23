/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:45 by mjuin             #+#    #+#             */
/*   Updated: 2022/09/30 16:01:40 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		pos;
	char		*tmp;
	const char	*tmp2;

	pos = 0;
	tmp = dest;
	tmp2 = src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (pos < n)
	{
		tmp[pos] = tmp2[pos];
		pos++;
	}
	return (dest);
}

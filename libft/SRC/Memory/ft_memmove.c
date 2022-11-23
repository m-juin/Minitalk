/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:27:45 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/05 13:20:37 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*tmp;
	const char	*tmp2;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	tmp = dest;
	tmp2 = src;
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		while (n > 0)
		{
			tmp[n - 1] = tmp2[n - 1];
			n--;
		}
	}
	return (dest);
}

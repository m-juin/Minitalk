/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:09:24 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/01 14:05:36 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	y;
	size_t	lens;

	y = 0;
	lens = len;
	if ((big == NULL || little == NULL) && len == 0)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)&big[y]);
	while (lens > 0 && big[y] != '\0')
	{
		i = 0;
		while (little[i] && little[i] == big[y + i] && (i + y) < len)
			i++;
		if (little[i] == '\0')
			return ((char *)&big[y]);
		y++;
		lens--;
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:40:11 by mjuin             #+#    #+#             */
/*   Updated: 2022/09/28 12:37:06 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	tmp = (char *)s;
	i = ft_strlen(tmp);
	c = c % 256;
	if (c == 0 && tmp[i] == 0)
		return (tmp + i);
	while (--i > -1)
		if (tmp[i] == c)
			return (tmp + i);
	return (0);
}

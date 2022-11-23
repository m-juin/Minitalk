/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:14:14 by mjuin             #+#    #+#             */
/*   Updated: 2022/09/30 10:01:26 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int			i;
	unsigned char			*s1b;
	unsigned char			*s2b;

	i = 0;
	s1b = (unsigned char *)s1;
	s2b = (unsigned char *)s2;
	while (i < n && (s1b[i] || s2b[i]))
	{
		if (s1b[i] != s2b[i])
			return (s1b[i] - s2b[i]);
		i++;
	}
	return (0);
}

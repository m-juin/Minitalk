/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:01:35 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/01 15:16:42 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		size;
	int		pos;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	pos = 0;
	while (*s1 != '\0')
		str[pos++] = *s1++;
	while (*s2 != '\0')
		str[pos++] = *s2++;
	str[pos] = 0;
	return (str);
}

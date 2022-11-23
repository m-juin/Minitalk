/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 14:24:12 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/01 15:17:12 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*subs;
	int		pos;

	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		subs = malloc(1);
		subs[0] = '\0';
		return (subs);
	}
	pos = 0;
	if (len <= (ft_strlen(s) - start))
		subs = malloc((len * sizeof(char)) + 1);
	else
		subs = malloc(((ft_strlen(s) - start) * sizeof(char)) + 1);
	if (!subs)
		return (NULL);
	while (s[start] && len-- > 0)
		subs[pos++] = s[start++];
	subs[pos] = '\0';
	return (subs);
}

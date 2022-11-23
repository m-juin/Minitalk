/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 20:12:17 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/05 21:47:24 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_straddchar(char *dst, const char src)
{
	int		pos;
	char	*str;

	str = ft_calloc((ft_strlen(dst) + 2), sizeof(char));
	if (!str)
		return (NULL);
	pos = 0;
	if (dst != NULL)
		while (*dst != '\0')
			str[pos++] = *dst++;
	str[pos] = src;
	return (str);
}

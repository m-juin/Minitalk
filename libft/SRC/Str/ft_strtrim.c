/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 15:59:49 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/01 15:17:00 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_checkstart(char const *s1, char const *set)
{
	int	count;
	int	scount;

	count = 0;
	while (s1[count])
	{
		scount = 0;
		while (set[scount])
		{
			if (set[scount] == s1[count])
			{
				break ;
			}
			scount++;
		}
		if (set[scount] == '\0')
			return (count);
		count++;
	}
	return (count);
}

static int	ft_checkend(char const *s1, char const *set)
{
	int	count;
	int	scount;

	count = ft_strlen(s1) - 1;
	while (count >= 0)
	{
		scount = 0;
		while (set[scount])
		{
			if (set[scount] == s1[count])
			{
				break ;
			}
			scount++;
		}
		if (set[scount] == '\0')
			return ((ft_strlen(s1) - 1) - count);
		count--;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		count1;
	int		count2;
	int		count3;
	int		size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	count1 = ft_checkstart(s1, set);
	count2 = ft_checkend(s1, set);
	size = (ft_strlen(s1) - (count1 + count2));
	newstr = malloc((size * sizeof(char)) + 1);
	if (!newstr)
		return (NULL);
	count3 = -1;
	while (++count3 < size)
	{
		newstr[count3] = s1[count1 + count3];
	}
	newstr[count3] = '\0';
	return (newstr);
}

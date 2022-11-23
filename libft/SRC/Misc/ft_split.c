/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:21:02 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/04 14:37:13 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_cleartab(char **tab)
{
	int	pos;

	pos = 0;
	while (tab[pos] != NULL)
	{
		free(tab[pos]);
		pos++;
	}
	free(tab);
}

static char	*ft_getnextword(char const *s, char c, int *start)
{
	int		count;
	char	*str;

	count = 0;
	while (s[*start + count] == c)
		count++;
	*start = *start + count;
	count = 0;
	while (s[*start + count] && s[*start + count] != c)
		count++;
	str = malloc((count * sizeof(char)) + 1);
	if (!str)
		return (NULL);
	count = 0;
	while (s[*start + count] && s[*start + count] != c)
	{
		str[count] = s[*start + count];
		count++;
	}
	str[count] = '\0';
	*start = *start + count;
	return (str);
}

static int	ft_wordcount(const char *s, char c)
{
	int	count;
	int	pos;

	count = 0;
	pos = 0;
	if (!s[pos])
		return (count);
	while (s[pos])
	{
		if (s[pos] == c && (pos > 0 && s[pos - 1] != c))
			count++;
		pos++;
	}
	if (pos > 0 && s[pos - 1] == c)
		return (count);
	return (count + 1);
}

static int	ft_split2(char **tab, int *start, const char *s, int c)
{
	int	count2;
	int	count;

	count2 = 0;
	count = ft_wordcount(s, c);
	while (count2 < count)
	{
		tab[count2] = ft_getnextword(s, c, start);
		if (!tab[count2])
		{
			ft_cleartab(tab);
			return (1);
		}
		count2++;
	}
	tab[count2] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		start;
	char	**splited;
	int		count;

	start = 0;
	if (s == NULL)
		return (NULL);
	count = ft_wordcount(s, c);
	splited = malloc(((count + 1) * sizeof(char *)));
	if (!splited)
		return (NULL);
	if ((s[0] == '\0' || count == 0))
	{
		splited[0] = 0;
		return (splited);
	}
	if (ft_split2(splited, &start, s, c) == 1)
		return (NULL);
	return (splited);
}

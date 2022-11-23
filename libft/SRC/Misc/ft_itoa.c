/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 13:00:13 by mjuin             #+#    #+#             */
/*   Updated: 2022/09/30 11:36:53 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static int	ft_getsize(long int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n == 0)
		return (1);
	while (n > 0)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static int	ft_getnum(long int *n)
{
	int	ret;

	ret = *n % 10;
	*n = *n / 10;
	return (ret);
}

char	*ft_itoa(int n)
{
	int			pos;
	char		*ret;
	int			size;
	long int	newn;

	size = ft_getsize(n);
	ret = malloc((size + 1) * sizeof(char));
	newn = n;
	if (!ret)
		return (NULL);
	ft_bzero(ret, size + 1);
	pos = 0;
	if (newn < 0)
	{
		ret[pos] = '-';
		newn *= -1;
	}
	else if (newn == 0)
		ret[pos] = '0';
	pos++;
	while (newn > 0)
		ret[size - pos++] = ft_getnum(&newn) + 48;
	return (ret);
}

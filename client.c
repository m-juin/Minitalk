/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:43:27 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/22 09:32:40 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static int	*ft_convertbinary(unsigned int c)
{
	int	*ret;
	int	pos;

	pos = 7;
	ret = ft_calloc(8, sizeof(int));
	if (!ret)
		return (0);
	while (pos > 0)
	{
		ret[pos] = c % 2;
		pos--;
		c /= 2;
	}
	return (ret);
}

static int	ft_sendbinary(int bin[8], int pid)
{
	int	pos;
	int	ret;

	pos = 0;
	while (pos < 8)
	{
		if (bin[pos] == 0)
			ret = kill(pid, SIGUSR1);
		else
			ret = kill(pid, SIGUSR2);
		if (ret != 0)
			return (-1);
		pos++;
		usleep(300);
	}
	return (0);
}

int	main(int ac, char **av)
{
	int					pid;
	int					*bin;
	int					pos;
	int					ret;

	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (0);
	pos = 0;
	while ((pos == 0 && av[2][pos]) || (pos != 0 && av[2][pos - 1]))
	{
		bin = ft_convertbinary(av[2][pos]);
		ret = ft_sendbinary(bin, pid);
		pos++;
		free(bin);
		if (ret == -1)
			return (0);
	}
}

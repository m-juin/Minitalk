/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:43:27 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/21 10:36:12 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

static int	ft_sendbinary(char c, int pid)
{
	int	pos;
	int	ret;

	pos = 0;
	while (pos < 8)
	{
		if (c >> pos & 1)
			ret = kill(pid, SIGUSR2);
		else
			ret = kill(pid, SIGUSR1);
		if (ret != 0)
			return (-1);
		pos++;
		usleep(1);
	}
	return (0);
}

static void	ft_sendint(int sended, int pid)
{
	int	pos;

	pos = 0;
	while (pos < 32)
	{
		if (sended >> pos & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		pos++;
		usleep(1);
	}
}

int	main(int ac, char **av)
{
	int					pid;
	int					pos;
	int					ret;

	if (ac < 3)
		return (0);
	pid = ft_atoi(av[1]);
	if (pid < 0)
		return (0);
	pos = 0;
	if (av[2] != NULL && av[2][0] != '\0')
		ft_sendint(ft_strlen(av[2]), pid);
	while (av[2][pos])
	{
		ret = ft_sendbinary(av[2][pos], pid);
		pos++;
		if (ret == -1)
			return (0);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:48:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/12/21 10:47:06 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static char	*g_str;

static void	ft_handleresult(int send)
{
	static int	size;
	static int	count;

	if (g_str == NULL)
	{
		size = send;
		g_str = malloc((size + 1) * sizeof(char));
		if (g_str == NULL)
			return ;
		g_str[size] = '\0';
		return ;
	}
	count++;
	g_str[count - 1] = send;
	if (count == size)
	{
		write(1, g_str, size);
		free(g_str);
		g_str = NULL;
		size = 0;
		count = 0;
	}
}

void	signal_catcher(int signo)
{
	static int	count;
	static int	sendedchar;
	int			binvalue;

	if (signo == 10)
		binvalue = 0;
	else
		binvalue = 1;
	sendedchar += binvalue * ft_power(count, 2);
	count++;
	if ((g_str == NULL && count == 32) || (g_str != NULL && count == 8))
	{
		count = 0;
		ft_handleresult(sendedchar);
		sendedchar = 0;
	}
}

int	main(void)
{
	ft_printf("Server pid = %i\n", getpid());
	g_str = NULL;
	while (1)
	{
		signal(SIGUSR1, &signal_catcher);
		signal(SIGUSR2, &signal_catcher);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 11:48:30 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/22 13:53:13 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "libft/libft.h"

static int	g_signo;

static int	ft_addbinary(int binary[8])
{
	int	pos;

	pos = 0;
	while (pos < 8 && binary[pos] != 2)
		pos++;
	if (pos == 8)
	{	
		pos = 0;
		while (pos < 8)
			binary[pos++] = 2;
		pos = 0;
	}
	if (g_signo == 10)
		binary[pos] = 0;
	else
		binary[pos] = 1;
	return (pos + 1);
}

static void	ft_write(char *str)
{
	int	pos;

	pos = 0;
	while (str[pos])
	{
		write(1, &str[pos], 1);
		pos++;
	}
	free(str);
}

static char	*ft_handleresult(int binary[8], char *str)
{
	char	*tmp;
	int		pos;
	char	added;

	pos = ft_addbinary(binary);
	if (pos != 8)
		return (str);
	added = ft_convert_bin(binary);
	tmp = ft_straddchar(str, added);
	if (str != NULL)
		free(str);
	if (!tmp)
		return (NULL);
	if (added == 0)
	{
		ft_write(tmp);
		return (NULL);
	}
	return (tmp);
}

void	signal_catcher(int signo)
{
	g_signo = signo;
}

int	main(void)
{
	int					binary[8];
	int					pos;
	char				*str;
	struct sigaction	sa;

	ft_printf("Server pid = %i\n", getpid());
	sa.sa_handler = (void *)signal_catcher;
	sa.sa_flags = SA_RESTART;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pos = 0;
	str = NULL;
	while (pos < 8)
		binary[pos++] = 2;
	while (1)
	{
		pause();
		usleep(1);
		str = ft_handleresult(binary, str);
	}
}

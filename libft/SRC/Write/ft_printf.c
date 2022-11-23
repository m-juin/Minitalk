/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 16:11:27 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/12 13:19:24 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

static void	ft_convert(const char *str, int pos, va_list aglst, size_t *write)
{	
	if (str[pos] == '%')
		*write += ft_putchar_fd(str[pos], 1);
	else if (str[pos] == 'c')
		*write += ft_putchar_fd(va_arg(aglst, int), 1);
	else if (str[pos] == 's')
		*write += ft_putstr_fd(va_arg(aglst, char *), 1);
	else if (str[pos] == 'i' || str[pos] == 'd')
		*write += ft_putnbr_fd(va_arg(aglst, int), 1);
	else if (str[pos] == 'u')
		*write += ft_uputnbr_fd(va_arg(aglst, unsigned int), 1);
	else if (str[pos] == 'x')
		*write += ft_puthexa_fd(va_arg(aglst, unsigned int), 0, 1, 0);
	else if (str[pos] == 'X')
		*write += ft_puthexa_fd(va_arg(aglst, unsigned int), 1, 1, 0);
	else if (str[pos] == 'p')
		*write += ft_puthexa_fd(va_arg(aglst, long unsigned int), 0, 1, 1);
	else if (str[pos] != '\0')
	{
		*write += ft_putchar_fd(str[pos - 1], 1);
		*write += ft_putchar_fd(str[pos], 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list		arglist;
	int			pos;
	size_t		size;

	va_start(arglist, str);
	pos = 0;
	size = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
		{
			pos++;
			ft_convert(str, pos, arglist, &size);
		}
		else
			size += ft_putchar_fd(str[pos], 1);
		pos++;
	}
	return (size);
}

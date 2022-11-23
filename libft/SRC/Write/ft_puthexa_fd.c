/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:48:45 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/12 13:12:40 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_puthexa_fd(long unsigned int nbr, int size, int fd, int pointer)
{
	char	*basemin;
	char	*basemaj;
	size_t	rsize;

	basemin = "0123456789abcdef";
	basemaj = "0123456789ABCDEF";
	rsize = 0;
	if (pointer == 1)
	{
		if (nbr == 0)
		{
			rsize += ft_putstr_fd("(nil)", fd);
			return (rsize);
		}
		rsize += ft_putstr_fd("0x", fd);
	}
	if (nbr >= 16)
		rsize += ft_puthexa_fd((nbr / 16), size, fd, 0);
	if (size == 0)
		rsize += ft_putchar_fd(basemin[nbr % 16], fd);
	else
		rsize += ft_putchar_fd(basemaj[nbr % 16], fd);
	return (rsize);
}

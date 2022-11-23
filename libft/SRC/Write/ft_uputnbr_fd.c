/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:43:29 by mjuin             #+#    #+#             */
/*   Updated: 2022/10/12 12:33:41 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

size_t	ft_uputnbr_fd(unsigned int nbr, int fd)
{
	size_t	size;

	size = 0;
	if (nbr > 9)
	{
		size += ft_uputnbr_fd(nbr / 10, fd);
	}
	size += ft_putchar_fd(((nbr % 10) + '0'), fd);
	return (size);
}

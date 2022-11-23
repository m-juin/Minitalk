/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_bin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjuin <mjuin@student.42angouleme.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 19:55:41 by mjuin             #+#    #+#             */
/*   Updated: 2022/11/05 21:50:12 by mjuin            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

unsigned char	ft_convert_bin(int binary[8])
{
	int				pos;
	unsigned char	c;

	pos = 0;
	c = 0;
	while (pos < 8)
	{
		c += binary[pos] * (ft_power(7 - pos, 2));
		pos++;
	}
	return (c);
}

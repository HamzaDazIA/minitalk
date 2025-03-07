/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsignd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 03:51:36 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/07 03:51:37 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_unsignd(unsigned int n)
{
	long	nb;
	int		how_mprint;

	how_mprint = 0;
	nb = n;
	if (nb > 9)
	{
		how_mprint += ft_putnbr(nb / 10);
		how_mprint += ft_putchar((nb % 10) + '0');
	}
	else
		how_mprint += ft_putchar(nb + '0');
	return (how_mprint);
}

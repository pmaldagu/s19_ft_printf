/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:22:34 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/15 19:27:23 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_base(int nb, int base)
{
	if (nb <= (base - 1) && nb >= 0)
		ft_putchar(nb + 48);
	else if (nb > (base - 1))
	{
		ft_putnbr_base(nb / base, base);
		ft_putnbr_base(nb % base, base);
	}
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		ft_putchar('-');
		ft_putnbr_base((nb * -1), base);
	}
}

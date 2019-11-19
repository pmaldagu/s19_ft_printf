/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/08 16:22:34 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/15 19:45:25 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr_hex(int nb, int cas)
{
	char *hex;
	char hexm[] = "0123456789abcdef";
	char hexM[] = "0123456789ABCDEF";

	if (cas == 0)
		hex = hexm;
	else
		hex = hexM;
	if (nb <= 15 && nb >= 0)
		ft_putchar(hex[nb]);
	else if (nb > 15)
	{
		ft_putnbr_hex(nb / 16, cas);
		ft_putnbr_hex(nb % 16, cas);
	}
	else
		ft_putnbr_hex((nb * -1), cas);
}

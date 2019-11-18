/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:28:11 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/16 17:15:30 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void 	ft_putstr(char *print, long int nb)
{
	unsigned long int i;
	
	i = 0;
	if (print == NULL)
	{
		write(1 , "Error\n", 6);
		return ;
	}
	if (nb == 0)
		write(1, "0x", 20);
	while (print[i] != 0)
	{
		write(1, &print[i], 1);
		i++;
	}
}

static unsigned long int	ft_msize(unsigned long int nb, int base)
{
	unsigned long int i;

	i = 1;
	//if (nb < 0)
	//	i++;
	while (nb /= base)
		i++;
	return (i);
}

void	ft_itoa_base(unsigned long int unb, long int nb, int base, char cas)
{
	char	*nbr;
	char	*hex;
	char	hexm[] = "0123456789abcdef";
	char	hexM[] = "0123456789ABCDEF";
	int	size;
	//int	sign;

	//nb < 0 ? unb = nb * 1: unb;
	//nb > 0 ? unb = nb : unb;
	//sign = 0;
	cas == 'm' ? hex = hexm : hex;
	cas == 'M' ? hex = hexM : hex;
	size = ft_msize(nb, base);
	if (nb < 0)
	//{
//		sign = 1;
		nb *= -1;
	//}
	if ((nbr = malloc(sizeof(char) * (size + 1))))
	{
		nbr[size] = '\0';
		while (nb / base != 0)
		{
			if (base == 16)
				nbr[--size] = hex[nb % 16];
			else
				nbr[--size] = (nb % base) + 48;
			nb /= base;
		}
		if (base == 16)
			nbr[--size] = hex[nb % 16];
		else
			nbr[--size] = (nb % base) + 48;
		//sign == 1 ? nbr[0] = '-' : nb;
		ft_putstr(nbr, nb);
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:17:47 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 16:13:07 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static unsigned long	ft_msize(unsigned long nb)
{
	unsigned long	i;

	i = 0;
	while (nb /= 16)
		i++;
	return (i);
}

char					*ft_hexadress(unsigned long nb)
{
	char			*hex;
	char			*nbr;
	int				len;

	hex = ft_strdup("0123456789abcdef");
	len = ft_msize(nb) + 3;
	if ((nbr = malloc(sizeof(char) * (len + 1))))
	{
		nbr[len] = '\0';
		nbr[0] = '0';
		nbr[1] = 'x';
		while (nb / 16)
		{
			nbr[--len] = hex[nb % 16];
			nb /= 16;
		}
		nbr[--len] = hex[nb % 16];
		ft_free(hex);
		return (nbr);
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 16:17:47 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/18 17:03:17 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char *ft_cas(char cas)
{
	if (cas == 'm')
		return (ft_strdup("0123456789abcdef"));
	else
		return(ft_strdup("0123456789ABCDEF"));
}

static size_t ft_msize(size_t nb, int base)
{
	size_t i;

	i = 0;
	while (nb /= base)
		i++;
	return (i + 1);
}

char *ft_itoa_ubase(size_t nb, int base, char cas)
{
	char *hex;
	char *nbr;
	int len;
	
	hex = ft_cas(cas);
	len = ft_msize(nb, base);
	if ((nbr = malloc(sizeof(char) * (len + 1))))
	{
		nbr[len] = '\0';
		while (nb / base)
		{
			if (base == 16)
				nbr[--len] = hex[nb % 16];
			else
				nbr[--len] = (nb % base) + 48;
			nb /= base;
		}
		if ( base == 16)
			nbr[--len] = hex[nb % 16];
		else
			nbr[--len] = (nb % base) + 48;
		free(hex);
		return (nbr);
	}
	return (NULL);
}

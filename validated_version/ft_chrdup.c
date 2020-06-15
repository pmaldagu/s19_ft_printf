/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:50 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/16 20:25:52 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_chrdup(char c)
{
	int		i;
	char	*s2;

	i = 0;
	if (c == 0)
		return (0);
	if ((s2 = malloc(sizeof(char) * 2)) != NULL)
	{
		s2[0] = c;
		s2[1] = '\0';
		return (s2);
	}
	return (NULL);
}

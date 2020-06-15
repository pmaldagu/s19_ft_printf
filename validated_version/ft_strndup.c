/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 10:06:50 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/16 18:06:46 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strndup(const char *s1, size_t size)
{
	size_t		i;
	char		*s2;

	i = 0;
	if ((s2 = malloc(sizeof(*s2) * (size + 1))) != NULL)
	{
		while (i < size)
		{
			s2[i] = s1[i];
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	return (NULL);
}

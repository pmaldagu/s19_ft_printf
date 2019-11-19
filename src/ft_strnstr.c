/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:57:13 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/10/21 17:09:33 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	if (n[i] == 0)
		return ((char *)h);
	while (h[i] != '\0')
	{
		j = 0;
		while (h[i + j] == n[j] && (i + j) < len)
		{
			j++;
			if (n[j] == '\0')
				return (&((char *)h)[i]);
		}
		i++;
	}
	return (NULL);
}

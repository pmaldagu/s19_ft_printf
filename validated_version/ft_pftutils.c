/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pftutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 16:05:07 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 16:19:06 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	ft_convers(char format, char type)
{
	size_t	i;
	char	*cvs;
	char	*cvn;
	char	*cv;

	i = 0;
	cvs = "cspdiouxX%";
	cvn = "csp";
	if (type == 's')
		cv = cvs;
	else
		cv = cvn;
	while (cv[i] != '\0')
	{
		if (format == cv[i])
			return (format);
		i++;
	}
	return (0);
}

void	ft_free(char *heap)
{
	if (heap != NULL)
		free(heap);
}

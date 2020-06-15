/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:15:10 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 15:49:15 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		ft_wildcard(int card, t_db *vl, va_list ap)
{
	int trash;

	if (vl->card == 1 && vl->nb == 0)
	{
		vl->nb = va_arg(ap, int);
		if (vl->nb < 0)
			vl->zero = 0;
	}
	else if (vl->card == 1 && vl->nb != 0)
		trash = va_arg(ap, int);
	if (card == 1 && vl->pre == 0)
		vl->pre = va_arg(ap, int);
	else if (card == 1 && vl->pre != 0)
		trash = va_arg(ap, int);
}

int			ft_dotcheck(char format, t_db *vl)
{
	if (format == '.')
	{
		vl->dot = 1;
		return (1);
	}
	return (0);
}

char		*ft_precision(char *format, t_db *vl, va_list ap)
{
	size_t	i;
	int		sign;
	int		card;

	sign = 0;
	card = 0;
	i = ft_dotcheck(format[0], vl);
	while (ft_isvalid(format[i]) == 1 || format[i] == '*' || format[i] == '.')
	{
		if (format[i] == '-')
		{
			sign = 1;
			vl->pre = 0;
		}
		else if (format[i] == '*')
			card = 1;
		else if (ft_isspace(format[i]) == 0 && format[i] != '.')
			vl->pre = ((vl->pre * 10) + (format[i] - 48));
		i++;
	}
	if (card == 1 || vl->card == 1)
		ft_wildcard(card, vl, ap);
	if (sign == 1 && vl->pre > 0)
		vl->pre *= -1;
	return (&format[i]);
}

int			ft_zerocheck(char format, t_db *vl)
{
	if (format == '0')
	{
		vl->zero = 1;
		return (1);
	}
	return (0);
}

char		*ft_modifier(char *format, t_db *vl, va_list ap)
{
	size_t	i;
	int		sign;

	sign = 0;
	i = ft_zerocheck(format[0], vl);
	while (ft_isvalid(format[i]) == 1)
	{
		if (format[i] == '-')
		{
			vl->nb = 0;
			vl->zero = 0;
			sign = 1;
		}
		else if (format[i] == '*')
			vl->card = 1;
		else if (ft_isspace(format[i]) == 0)
			vl->nb = ((vl->nb * 10) + (format[i] - 48));
		i++;
	}
	format = ft_precision(&format[i], vl, ap);
	if (sign == 1 && vl->nb > 0)
		vl->nb *= -1;
	return ((vl->cv = ft_convers(format[0], 's')) != 0 ? format : format);
}

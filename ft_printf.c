/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:37:05 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 16:15:35 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_nwstruct(t_db *vl)
{
	vl->result = NULL;
	vl->cnull = 0;
	vl->zero = 0;
	vl->card = 0;
	vl->dot = 0;
	vl->nb = 0;
	vl->pre = 0;
	vl->cv = 0;
}

void	ft_result(t_db *vl, va_list ap)
{
	char *tmp;

	if ((tmp = ft_conversion(vl->cv, ap)) == NULL)
	{
		if (vl->cv == 's')
			tmp = ft_strdup("(null)");
		else
			tmp = ft_calloc(1, 1);
		if (vl->cv == 'c')
		{
			if (vl->nb < 0)
				vl->nb += 1;
			else if (vl->nb > 0)
				vl->nb -= 1;
			vl->cnull = 1;
		}
		vl->result = ft_flg0(tmp, vl);
	}
	else
		vl->result = ft_flg0(tmp, vl);
}

int		ft_wrtmod(t_db *vl)
{
	if (vl->nb >= 0 && vl->cnull == 1)
	{
		ft_putncount(vl->result, 0, vl);
		ft_putncount(NULL, '\0', vl);
	}
	else if (vl->nb < 0 && vl->cnull == 1)
	{
		ft_putncount(NULL, '\0', vl);
		ft_putncount(vl->result, 0, vl);
	}
	else if (ft_convers(vl->cv, 's') > 0)
		ft_putncount(vl->result, 0, vl);
	ft_free(vl->result);
	return (0);
}

void	ft_strcheck(char *format, t_db *vl, va_list ap)
{
	size_t	i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format = ft_modifier(&format[i + 1], vl, ap);
			ft_result(vl, ap);
			i = ft_wrtmod(vl);
			if (ft_convers(format[i], 's') > 0)
				i = 1;
			ft_nwstruct(vl);
		}
		else if (vl->cv == 0)
		{
			ft_putncount(NULL, format[i], vl);
			i++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	char	*fmt;
	va_list	ap;
	t_db	vl;

	vl.cchr = 0;
	if (format == NULL)
		return (0);
	fmt = (char*)format;
	ft_nwstruct(&vl);
	va_start(ap, format);
	ft_strcheck(fmt, &vl, ap);
	va_end(ap);
	return (vl.cchr);
}

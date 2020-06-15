/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:37:05 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 16:12:45 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putncount(char *str, char c, t_db *vl)
{
	size_t i;
	size_t len;

	i = 0;
	if (vl->cnull == 1 && str != NULL)
		len = ft_strlen(str) - 1;
	if (str != NULL)
	{
		len = ft_strlen(str);
		write(1, str, len);
		vl->cchr += len;
	}
	else
	{
		write(1, &c, 1);
		vl->cchr += 1;
	}
}

int		ft_isvalid(char c)
{
	if (ft_isspace(c) == 1)
		return (1);
	else if (ft_isdigit(c) == 1)
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (1);
	else
		return (0);
}

char	*ft_conversion(char type, va_list ap)
{
	if (type == 'c')
		return (ft_chrdup(va_arg(ap, int)));
	else if (type == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (type == 'u')
		return (ft_utoa_base(va_arg(ap, unsigned int), 10, 'm'));
	else if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (type == 'o')
		return (ft_utoa_base(va_arg(ap, unsigned int), 8, 'm'));
	else if (type == 'x')
		return (ft_utoa_base(va_arg(ap, unsigned int), 16, 'm'));
	else if (type == 'X')
		return (ft_utoa_base(va_arg(ap, unsigned int), 16, 'M'));
	else if (type == 'p')
		return (ft_hexadress(va_arg(ap, unsigned long)));
	else if (type == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

char	*ft_noflg(char *arg, t_db *vl)
{
	char	*spce;
	char	*tmp;
	int		abs;

	if (vl->nb < 0)
		abs = vl->nb * -1;
	else
		abs = vl->nb;
	if (vl->zero == 0 && abs > (int)ft_strlen(arg))
	{
		abs = abs - (int)ft_strlen(arg);
		spce = ft_calloc(1, abs + 1);
		ft_memset(spce, ' ', abs);
		tmp = arg;
		if (vl->nb > 0)
			arg = ft_strjoin(spce, arg);
		else
			arg = ft_strjoin(arg, spce);
		ft_free(tmp);
		ft_free(spce);
	}
	return (arg);
}

char	*ft_flg0(char *arg, t_db *vl)
{
	char	*zer0;
	char	*tmp;

	arg = ft_dotnull(arg, vl);
	if (vl->zero == 1 \
			&& vl->cv != 'p' && vl->nb > (int)ft_strlen(arg))
	{
		vl->nb = vl->nb - (int)ft_strlen(arg);
		zer0 = ft_calloc(1, vl->nb + 1);
		ft_memset(zer0, '0', vl->nb);
		tmp = arg;
		if (arg[0] == '-')
		{
			zer0[0] = '-';
			arg[0] = '0';
		}
		arg = ft_strjoin(zer0, arg);
		ft_free(tmp);
		ft_free(zer0);
	}
	arg = ft_noflg(arg, vl);
	return (arg);
}

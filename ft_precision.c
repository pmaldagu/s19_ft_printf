/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:37:05 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 16:21:25 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dotnull(char *arg, t_db *vl)
{
	if (vl->dot == 1 && vl->cv == '%')
		vl->dot = 0;
	else if (vl->cv == 'p' && arg[3] == 0 && ft_strlen(arg) == 3 \
			&& vl->dot == 1 && vl->pre == 0)
	{
		ft_free(arg);
		arg = ft_strdup("0x");
		vl->dot = 0;
	}
	else if (vl->cv == 'p' && arg[3] == 0 && ft_strlen(arg) == 3 \
			&& vl->dot == 0 && vl->zero == 1)
	{
		if (vl->nb > 5)
			vl->pre = vl->nb - 2;
		vl->dot = 1;
	}
	else if (arg[0] == '0' && vl->pre == 0 && vl->dot == 1 && vl->cv != 'p')
	{
		ft_free(arg);
		arg = ft_calloc(1, 1);
	}
	return (ft_dot_0(arg, vl));
}

char	*ft_dot_0(char *arg, t_db *vl)
{
	char	*tmp;

	if (vl->dot == 1 && (vl->cv == 'd' || vl->cv == 'u' || vl->cv == 'i') \
			&& vl->pre == 0)
		vl->zero = 0;
	else if (vl->dot == 1 && vl->pre <= 0 && vl->cv == 'd')
		vl->dot = 0;
	else if (vl->dot == 1 && vl->pre == 0 && (vl->cv == 'X' || vl->cv == 'x'))
		vl->zero = 0;
	else if (vl->dot == 1 && vl->pre <= 0 && (vl->cv == 'X' || vl->cv == 'x'))
		vl->dot = 0;
	else if (vl->dot == 1 && vl->pre < 0 && (vl->cv == 'i' || vl->cv == 'u'))
		vl->dot = 0;
	else if (vl->dot == 1 && vl->pre < 0 && vl->cv == 's')
		vl->dot = 0;
	else if (vl->dot == 1 && vl->pre < (int)ft_strlen(arg) \
			&& vl->pre > -1 && vl->cv == 's')
	{
		tmp = arg;
		arg = ft_strndup(arg, vl->pre);
		ft_free(tmp);
	}
	return (ft_dot_1(arg, vl));
}

char	*ft_dot_1(char *arg, t_db *vl)
{
	if (vl->dot == 1 && vl->pre < 0)
	{
		vl->nb = vl->pre;
		vl->zero = 0;
		if (vl->cv == 's')
		{
			ft_free(arg);
			arg = ft_calloc(1, 1);
		}
	}
	else if (vl->dot == 1 && vl->pre == 0 && ft_convers(vl->cv, 'n') == 1 \
			&& vl->cv != 'p')
	{
		ft_free(arg);
		arg = ft_calloc(1, 1);
	}
	else if (vl->dot == 1 && vl->pre > 0 \
			&& vl->pre < (int)ft_strlen(arg) && ft_convers(vl->cv, 'n') == 0)
		vl->zero = 0;
	return (ft_dot_2(arg, vl));
}

char	*ft_dot_2(char *arg, t_db *vl)
{
	char	*dot;
	char	*tmp;

	if (vl->dot == 1 && vl->pre >= (int)ft_strlen(arg) \
			&& ft_convers(vl->cv, 'n') == 0 && vl->cv != 0)
	{
		vl->zero = 0;
		vl->pre -= ft_strlen(arg);
		dot = ft_calloc(1, vl->pre + 1);
		ft_memset(dot, '0', vl->pre);
		tmp = arg;
		if (arg[0] == '-')
		{
			arg[0] = '0';
			arg = dot;
			dot = ft_strjoin(dot, tmp);
			ft_free(arg);
			arg = ft_strjoin("-", dot);
		}
		else
			arg = ft_strjoin(dot, arg);
		ft_free(dot);
		ft_free(tmp);
	}
	return (ft_dot_3(arg, vl));
}

char	*ft_dot_3(char *arg, t_db *vl)
{
	char	*dot;
	char	*tmp;
	char	*heap;

	if (vl->dot == 1 && vl->pre >= (int)ft_strlen(arg) && vl->cv == 'p')
	{
		vl->zero = 0;
		vl->pre -= ft_strlen(arg);
		dot = ft_calloc(1, vl->pre + 1);
		ft_memset(dot, '0', vl->pre);
		heap = dot;
		tmp = arg;
		arg[1] = '0';
		dot = ft_strjoin(dot, arg);
		arg = ft_strjoin("0x", dot);
		ft_free(dot);
		ft_free(tmp);
		ft_free(heap);
	}
	return (arg);
}

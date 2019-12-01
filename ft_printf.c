/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:37:05 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/01 20:41:52 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

/*typedef struct			 s_var
{
	int zero;
	int card;
	size_t nb;
	size_t pre;
	char cv;
}						mod;			
*/
static char ft_convers(char format, char type)
{
	size_t i;
	char *cvs;
	char *cvn;
	char *cv;

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

static void ft_wildcard(int card, mod *value, va_list ap)
{
	if (value->card == 1)
		value->nb = va_arg(ap, int);
	if (card == 1)
		value->pre = va_arg(ap, int);
}

static char *ft_precision(char *format, mod *value, va_list ap)
{
	size_t i;
	int sign;
	int card;

	i = 0;
	sign = 0;
	card = 0;
	if (format[i] == '.')
	{
		value->dot = 1;
		i++;
	}
	while (ft_isdigit(format[i]) == 1 || format[i] == '-' || format[i] == '*')
	{
		if (format[i] == '-')
		{
			sign = 1;
			value->pre = 0;
		}
		else if (format[i] == '*')
			card = 1;
		else
			value->pre = ((value->pre * 10) + (format[i] - 48));
		i++;
	}
	if (card == 1 || value->card == 1 )
		ft_wildcard(card, value, ap);
	if (sign == 1 && value->pre > 0)
		value->pre *= -1;
	return (&format[i]);
}
	
static char *ft_modifier(char *format, mod *value, va_list ap)
{
	size_t i;
	int sign;

	i = 0;
	sign = 0;	
	if (format[i] == '0')
	{
		value->zero = 1;
		i++;
	}
	while (ft_isdigit(format[i]) == 1 || format[i] == '-' || format[i] == '*')
	{
		if (format[i] == '-')
		{
			value->nb = 0;
			value->zero = 0;
			sign = 1;
		}
		else if (format[i] == '*')
			value->card = 1;
		else
			value->nb = ((value->nb * 10) + (format[i] - 48));
		i++;
	}
	format = ft_precision(&format[i], value, ap);
	if (sign == 1 && value->nb > 0)
		value->nb *= -1;
	return ((value->cv = ft_convers(format[0], 's')) != 0 ? format : format);
}

static void  ft_nwstruct(mod *value)
{
	value->zero = 0;
	value->card = 0;
	value->dot = 0;
	value->nb = 0;
	value->pre = 0;
	value->cv = 0;	
}

static char *ft_noflg(char *arg, mod *value)
{
	char *spce;
	char *tmp;
	int abs;

	if (value->nb < 0)
		abs = value->nb * -1;
	else
		abs = value->nb;
	if (value->zero == 0 && abs > (int)ft_strlen(arg) && value->cv != 'p')
	{
		abs = abs - (int)ft_strlen(arg);
		spce = ft_calloc(1, abs + 1);
		ft_memset(spce, ' ', abs);
		tmp = arg;
		if (value->nb > 0)
			arg = ft_strjoin(spce, arg);
		else
			arg = ft_strjoin(arg, spce);
		free(tmp);
		free(spce);
	}
	return (arg);
}

static char *ft_dot(char *arg, mod *value)
{
	char *dot;
	char *tmp;

	if (value->dot == 1 && value->pre < (int)ft_strlen(arg) && value->pre > -1 && value->cv == 's')
	{
		tmp = arg;
		arg = ft_strndup(arg, value->pre);
		value->cv = 'd';
		//free(tmp);
	}
	else if (value->dot == 1 && value->pre < 0)
	{
		value->nb = value->pre;
		value->zero = 0;
		if (value->cv == 's')
			arg = ft_calloc(1, 1);
	}
	else if (value->dot == 1 && value->pre > (int)ft_strlen(arg) && ft_convers(value->cv, 'n') == 0)
	{
		//printf("\nvalue->pre = %d\n", value->pre);
		value->zero = 0;
		value->pre -= ft_strlen(arg);
		//printf("\nvalue->pre2 = %d\n", value->pre);
		dot = ft_calloc(1, value->pre + 1);
		ft_memset(dot, '0', value->pre);
		tmp = arg;
		//printf("\narg[0] = %c\n", arg[0]);
		//printf("\nvdot = %s\n", dot);
		if (arg[0] == '-')
		{
			arg[0] = '0';
			dot = ft_strjoin(dot, arg);
			arg = ft_strjoin("-", dot);
		}
		else
			arg = ft_strjoin(dot, arg);
		//free(dot);
		//free(tmp);
		//printf("\narg = %s\n", arg);
	}
	return (arg);
}

static char *ft_flg0(char *arg, mod *value)
{
	char *zer0;
	char *tmp;

	arg = ft_dot(arg, value);
	if (value->zero == 1 && ft_convers(value->cv, 'n') == 0 && value->nb > (int)ft_strlen(arg))
	{
		value->nb = value->nb - (int)ft_strlen(arg);
		zer0 = ft_calloc(1, value->nb + 1);
		ft_memset(zer0, '0', value->nb);
		tmp = arg;
		if (arg[0] == '-')
		{
			zer0[0] = '-';
			arg[0] = '0';
		}
		arg = ft_strjoin(zer0, arg);
		free(tmp);
		free(zer0);
	}
	arg = ft_noflg(arg, value);
	return (arg);
}
			
static void ft_strcheck(char *format, mod *value, va_list ap)
{
	size_t i;
	char *tmp;
	char *line;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format = ft_modifier(&format[i + 1], value, ap);
			tmp = ft_conversion(value->cv, ap);
			line = ft_flg0(tmp, value);
			ft_putstr_fd(line, 1);
			//free(line);
			//free(tmp);
			//ft_nwstruct(value);
			//printf("\nfomat[0] = %c\n", format[0]);
			i = 0;
			if (value->cv > 0)
				i = 1;
			ft_nwstruct(value);
		}
		else if (value->cv == 0)
		{
			write(1, &format[i], 1);
			i++;
		}
	}
	//printf("\ntmp = %s\n", tmp);
}

int ft_printf(const char *format, ...)
{
	char *fmt;
	va_list ap;
	mod value;

	fmt = (char*)format;
	ft_nwstruct(&value);
	va_start(ap, format);
	ft_strcheck(fmt, &value, ap);
	//printf("zero = %d\n", value.zero);
	//printf("card = %d\n", value.card);
	//printf("nb = %d\n", value.nb);
	//printf("pre = %d\n", value.pre);
	//printf("cv = %c\n", value.cv);
	va_end(ap);
	return(1);
}

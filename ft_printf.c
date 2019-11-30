/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_patoi.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 13:37:05 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/30 20:56:01 by pmaldagu         ###   ########.fr       */
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
		i++;
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
	if (format[i++] == '0')
		value->zero = 1;
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
	value->nb = 0;
	value->pre = 0;
	value->cv = 0;	
}

char *ft_flg0(char *arg, mod *value)
{
	char *zer0;
	char *tmp;

	if (value->zero == 1 && ft_convers(value->cv, 'n') == 0 && value->nb > (int)ft_strlen(arg))
	{
		value->nb = value->nb - (int)ft_strlen(arg);
		zer0 = ft_calloc(1, value->nb + 1);
		ft_memset(zer0, '0', value->nb);
		tmp = arg;
		arg = ft_strjoin(zer0, arg);
		free(tmp);
		free(zer0);
	}
	return (arg);
}
			
static void ft_strcheck(char *format, mod *value, va_list ap)////////////
{
	size_t i;
	char *tmp;
	//char *line;

	i = 0;
	//line = "";
	//write(1, "okcheck\n", 8);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			format = ft_modifier(&format[i + 1], value, ap);
			//write(1, "loop\n", 5); 
			//printf("value->cv = %c\n", value->cv);
			tmp = ft_conversion(value->cv, ap);
			tmp = ft_flg0(tmp, value);
			//line = ft_strjoin(line, 
		}
		else
			i++;
	}
	printf("tmp = %s\n", tmp);
}

int ft_printf(const char *format, ...)
{
	char *fmt;
	va_list ap;
	mod value;

	fmt = (char*)format;
	ft_nwstruct(&value);
	va_start(ap, format);
	//printf("structok = %d\n", value.zero);
	ft_strcheck(fmt, &value, ap);
	printf("zero = %d\n", value.zero);
	printf("card = %d\n", value.card);
	printf("nb = %d\n", value.nb);
	printf("pre = %d\n", value.pre);
	printf("cv = %c\n", value.cv);
	va_end(ap);
	return(1);
}

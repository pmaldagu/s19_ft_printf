/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 12:52:22 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/27 18:51:57 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

///////////conversions :
//c = le premier byte de l'argument, character. V
//s = la chaine de caractere V
//p = adresse du pointeur en hexadecimal
//d ou i = decimal signed V
//o = unsigned octal
//u = unsigned decimal V
//X ou x = unsigned hexadecimal avec majuscule ou minuscule

/////////flags :
//- = des espaces a droite
//0 = remplir avec des zero gauche
//. = mix de 0 et -, ex 
//* = 

#include "libft.h"

//static void	ft_putchar(char c)
//{
//	write(1, &c, 1);
//}

static void	ft_putstr(char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

static char	*ft_conversion(char type, va_list ap)
{
	if (type == 'c')
		return (ft_chrdup(va_arg(ap, int)));
	else if (type == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (type == 'u')
		return (ft_itoa_ubase(va_arg(ap, unsigned int), 10, 'm'));
	else if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (type == 'o')
		return (ft_itoa_ubase(va_arg(ap, unsigned int), 8, 'm'));
	else if (type == 'x')
		return (ft_itoa_ubase(va_arg(ap, unsigned int), 16, 'm'));
	else if (type == 'X')
		return (ft_itoa_ubase(va_arg(ap, unsigned int), 16, 'M'));
	else if (type == 'p')
		return (ft_hexadress(va_arg(ap, unsigned long)));
	else if (type == '%')
		return (ft_strdup("%"));
	else
		return (NULL);
}

static char  *ft_modifier(char *format, char flags, va_list ap)
{
	size_t i;
	size_t j;
	char *mod;
	size_t nb;
	size_t pre;
	long int k;
	char *arg;

	i = 0;
	j = 0;
	pre = 0;
	arg = NULL;
	mod = ft_calloc(1, 1);
	if (format[i] == '*')
	{
		i++;
		k = ft_atoi(ft_itoa(va_arg(ap, int)));
		if (k < 0)
		{
			nb = k * -1;
			flags = '-';
		}
		else
			nb = k;
		arg = ft_conversion(format[i], ap); 
	}
	else
	{
		while ((arg = ft_conversion(format[i], ap)) == NULL && ft_isdigit(format[i]) != 0)
		{
			mod = ft_strjoin(mod, ft_chrdup(format[i]));
			i++;
		}
		nb = ft_atoi(mod);
	}
	free(mod);
	if (arg != NULL && nb > ft_strlen(arg))
	{
		if (flags == '0')
		{
			nb = nb - ft_strlen(arg);
			mod = ft_calloc(1, nb + 1);
			ft_memset(mod , '0', nb);
			if (arg[0] == '-')
			{
				arg[0] = '0';
				mod[0] = '-';
			}
			ft_putstr(ft_strjoin(mod, arg));
			free(mod);
			free(arg);
		}
		if (flags == '-')
		{
			nb = nb - ft_strlen(arg);
			mod = ft_calloc(1, nb + 1);
			ft_memset(mod, ' ', nb);
			ft_putstr(ft_strjoin(arg, mod));
			free(mod);
			free(arg);
		}
		if (flags == 0)
		{
			nb = nb - ft_strlen(arg);
			mod = ft_calloc(1, nb + 1);
			ft_memset(mod, ' ', nb);
			ft_putstr(ft_strjoin(mod, arg));
			free(mod);
			free(arg);
		}
	}
	else if (format[i] == '.')
	{
		i++;
		mod = ft_calloc(1, 1);
		if (format[i] == '*')
		{
			i++;
			k = ft_atoi(ft_itoa(va_arg(ap, int)));
			if (k < 0)
			{
				pre = k * -1;
				flags = '-';
			}
			else
				pre = k;
			arg = ft_conversion(format[i], ap); 
		}
		else
		{
			while ((arg = ft_conversion(format[i], ap)) == NULL && ft_isdigit(format[i]) != 0)
			{
				mod = ft_strjoin(mod, ft_chrdup(format[i]));
				i++;
			}
			pre = ft_atoi(mod);
			k = 1;
		}
		free(mod);
		if (pre > ft_strlen(arg) && k > 0)
		{
			pre = pre - ft_strlen(arg);
			mod = ft_calloc(1, pre + 1);
			ft_memset(mod, '0', pre);
			if (arg[0] == '-')
			{
				arg[0] = '0';
				arg = ft_strjoin(mod, arg);
				arg = ft_strjoin("-", arg);
			}
			else
				arg = ft_strjoin(mod, arg);
			free(mod);
		}
		else
			flags = 0;
		if (nb > ft_strlen(arg))
		{
			nb = nb - ft_strlen(arg);
			mod = ft_calloc(1, nb + 1);
			ft_memset(mod, ' ', nb);
			if (flags == '-')
				arg = ft_strjoin(arg, mod);
			else
				arg = ft_strjoin(mod, arg);
			ft_putstr(arg);
			free(mod);
			free(arg);
		}
		else 
			ft_putstr(arg);
		return (&format[i + j]);
	}		
	else
	{
		ft_putstr(arg);
		free(arg);
	}
	return (&format[i]);
}

static char	*ft_flags(char *format, va_list ap)
{
	int i;
	char *mod;

	i = 0;
	mod = 0;
	if (format[i] == '0')
		return (ft_modifier(&format[i + 1], '0', ap));
	else if (format[i] == '-')
		return (ft_modifier(&format[i + 1], '-', ap));
	else if (format[i] == '%')
	{
		write(1, "%", 1);
		return (&format[i]);
	}
	else
		return (ft_modifier(&format[i], 0, ap));
}

static void	ft_convertcheck(const char *format, va_list ap)
{
	size_t i;
	char *form;

	i = 0;
	form = ft_strdup(format);
	while (form[i] != '\0')
	{
		if (form[i] == '%')
		{
			form = ft_flags(&form[i + 1], ap);
			i = 0;
		}
		else
			write(1, &form[i], 1);
		i++;
	}
}

int		ft_printf(const char *format, ...)
{
	va_list ap;

	va_start(ap, format);
	ft_convertcheck(format, ap);
	va_end(ap);
	return (1);
}

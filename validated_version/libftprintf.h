/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 17:39:33 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/19 16:29:30 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct		s_var
{
	char			*result;
	int				cnull;
	int				zero;
	int				card;
	int				dot;
	long long int	nb;
	long long int	pre;
	char			cv;
	int				cchr;
}					t_db;

int					ft_printf(const char *format, ...);

char				*ft_utoa_base(size_t nb, int base, char cas);
char				*ft_hexadress(unsigned long nb);
char				*ft_chrdup(char c);
char				*ft_strndup(const char *s1, size_t size);
int					ft_isspace(int c);

void				ft_free(char *heap);
char				ft_convers(char format, char type);

void				ft_wildcard(int card, t_db *vl, va_list ap);
int					ft_dotcheck(char format, t_db *vl);
char				*ft_precision(char *format, t_db *vl, va_list ap);
int					ft_zerocheck(char format, t_db *vl);
char				*ft_modifier(char *format, t_db *vl, va_list ap);

char				*ft_dotnull(char *arg, t_db *vl);
char				*ft_dot_0(char *arg, t_db *vl);
char				*ft_dot_1(char *arg, t_db *vl);
char				*ft_dot_2(char *arg, t_db *vl);
char				*ft_dot_3(char *arg, t_db *vl);

char				*ft_conversion(char type, va_list ap);
char				*ft_noflg(char *arg, t_db *vl);
char				*ft_flg0(char *arg, t_db *vl);
void				ft_putncount(char *str, char c, t_db *vl);
int					ft_isvalid(char c);

void				ft_nwstruct(t_db *vl);
void				ft_result(t_db *vl, va_list ap);
int					ft_wrtmod(t_db *vl);
void				ft_strcheck(char *format, t_db *vl, va_list ap);

#endif

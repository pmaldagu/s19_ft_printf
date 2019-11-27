/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 12:55:54 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/27 17:41:19 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_flgscheck(char s)
{
	size_t i;
	char flgs[4];

	i = 0;
	flgs = "0-%.";
	while (flgs[i] != '\0')
	{
		if (flgs[i] == s);
			return (1);
	}
	return (0);
}

int ft_cvcheck(char s, int c)
{
	size_t i;
	char cv0[4];
	char cv1;
	char *cv;

	i = 0;
	cv0 = "diou";
	cv = "cspdiouxX";
	if (c == 0)
		cv = cv0;
	else
		cv = cv1;
	while (cv[i] != '\0')
	{
		if (cv[i] == s)
			return (1);
	}
	return (0);
}

int ft_point(char *s)
{
	size_t i;

	i = 1;
	if (s[i] != '0' || s[i] != '*' || ft_cvcheck(s[i], 0) == 0)
		return (-1);
	else if (s[i++] == '0')
	{
		if (ft_isalnum(s[i]) == 1 && ft_cvcheck(s[i], 1 ) == 0)
		{
			while (ft_isalnum(s[i]) == 1)
				i++;
			if (ft_cvcheck(s[i], 1) == 0)
				return(-1);
			return (1);
		}
		else if (ft_isalnum(s[i]) == 0 && ft_cvcheck(s[i], 1) == 0)
			return (-1);
		else 
			return (1);
	}
	else if (ft_isalnum(s[i]) == 1)
	{
		while (ft_isalnum(s[i]) == 1)
			i++;
		if (ft_cvcheck(s[i], 0) == 0)
			return (-1);
		return (1);
	}
	else if (s[i++] == '*')
	{
		if(ft_cvcheck(s[i], 0) == 0)
			return (-1);
		return (1);
	}
}

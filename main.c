/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:26:37 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/30 20:57:14 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	char str[] = "calcul";
	int a = 5;
	int b = -333;
	unsigned int i = -333;
	//int j = 30;

	printf("\n=============== MON PRINTF ===============\n\n");
	ft_printf("%0*.-c", 23, 48, 56);
	//printf("\n\n================= PRINTF =================\n\n");
	//printf("le resultat du %15s de %5.*i + %010-----6-5d %0-50%  end", str, a, b, i);
	//printf("\n=============== HEX ADRSS ================\n\n");
	//printf("%s\n", ft_hexadress );
	return (0);
}

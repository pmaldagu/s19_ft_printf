/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:26:37 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/27 18:48:55 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	char str[] = "calcul";
	int a = 10;
	int b = -333;
	unsigned int i = -333;
	//int j = 30;

	printf("\n=============== MON PRINTF ===============\n\n");
	ft_printf("le resultat du %p de %5.*d + %05d", str, a, b, i);
	printf("\n\n================= PRINTF =================\n\n");
	printf("le resultat du %p de %5.*d + %05d ", str, a, b, i);
	//printf("\n=============== HEX ADRSS ================\n\n");
	//printf("%s\n", ft_hexadress );
	return (0);
}

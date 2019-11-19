/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:26:37 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/11/19 18:18:39 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	char str[] = "calcul";
	char a = 'a';
	int b = -333;
	unsigned int i = -333;
	//int j = 30;

	printf("\n=============== MON PRINTF ===============\n\n");
	ft_printf("le resultat du %p de %16.4d + %x = %X\n", str, a , b, i);
	printf("\n================= PRINTF =================\n\n");
	printf("le resultat du %p de %16.4d + %x = %X\n", str, a , b, i);
	//printf("\n=============== HEX ADRSS ================\n\n");
	//printf("%s\n", ft_hexadress );
	return (0);
}

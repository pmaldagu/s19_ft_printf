/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 13:26:37 by pmaldagu          #+#    #+#             */
/*   Updated: 2019/12/11 20:06:26 by pmaldagu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int main()
{
	char str[] = "calcul";
	int a = 'a';
	int b = 3;
	unsigned int i = -333;
	//int j = 30;

	printf("\n=============== MON PRINTF ===============\n\n");
	//ft_printf("%-196.9s%087.124d%0.x%*c===" ,"h:N{",1475099643,662365497u,-166,0);
	//ft_printf("%-96c%-*c===" ,0,59,-54);
	//ft_printf("%-38c%-160p%*c" ,0,(void*)16025742189089525589lu,161,-6);
	ft_printf("%-196c%000127.1i" ,0,1096795813);
	printf("\n\n================= PRINTF =================\n\n");
	//printf("%-196.9s%087.124d%0.x%*c===" ,"h:N{",1475099643,662365497u,-166,0);
	//printf("%-96c%-*c===" ,0,59,-54);
	//ft_printf("%-38c%-160p%*c" ,0,(void*)16025742189089525589lu,161,-6);
	printf("%-196c%000127.1i" ,0,1096795813);
	//printf("\n=============== HEX ADRSS ================\n\n");
	//printf("%s\n", ft_hexadress );
	return (0);
}

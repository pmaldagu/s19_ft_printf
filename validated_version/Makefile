 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 09:46:31 by pmaldagu          #+#    #+#              #
#    Updated: 2020/01/09 17:29:52 by pmaldagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	./libft/*.c \
		ft_nbcheck.c \
		ft_flagncv.c \
		ft_isspace.c \
		ft_precision.c \
		ft_utoa_base.c \
		ft_chrdup.c \
		ft_hexadress.c \
		ft_printf.c \
		ft_strndup.c \
		ft_pftutils.c \

NAME = libftprintf.a

OBJS = ./*.o

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

RM = rm -rf

HEADER = ./

TEST = ./main.c


all: $(NAME)

$(OBJS): $(SRC)
	$(GCC) $(CFLAGS) -I$(HEADER) -c $(SRC)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)   

test: re
	$(GCC) -I$(HEADER) $(TEST) $(NAME)
	./a.out

lib: all clean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all test clean fclean re

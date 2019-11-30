 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmaldagu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 09:46:31 by pmaldagu          #+#    #+#              #
#    Updated: 2019/11/30 17:25:48 by pmaldagu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ./src/*.c \
	  printf.c \
	  ft_printf.c \

NAME = libftprintf.a

OBJS = ./*.o

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

RM = rm -rf

HEADER = ./include

TEST = ./main.c


all: $(NAME)
	@clear
	@echo "Making ${NAME}"
#	@sleep 0.5
#	@clear
#	@echo "Making ${NAME} ."
#	@sleep 0.3
#	@clear
#	@echo "Making ${NAME} . ."
	@sleep 0.2
#	@clear
#	@echo "Making ${NAME} . . ."
#	@sleep 0.3
#	@clear
	@echo "${NAME} Done!"
	@sleep 0.5
	

$(OBJS): $(SRC)
	@$(GCC) $(CFLAGS) -I$(HEADER) -c $(SRC)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)   

bonus:
	$(GCC) $(CFLAGS) -I$(BHEADER) -c $(SBONUS)
	ar rc $(NAME) $(BOBJS)

test: re
	@$(GCC) -I$(HEADER) $(TEST) $(NAME)
	@clear
	@echo ""
	@echo "=========================================="
	@echo "=============== RESULT : ================="
	@echo "=========================================="
	@echo ""
	@./a.out

lib: all clean

clean:
	@clear
	@$(RM) $(OBJS)
	@echo "Removing objects"

fclean: clean
	@$(RM) $(NAME)
	@echo "Removing ${NAME}"

re: fclean all

.PHONY: all test clean fclean re bonus

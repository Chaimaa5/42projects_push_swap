# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 13:40:07 by cel-mhan          #+#    #+#              #
#    Updated: 2022/03/03 13:40:09 by cel-mhan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PS_NAME = push_swap
# CK_NAME = checker
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c linked_list_tools.c parsing_tools.c operations.c sorter.c  chunker.c op_tools.c sort.c find.c checker_stack.c checker.c
LIB = libft.a

OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c

$(LIB):
	make -C ../inc/libft
	cp ../inc/libft/libft.a ./

$(PS_NAME) : $(SRCS) $(LIB)
		$(CC) $(CFLAGS) $(SRCS) -o ${PS_NAME} $(LIB)

all : $(PS_NAME) 

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f push_swap
	rm -f libft.a

re : fclean all

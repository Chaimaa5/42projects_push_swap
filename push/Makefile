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

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c linked_list_tools.c parsing_tools.c operations.c sorter.c  chunker.c op_tools.c sort.c find.c checker.c
LIB = libft.a

OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c

$(LIB):
	make -C ../inc/libft
	cp ../inc/libft/libft.a ./

$(NAME) : $(SRCS) $(LIB)
		$(CC) $(CFLAGS) $(SRCS) -o ${NAME} $(LIB)

all : $(NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f push_swap
	rm -f libft.a

re : fclean all

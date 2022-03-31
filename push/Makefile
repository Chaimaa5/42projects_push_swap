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

CK_NAME = checker
PS_NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = checker.c linked_list_tools.c parsing_tools.c operations.c sorter.c  chunker.c op_tools.c sort.c find.c  error_check.c ../inc/gnl/get_next_line.c ../inc/gnl/get_next_line_utils.c small_sort.c
SRCP = push_swap.c linked_list_tools.c parsing_tools.c operations.c sorter.c  chunker.c op_tools.c sort.c find.c error_check.c small_sort.c
LIB = libft.a

OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c

$(PS_NAME) : $(SRCP) $(LIB)
		$(CC) $(CFLAGS) $(SRCP) -o ${PS_NAME} $(LIB)

$(LIB):
	make -C ../inc/libft
	cp ../inc/libft/libft.a ./


$(CK_NAME) : $(SRCS) $(LIB)
		$(CC) $(CFLAGS) $(SRCS) -o ${CK_NAME} $(LIB)



all : $(CK_NAME) $(PS_NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f push_swap
	rm -f checker
	rm -f libft.a

re : fclean all

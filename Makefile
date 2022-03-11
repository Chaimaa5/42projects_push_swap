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
SRCS = push_swap.c linked_list_tools.c parsing_tools.c log_tools.c operations.c tools.c sorter.c  chunker.c op_tools.c sort.c find.c checker.c
	
OBJS = $(SRCS:.c=.o)

%.o : %.c
	   $(CC) $(CFLAGS) $< -c
$(NAME) : $(SRCS)
		$(CC) $(CFLAGS) $(SRCS) -o ${NAME}

all : $(NAME)

clean :
	rm -f ${OBJS}
fclean : clean
	rm -f push_swap

re : fclean all

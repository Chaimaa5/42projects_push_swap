NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror 
SRCS = push_swap.c linked_list_tools.c parsing_tools.c log_tools.c operations.c tools.c small_sorter.c big_sorter.c
	
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
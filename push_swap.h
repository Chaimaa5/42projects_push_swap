#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct s_stack{
	int content;
	struct s_stack *next;
}               t_stack;


typedef struct s_op{
	char            *operation;
	struct s_op    *next;
}               t_op;

t_stack		*ft_lstnew(int content);
int			ft_lstsize(t_stack *lst);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **alst, t_stack *new);
void		ft_lstadd_front(t_stack **alst, t_stack *new);
int			ft_atoi(const char *str);
void   		print_stack(t_stack *stack, char *str);
void   		print_operations(t_op *operations);
void    	log_global_error(char *err);
size_t		ft_strlen(char *str);
void		shift_up(t_stack **stack);
void		shift_down(t_stack **stack);
int     	is_sorted(t_stack *stack);
void		ft_swap(t_stack **stack);
void		ft_push(t_stack **from, t_stack **to);
void	    pre_execute_operation(char *operation, t_stack **a, t_stack **b, t_op **op);
int			max(t_stack *stack);
int			min(t_stack *stack);

#endif
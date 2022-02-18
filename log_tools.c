#include "push_swap.h"

void    print_operations(t_op *operations)
{
    int i;

    i = 0;
    while (operations)
    {
        while (operations->operation[i])
        {
            write(1, &operations->operation[i], 1);
            i++;
        }
        operations = operations->next;
    }
}

void    print_stack(t_stack *stack, char *str)
{
    printf("%s\n", str);
    while (stack)
    {
        printf("%d\n", stack->content);
        stack = stack->next;
    }
    printf("****************************\n");
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void    log_global_error(char *err)
{
    write(2, err, ft_strlen(err));
    exit(1);
}
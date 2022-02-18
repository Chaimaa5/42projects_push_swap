#include "push_swap.h"

int		ft_isdigit(int c)
{
	if (c <= 57 && c >= 48)
		return (1);
	return (0);
}

int     check_number(char *num)
{
    int i;

    i = 1;
    if(num[0] == '-' || num[0] == '+' || ft_isdigit(num[0]))
    {
        while (num[i])
        {
            if (ft_isdigit(num[i]))
                i++;
            else
                return (FALSE);
        }
    }
    else
        return (FALSE);
    return (TRUE);
}

t_stack *parser(char **argv)
{
    int i;
    t_stack *stack;

    i = 1;
    stack = NULL;
    while (argv[i])
    {
        if (check_number(argv[i]))
        {
            ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i])));
        }
        else
        {
            log_global_error("Error\n");
        }
        i++;      
    }
    return(stack);
}


int main(int argc, char **argv)
{
    t_stack *a;
    // t_stack *b;
    // t_op    *op;

    // b = NULL;
    // op = NULL;
    if (argc == 1)
        return (0);
    a = parser(argv);
    // print_stack(a, "stack before\n");
    // sort(&a, &b, &op);
    printf(">> %d\n", min(a));
    // print_stack(a, "stack after\n");

    return (0);
}

#include "push_swap.h"

void    sort(t_stack **a, t_stack **b, t_op **op)
{
    if (ft_lstsize(*a) == 2)
        pre_execute_operation("sa", a, b, op);
    // else if (ft_lstsize(*a) == 3)
    //     sort_three(a, b, op);
    // else if (ft_lstsize(*a) == 4)
    //     sort_four(a, b, op);
    // else if (ft_lstsize(*a) == 5)
    //     sort_five(a, b, op);
    // else
    //     sort_whatever(a, b, op);
}

int max(t_stack *stack)
{
    int index;
    int max;
    int i;

    i = 1;
    max = stack->content;
    while (stack)
    {
        if (max <= stack->content)
        {
            max = stack->content;
            index = i;
        }
        stack = stack->next;
        i++;
    }
    return (index);
}

int min(t_stack *stack)
{
    int index;
    int min;
    int i;

    i = 1;
    min = stack->content;
    while (stack)
    {
        if (min >= stack->content)
        {
            min = stack->content;
            index = i;
        }
        stack = stack->next;
        i++;
    }
    return (index);
}

#include "push_swap.h"


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


int min_element(t_stack *stack)
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
    return (min);
}

int is_duplicate(t_stack *stack)
{
    int found;
    t_stack *tmp1;
    t_stack *tmp2;

    tmp1 = stack;
    found = 0;
    while (tmp1)
    {
        if (found > 1)
            return (TRUE);
        found = 0;
        tmp2 = stack;
        while (tmp2)
        {
            if (tmp1->content == tmp2->content)
                found++;
            tmp2 = tmp2->next;
        }
        tmp1 = tmp1->next;
    }
    return (FALSE);
}

void    sort_three(t_stack **a, t_stack **b, t_op **op)
{
     int    ma;
     int    mi;

     mi = min(*a);
     ma = max(*a);
    if (mi == 2 && ma == 3)
        pre_execute_operation("sa", a, b, op);
    else if (mi == 2 && ma == 1)
        pre_execute_operation("ra", a, b, op);
    else if (mi == 3 && ma == 2)
        pre_execute_operation("rra", a, b, op);
    else if (mi == 3 && ma == 1)
    {
        pre_execute_operation("sa", a, b, op);
        pre_execute_operation("rra", a, b, op);
    }
    else if (mi == 1 && ma == 2)
    {
        pre_execute_operation("sa", a, b, op);
        pre_execute_operation("ra", a, b, op);
    }
}

static  int     which_better(t_stack *stack, int index)
{
    if (ft_lstsize(stack) / 2 >= index)
        return(UP);
    else
        return(DOWN);
}

static  int get_index(t_stack *stack, int   key)
{
    int index;

    index = 1;
    while (stack)
    {
        if (key == stack->content)
            return (index);
        index++;
        stack = stack->next;
    }
    return (index);
}

void    sort_four(t_stack **a, t_stack **b, t_op **op)
{
    if(which_better(*a, min(*a)) == UP)
        while (min(*a) != 1)
            pre_execute_operation("ra", a, b, op);
    else
        while (min(*a) != 1)
            pre_execute_operation("rra", a, b, op);
    pre_execute_operation("pb", a, b, op);
    sort_three(a, b, op);
    pre_execute_operation("pa", a, b, op);
}

void    sort_five(t_stack **a, t_stack **b, t_op **op)
{
    if(which_better(*a, min(*a)) == UP)
        while (min(*a) != 1)
            pre_execute_operation("ra", a, b, op);
    else
        while (min(*a) != 1)
            pre_execute_operation("rra", a, b, op);
    pre_execute_operation("pb", a, b, op);
    sort_four(a, b, op);
    pre_execute_operation("pa", a, b, op);
}

int     right_index(t_stack *stack, int key)
{
    int     index;

    index = 1;
    while (stack)
    {
        if (stack->content < key)
            index++;
        stack = stack->next;
    }
    return (index);
}

int     get_chunk_size(t_stack *stack)
{
    int size;

    size = ft_lstsize(stack);
    if (size <= 5)
        return (0);
    if (size > 200)
        return (100);
    else if (size > 100)
        return (70);
    else if (size > 60)
        return (size / 3);
    else
        return (15);
}

int     *chunk_content(t_stack *stack, int size)
{
    int     *chunk;
    int     i;
    t_stack *copy;

    i = 0;
    copy = NULL;
    chunk = malloc(size * 4);
    while (stack)
    {
        if (right_index(copy, stack->content) < size)
        {
            chunk[i] = stack->content;
            i++;
        }
        stack = stack->next;
    }
    return (chunk);
}

int     get_number(t_stack *stack, int index)
{
    int i;

    i = 1;
    while (stack)
    {
        if (i == index)
            return (stack->content);
        stack = stack->next;
        i++;
    }
    return (0);
}

int     exists_in_chunk(int *chunk, int key, int size)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (chunk[i] == key)
            return TRUE;
        i++;
    }
    return FALSE;
}

void    chunker(t_stack **a, t_stack **b, t_op **op)
{
    int     chunk_size;
    int     *chunk;
    t_stack *tmp;

    chunk_size = get_chunk_size(*a);
    chunk = chunk_content(*a, chunk_size);
    tmp = *a;
    while (tmp)
    {
        if (exists_in_chunk(chunk, (*a)->content, chunk_size))
        {
            if(which_better(*a, get_index(*a, (*a)->content) == UP))
                while (get_index(*a, (*a)->content) != 1)
                    pre_execute_operation("ra", a, b, op);
            else
                while (get_index(*a, (*a)->content) != 1)
                    pre_execute_operation("rra", a, b, op);
            pre_execute_operation("pb", a, b, op);   
        }
        tmp = tmp->next;
    }
}

void    sort_whatever(t_stack **a, t_stack **b, t_op **op)
{
    while (get_chunk_size(*a))
        chunker(a, b, op);
    sort(a, b, op);
}

void    sort(t_stack **a, t_stack **b, t_op **op)
{
    if (ft_lstsize(*a) == 1)
        return ;
    if (ft_lstsize(*a) == 2)
        pre_execute_operation("sa", a, b, op);
    else if (ft_lstsize(*a) == 3)
        sort_three(a, b, op);
    else if (ft_lstsize(*a) == 4)
        sort_four(a, b, op);
    else if (ft_lstsize(*a) == 5)
        sort_five(a, b, op);
    else
        sort_whatever(a, b, op);
}

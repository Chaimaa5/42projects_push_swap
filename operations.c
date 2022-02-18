//sa sa (swap a): Swap the first 2 elements at the top of stack a.
//Do nothing if there is only one or no elements.

// pa (push a): Take the first element at the top of b and put it at the top of a.
// Do nothing if b is empty.
// pb (push b): Take the first element at the top of a and put it at the top of b.
// Do nothing if a is empty.
// ra (rotate a): Shift up all elements of stack a by 1.
// The first element becomes the last one.
// rb (rotate b): Shift up all elements of stack b by 1.
// The first element becomes the last one.
// rr : ra and rb at the same time.
// rra (reverse rotate a): Shift down all elements of stack a by 1.
// The last element becomes the first one.
// rrb (reverse rotate b): Shift down all elements of stack b by 1.
// The last element becomes the first one.
// rrr : rra and rrb at the same time.

#include "push_swap.h"

void    ft_swap(t_stack **stack)
{
	int	i;
	int	j;

	j = (*stack)->content;
	i = (*stack)->next->content;
	(*stack)->content = i;
	(*stack)->next->content = j;
}

void	ft_push(t_stack **from, t_stack **to)
{
	int		i;
	t_stack	*tmp;

	i = (*from)->content;
	tmp = NULL;
	ft_lstadd_front(to, ft_lstnew(i));
	tmp = (*from);
	(*from) = (*from)->next;
	free(tmp);
}

void	shift_up(t_stack **stack)
{
	int		first;
	t_stack	*tmp;

	tmp = *stack;
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = (tmp->next)->content;
		tmp = tmp->next;
	}
	tmp->content = first;
}

void	shift_down(t_stack **stack)
{
	int		swp;
	int		next_swp;
	t_stack	*tmp;

	tmp = *stack;
	swp = tmp->content;
	while (tmp->next)
	{
		next_swp = tmp->next->content;
		tmp->next->content = swp;
		swp = next_swp;
		tmp = tmp->next;
	}
	(*stack)->content = swp;
}

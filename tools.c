#include "push_swap.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*s11;
	unsigned char	*s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (s11[i] && s22[i] && s11[i] == s22[i])
		{
			i++;
			continue ;
		}
		return (s11[i] - s22[i]);
	}
	return (0);
}

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*buff;
	char	*s;

	s = (char *)s1;
	i = 0;
	len = ft_strlen(s);
	buff = malloc(sizeof(char) * len + 1);
	if (!buff)
		return (0);
	while (s[i])
	{
		buff[i] = s[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}

t_op		*ft_lstnew_op(char *content)
{
	t_op		*new;

	if (!(new = (t_op *)malloc(sizeof(t_op) * 1)))
		return (NULL);
	new->operation = content;
	new->next = NULL;
	return (new);
}

int		ft_lstsize_op(t_op *lst)
{
	int		i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

t_op	*ft_lstlast_op(t_op *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_op(t_op **alst, t_op *new)
{
	new->next = NULL;
	if (!(*alst))
		*alst = new;
	else
		ft_lstlast_op(*alst)->next = new;
}

void	ft_lstadd_front_op(t_op **alst, t_op *new)
{
	new->next = *alst;
	*alst = new;
}


int     is_sorted(t_stack *stack)
{
    while (stack->next)
    {
        if (stack->content < stack->next->content)
            stack = stack->next;
        else
            return (FALSE);
    }
    return (TRUE);
}

static void    exec_helper(t_stack **a, t_stack **b, char *operation)
{
    if (!ft_strncmp(operation, "rr", 5))
    {
        shift_up(a);
        shift_up(b);
    }
    else if (!ft_strncmp(operation, "rra", 5))
        shift_down(a);
    else if (!ft_strncmp(operation, "rrb", 5))
        shift_down(b);
    else if (!ft_strncmp(operation, "rrr", 5))
    {
        shift_down(a);
        shift_down(b);
    }
}

void    exec_op(t_stack **a, t_stack **b, char *operation)
{
    if (!ft_strncmp(operation, "pa", 5))
        ft_push(b, a);
    else if (!ft_strncmp(operation, "pb", 5))
        ft_push(a, b);
    else if (!ft_strncmp(operation, "sa", 5))
        ft_swap(a);
    else if (!ft_strncmp(operation, "sb", 5))
        ft_swap(b);
    else if (!ft_strncmp(operation, "ss", 5))
    {
        ft_swap(a);
        ft_swap(b);
    }
    else if (!ft_strncmp(operation, "ra", 5))
        shift_up(a);
    else if (!ft_strncmp(operation, "rb", 5))
        shift_up(b);
    else
        exec_helper(a, b, operation);
}

void    pre_execute_operation(char *operation, t_stack **a, t_stack **b, t_op **op)
{
    exec_op(a, b, operation);
    ft_lstadd_back_op(op, ft_lstnew_op(ft_strdup(operation)));
}


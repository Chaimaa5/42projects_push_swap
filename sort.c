/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:46 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:24:47 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	exec_helper(t_stack **a, t_stack **b, char *operation)
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

void	exec_op(t_stack **a, t_stack **b, char *operation)
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

void	pre_execute(char *operation, t_stack **a, t_stack **b, t_op **op)
{
	exec_op(a, b, operation);
	ft_lstadd_back_op(op, ft_lstnew_op(ft_strdup(operation)));
}

int	which_better(t_stack *stack, int index)
{
	if (ft_lstsize(stack) / 2 >= index)
		return (UP);
	else
		return (DOWN);
}

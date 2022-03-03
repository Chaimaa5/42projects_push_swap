/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:23:47 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:23:48 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(t_stack *stack)
{
	int	size;

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

int	*chunk_content(t_stack *stack, int size)
{
	int		*chunk;
	int		i;
	t_stack	*copy;

	i = 0;
	copy = NULL;
	chunk = malloc(size * 4);
	while (stack)
	{
		if (right_index(copy, stack->content) < size)
		{
			chunk[i] = stack->content;
			printf(">> %d \n", chunk[i]);
			i++;
		}
		stack = stack->next;
	}
	return (chunk);
}

int	get_number(t_stack *stack, int index)
{
	int	i;

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

int	exists_in_chunk(int *chunk, int key, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (chunk[i] == key)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	chunker(t_stack **a, t_stack **b, t_op **op)
{
	int		chunk_size;
	int		*chunk;
	t_stack	*tmp;

	chunk_size = get_chunk_size(*a);
	chunk = chunk_content(*a, chunk_size);
	tmp = *a;
	while (tmp)
	{
		if (exists_in_chunk(chunk, (*a)->content, chunk_size))
		{
			if (which_better(*a, get_index(*a, (*a)->content) == UP))
				while (get_index(*a, (*a)->content) != 1)
					pre_execute("ra", a, b, op);
			else
				while (get_index(*a, (*a)->content) != 1)
					pre_execute("rra", a, b, op);
			pre_execute("pb", a, b, op);
		}
		tmp = tmp->next;
	}
}


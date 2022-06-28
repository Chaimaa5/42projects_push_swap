/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:23:47 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/30 21:16:25 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_chunk_size(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size <= 5)
		return (0);
	else if (size <= 30)
		return (size / 2);
	else if (size <= 80)
		return (size / 3);
	else if (size <= 150)
		return (20);
	else if (size <= 250)
		return (25);
	else if (size <= 300)
		return (30);
	else if (size <= 400)
		return (40);
	return (50);
}

int	*chunk_content(t_stack *stack, int size)
{
	int		*chunk;
	int		i;
	t_stack	*copy;

	i = 0;
	copy = stack;
	chunk = malloc(size * 4);
	while (stack)
	{
		if (right_index(copy, stack->content) <= size)
		{
			chunk[i] = stack->content;
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

char	*easy(t_stack **a, int chunk)
{
	char	*cmd;

	if (which_better((*a), get_index((*a), chunk)) == UP)
		cmd = ft_strdup("ra");
	else
		cmd = ft_strdup("rra");
	return (cmd);
}

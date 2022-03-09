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

// big_sort: This algorithm is designed for larger amount of integers. 
// This algorithm splits stack A into smaller chunks which are pushed to stack B:
//  <= 100 are splitted into 5 chunks and > 100 integers into 10 chunks. Chunks with smallest numbers are pushed first to stack B. 
//  I used sorted array of integers to help me to split stack A. 
//  When all of the numbers are in the stack B then I can start to search numbers from biggest number and push them back to stack A. 
//  This continues until B is empty and A is sorted. 
//  For optimizing I created a function called shortest way to check is it more effective to use rb or rrb to get that number on top of the stack B.

#include "push_swap.h"

int	get_chunk_size(t_stack *stack)
{
	int	size;

	size = ft_lstsize(stack);
	if (size <= 5)
		return (0);
	else if (size > 5 && size <= 20)
		return (2);
	else if (size > 20 && size <= 100)
		return (30);
	else
		return (100);
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

void	chunker(t_stack **a, t_stack **b, t_op **op)
{
	int		*chunk;
	char	*cmd;
	int		chunk_size;
	int		i;

	while ((chunk_size = get_chunk_size((*a))))
	{
		chunk = chunk_content((*a), chunk_size);
		i = 0;
		while (i < chunk_size)
		{
			cmd = which_better((*a), get_index((*a), chunk[i])) == UP ? ft_strdup("ra") : ft_strdup("rra");
			while (get_index((*a), chunk[i]) != 1)
				pre_execute(cmd, a, b, op);
			pre_execute("pb", a, b, op);
			i++;
		}
		free(chunk);
	}
	final_sort(a, b, op);
}
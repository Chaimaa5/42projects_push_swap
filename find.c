/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:23:13 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:23:14 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max(t_stack *stack)
{
	int	index;
	int	max;
	int	i;

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

int	min(t_stack *stack)
{
	int	index;
	int	min;
	int	i;

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

int	min_element(t_stack *stack)
{
	int	index;
	int	min;
	int	i;

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

int	max_element(t_stack *stack)
{
	int	index;
	int	min;
	int	i;

	i = 1;
	min = stack->content;
	while (stack)
	{
		if (min <= stack->content)
		{
			min = stack->content;
			index = i;
		}
		stack = stack->next;
		i++;
	}
	return (min);
}

int	get_index(t_stack *stack, int key)
{
	int	index;

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

int	right_index(t_stack *stack, int key)
{
	int	index;

	index = 1;
	while (stack)
	{
		if (stack->content < key)
			index++;
		stack = stack->next;
	}
	return (index);
}

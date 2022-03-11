/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:12 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:24:14 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:48:10 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/31 12:48:11 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **a, t_stack **b, t_op **op)
{
	int	ma;
	int	mi;

	mi = min(*a);
	ma = max(*a);
	if (mi == 2 && ma == 3)
		pre_execute("sa", a, b, op);
	else if (mi == 2 && ma == 1)
		pre_execute("ra", a, b, op);
	else if (mi == 3 && ma == 2)
		pre_execute("rra", a, b, op);
	else if (mi == 3 && ma == 1)
	{
		pre_execute("sa", a, b, op);
		pre_execute("rra", a, b, op);
	}
	else if (mi == 1 && ma == 2)
	{
		pre_execute("sa", a, b, op);
		pre_execute("ra", a, b, op);
	}
}

void	sort_four(t_stack **a, t_stack **b, t_op **op)
{
	if (which_better(*a, min(*a)) == UP)
		while (min(*a) != 1)
			pre_execute("ra", a, b, op);
	else
		while (min(*a) != 1)
			pre_execute("rra", a, b, op);
	pre_execute("pb", a, b, op);
	sort_three(a, b, op);
	pre_execute("pa", a, b, op);
}

void	sort_five(t_stack **a, t_stack **b, t_op **op)
{
	if (which_better(*a, min(*a)) == UP)
		while (min(*a) != 1)
			pre_execute("ra", a, b, op);
	else
		while (min(*a) != 1)
			pre_execute("rra", a, b, op);
	pre_execute("pb", a, b, op);
	sort_four(a, b, op);
	pre_execute("pa", a, b, op);
}

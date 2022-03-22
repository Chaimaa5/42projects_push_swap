/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:42 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/15 22:41:13 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	sort(t_stack **a, t_stack **b, t_op **op)
{
	if (ft_lstsize(*a) == 1)
		return ;
	if (ft_lstsize(*a) == 2)
		pre_execute("sa", a, b, op);
	else if (ft_lstsize(*a) == 3)
		sort_three(a, b, op);
	else if (ft_lstsize(*a) == 4)
		sort_four(a, b, op);
	else if (ft_lstsize(*a) == 5)
		sort_five(a, b, op);
	else
		sort_whatever(a, b, op);
}

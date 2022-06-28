/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sorter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:42 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/30 21:17:15 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		sort_whatever(a, b, op);
		final_sort(a, b, op);
	}
}

void	sort_whatever(t_stack **a, t_stack **b, t_op **op)
{
	int		*chunk;
	char	*cmd;
	int		chunk_size;
	int		i;

	while (get_chunk_size((*a)) && (ft_lstsize((*a)) > 5))
	{
		chunk_size = get_chunk_size((*a));
		chunk = chunk_content((*a), chunk_size);
		i = 0;
		while (i < chunk_size)
		{
			cmd = easy(a, chunk[i]);
			while (get_index((*a), chunk[i]) != 1)
				pre_execute(cmd, a, b, op);
			pre_execute("pb", a, b, op);
			free(cmd);
			i++;
		}
		free(chunk);
	}
	sort(a, b, op);
}

void	final_sort(t_stack **a, t_stack **b, t_op **op)
{
	char	*cmd;

	while (*b)
	{
		if (which_better((*b), max(*b)) == DOWN)
			cmd = ft_strdup("rrb");
		else
			cmd = ft_strdup("rb");
		while (max(*b) != 1)
			pre_execute(cmd, a, b, op);
		pre_execute("pa", a, b, op);
		free(cmd);
	}
}

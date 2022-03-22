/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:39:55 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/15 22:44:02 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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


void	log_global_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

void	clear(t_stack **a, t_stack **b, t_op **op)
{
	t_stack *tmp;
	t_op	*swp;

	while (*a)
	{
		tmp = (*a)->next;
		free(*a);
		(*a) = tmp;
	}
	while (*b)
	{
		tmp = (*b)->next;
		free(*b);
		(*b) = tmp;
	}
	while (*op)
	{
		swp = (*op)->next;
		free((*op)->operation);
		free(*op);
		(*op) = swp;
	}
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	t_op	*op;

	b = NULL;
	op = NULL;
	if (argc == 1)
		return (0);
	a = parser(argv, argc);
	sort(&a, &b, &op);
	print_op(op);
	clear(&a, &b, &op);
	return (0);
}

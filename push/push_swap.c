/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:39:55 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/30 21:16:57 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear(t_stack **a, t_stack **b, t_op **op)
{
	t_stack	*tmp;
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

int	main(int argc, char **argv)
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

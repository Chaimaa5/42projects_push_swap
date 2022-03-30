/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 22:03:33 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/30 21:14:35 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	checker_result(t_stack	*stack)
{
	if (is_sorted(stack))
		ft_putstr("OK");
	else
		ft_putstr("KO");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*op[10000];
	int		i;

	b = NULL;
	i = 0;
	if (ac == 1)
		return (0);
	a = parser(av, ac);
	while ((op[i] = get_next_line(0)))
	{
		op[i][ft_strlen(op[i]) - 1] = '\0';
		i++;
	}
	i = 0;
	while (op[i])
	{
		exec_op(&a, &b, op[i]);
		i++;
	}
	checker_result(a);
	return (0);
}

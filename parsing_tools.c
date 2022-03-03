/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:31 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:24:32 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	spaces(char c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\v' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 0;
	i = 0;
	while (spaces(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
		res = res * 10 + ((int)str[i++] - '0');
	if (res > 2147483648 && sign == -1)
		return (0);
	if (res > 2147483647 && sign != -1)
		return (-1);
	if (sign == -1)
		return (res * -1);
	return (res);
}

t_stack	*parser(char **argv)
{
	int		i;
	t_stack	*stack;

	i = 1;
	stack = NULL;
	while (argv[i])
	{
		if (check_number(argv[i]))
			ft_lstadd_back(&stack, ft_lstnew(ft_atoi(argv[i])));
		else
			log_global_error("Error\n");
		i++;
	}
	return (stack);
}

void	print_op(t_op	*op)
{
	while (op)
	{
		printf("%s\n", op->operation);
		op = op->next;
	}
}

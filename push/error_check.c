/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:23:03 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:23:05 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(t_stack *stack)
{
	int		found;
	t_stack	*tmp1;
	t_stack	*tmp2;

	tmp1 = stack;
	found = 0;
	while (tmp1)
	{
		if (found > 1)
			return (TRUE);
		found = 0;
		tmp2 = stack;
		while (tmp2)
		{
			if (tmp1->content == tmp2->content)
				found++;
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (FALSE);
}

int	is_sorted(t_stack *stack)
{
	while (stack->next)
	{
		if (stack->content < stack->next->content)
			stack = stack->next;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	check_number(char *num)
{
	int	i;

	i = 1;
	if (num[0] == '-' || num[0] == '+' || ft_isdigit(num[0]))
	{
		while (num[i])
		{
			if (ft_isdigit(num[i]))
				i++;
			else
				return (FALSE);
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

void	log_global_error(char *err)
{
	write(2, err, ft_strlen(err));
	exit(1);
}

void	check_error(t_stack *stack)
{
	if (is_sorted(stack))
		log_global_error("");
	if (is_duplicate(stack))
		log_global_error("Error\n");
}

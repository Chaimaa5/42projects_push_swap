/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:24:05 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:24:07 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	*ft_lstnew_op(char *content)
{
	t_op	*new;

	new = (t_op *)malloc(sizeof(t_op) * 1);
	if (!(new))
		return (NULL);
	new->operation = content;
	new->next = NULL;
	return (new);
}

int	ft_lstsize_op(t_op *lst)
{
	int		i;

	i = 0;
	if (lst)
	{
		while (lst)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}

t_op	*ft_lstlast_op(t_op *lst)
{
	if (!lst)
		return (lst);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_op(t_op **alst, t_op *new)
{
	new->next = NULL;
	if (!(*alst))
		*alst = new;
	else
		ft_lstlast_op(*alst)->next = new;
}

void	ft_lstadd_front_op(t_op **alst, t_op *new)
{
	new->next = *alst;
	*alst = new;
}

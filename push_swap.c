/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cel-mhan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 13:39:55 by cel-mhan          #+#    #+#             */
/*   Updated: 2022/03/03 13:39:57 by cel-mhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    final_sort(t_stack **a, t_stack **b, t_op **op)
{
    char    *cmd;

    while(*b)
    {
        cmd = which_better((*b), get_index((*b), (*b)->content)) == DOWN ? ft_strdup("rb") : ft_strdup("rrb");
        while (max(*b) != 1)
                pre_execute(cmd, a, b, op);
        pre_execute("pa", a, b, op);
    }
}
int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    t_op    *op;

    b = NULL;
    op = NULL;
    if (argc == 1)
        return (0);
    a = parser(argv);
    sort(&a, &b, &op);
    print_op(op);
    return (0);
}
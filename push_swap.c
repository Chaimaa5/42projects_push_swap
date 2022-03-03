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
    // print_stack(a, "stack before\n");
    sort(&a, &b, &op);
    // printf(">> %d\n", is_duplicate(a));
    // print_stack(a, "stack after\n");
    // printf("%d\n", min_element(a));
    // print_op(op);
    // printf(">> %d\n",right_index(a, a->content));
    return (0);
}

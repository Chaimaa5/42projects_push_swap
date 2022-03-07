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
		// printf("index ; %d\n", get_index(&a, a->content));
		// printf("which better ; %d\n", which_better(a, get_index(&a, a->content)));

    // printf("%d\n", min_element(a));
    // print_op(op);
    // printf(">> %d\n",right_index(a, a->content));
    // int *tab = chunk_content(a, 4);
    // for (size_t i = 0; i < 4; i++)
    // {
    //   printf("* %d\n", tab[i]);
    // }
    


// printf("* %d\n", get_index(a, 99));
    print_stack(b, "stack b after\n");
    print_stack(a, "stack a after\n");

    return (0);
}
#include "checker.h"

int		push_swap(int argc, char **argv)
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

int main(int argc, char **argv)
{
    char    *op;
    t_stack *a;
    t_stack *b;

    
    while (1)
    {
        op = get_next_line(STDOUT_FILENO);
        exec_op(&a, &b, op);
    }
    if (is_sorted(a))
        ft_putstr("OK\n");
    else
        ft_putstr("KO\n");
}
 #include "checker.h"

void	push_swap(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	t_op	*op;

	b = NULL;
	op = NULL;
	a = parser(av, ac);
	sort(&a, &b, &op);
    print_op(op);
}

void	checker_result(t_stack	*stack)
{
	if (is_sorted(stack))
        ft_putstr("OK");
    else
        ft_putstr("KO");
}

int main(int ac, char **av)
{
    t_stack *a;
    t_stack *b;
    char *op[10000];
    int i;

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
    while(op[i])
    {
		exec_op(&a, &b, op[i]);
		i++;
	}
	checker_result(a);
	return (0);
}
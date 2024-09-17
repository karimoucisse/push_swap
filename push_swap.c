#include "libft.h"
#include "push_swap.h"

int ft_sort_stack(t_stack *a, t_stack *b)
{
	int range;
	int i;

	i = 0;
	ft_push_elem(a->stack, b->stack);
	// ft_push_elem(a->stack, b->stack);
	// ft_push_elem(a->stack, b->stack);
	// ft_push_elem(a->stack, b->stack);
	while(b->stack[i])
	{
		// if(a->stack[i])
		// 	printf("%s", a->stack[i]);
		// if(b->stack[i])
		printf("%s", b->stack[i]);
		printf("\n");
		i++;
	}
	range = 0;
	ft_find_range(atoi(a->stack[0]), b->stack);
	return (1);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	i = 0;
	if (ac < 2)
		return (ft_print_error());
	if (!ft_check_char(av, ac))
		return (ft_print_error());
	if (!init_struct(ac, av, &stack_a, &stack_b))
		return (ft_print_error());
	// if (!ft_sort_stack())
	// 	return (ft_print_error());
	ft_push_elem(stack_a->stack, stack_b->stack);
	ft_push_elem(stack_a->stack, stack_b->stack);
	ft_rotate_array(stack_a->stack);
	printf("a	b\n");
	while (stack_a->stack[i])
	{
		printf("%s	", stack_a->stack[i]);
		if (stack_b->stack[i])
			printf("%s", stack_b->stack[i]);
		printf("\n");
		i++;
	}
}

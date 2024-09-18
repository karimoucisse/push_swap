#include "libft.h"
#include "push_swap.h"

int ft_sort_stack(t_stack *a, t_stack *b)
{
	int range;
	int i;

	i = 0;
	ft_push_elem(a->stack, b->stack);
	ft_push_elem(a->stack, b->stack);
	range = 0;
	while(i < 2)
	{
		ft_find_range(atoi(a->stack[0]), b->stack);
		i++;
	}
	return (1);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	i = 0;
	if (ac < 2)
		return (ft_print_error());
	if (!ft_check_char(av, ac))
		return (ft_print_error());
	if (!init_struct(ac, av, stack_a, stack_b))
		return (ft_print_error());
	if (!ft_sort_stack(stack_a, stack_b))
		return (ft_print_error());
	// ft_push_elem(stack_a->stack, stack_b->stack);
	// ft_push_elem(stack_a->stack, stack_b->stack);
	// // ft_rotate_array(stack_a->stack);
	// printf("a	b\n\n");
	// while (stack_a->stack[i] && ft_stack_len(stack_a->stack))
	// {
	// 	printf("%s	", stack_a->stack[i]);
	// 	if (stack_b->stack[i] && ft_stack_len(stack_b->stack))
	// 		printf("%s", stack_b->stack[i]);
	// 	printf("\n");
	// 	i++;
	// }
}

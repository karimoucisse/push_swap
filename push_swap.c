#include "libft.h"
#include "push_swap.h"


int main(int ac, char **av)
{
	// t_stack *stack_a;
	// t_stack *stack_b;
	int res;

	res = 1;
	if (ac < 2)
		return (1);
	// if (ac == 2)
	res = ft_check_char(av, ac);
	if (res)
		printf("succcess");
	if (!res)
		printf("error");
	// stack_a = init_struct();
	// if (!stack_a)
	// 	return (0);
	// stack_b = init_struct();
	// if (!stack_b)
	// 	return (0);
	// if (!ft_check_args(av, ac, stack_a->stack))
	// 	return (0);
}

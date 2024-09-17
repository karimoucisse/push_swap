#include "libft.h"
#include "push_swap.h"

// int ft_sort_stack()
// {

// }

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	i =0;
	if (ac < 2)
		return (ft_print_error());
	if (!ft_check_char(av, ac))
		return (ft_print_error());
	if (!init_struct(ac, av, &stack_a, &stack_b))
		return (ft_print_error());
	// if (!ft_sort_stack())
	// 	return (ft_print_error());

}

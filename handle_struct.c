#include "libft.h"
#include "push_swap.h"

t_stack *init_struct(char **av, int ac)
{
	t_stack *stack;
	int len;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (0);
	if(ac == 2)
		len = ft_strlen(av[1]);
	else
		len = ac;
	stack->rev = 0;
	stack->stack = malloc(sizeof(int)  * len);
	return (stack);
}

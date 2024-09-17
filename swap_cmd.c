#include "libft.h"
#include "push_swap.h"

// sa sb
int	ft_swap_position(int *stack)
{
	int	copy;

	copy = stack[0];
	if (!copy)
		return (0);
	stack[0] = stack[1];
	stack[1] = copy;
	return (1);
}

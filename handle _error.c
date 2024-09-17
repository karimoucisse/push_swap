#include "libft.h"
#include "push_swap.h"

int ft_printf_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

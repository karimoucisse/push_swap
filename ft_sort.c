#include "libft.h"
#include "push_swap.h"

int ft_find_range(int num, char **stack_b)
{
	int i;
	int min;
	int max;
	int min_p;
	int max_p;

	min = ft_atoi(stack_b[0]);
	max = ft_atoi(stack_b[0]);
	min_p = 0;
	max_p = 0;
	i = 0;

	while(stack_b[i])
	{
		if(num > ft_atoi(stack_b[i]) && (num > min || min > ft_atoi(stack_b[i])))
		{
			min_p = i;
			min = ft_atoi(stack_b[i]);
		}
		if(num < ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i]))
		{
			min_p = i;
			max = ft_atoi(stack_b[i]);
		}
		i++;
	}
	// if((ft_stack_len(stack_b) / 2) > min)

	// printf("min = %d, max = %d\n", min, max);
	return (0);
}

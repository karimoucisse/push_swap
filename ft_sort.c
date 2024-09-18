#include "libft.h"
#include "push_swap.h"


void ft_find_min_and_max(char **stack_b, int *min, int *max)
{
	int	i;

	i = -1;
	*min = ft_atoi(stack_b[0]);
	*max = ft_atoi(stack_b[0]);
	while(stack_b[++i])
	{
		if (ft_atoi(stack_b[i]) < *min)
			*min = ft_atoi(stack_b[i]);
		if (ft_atoi(stack_b[i]) > *max)
			*max = ft_atoi(stack_b[i]);
	}
}

int ft_find_range(int num, char **stack_b)
{
	int	len;
	int	min;
	int	max;
	int i;


	ft_find_min_and_max(stack_b, &min, &max);
	i = 0;
	len = ft_stack_len(stack_b);
	if (num < min || num > max)
		return (min);
	while (stack_b[i])
	{
		if(max != ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > num)
			max = ft_atoi(stack_b[i]);
		i++;
	}
	return (max);
}

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

// b to a
int ft_find_range2(int num, char **stack_b)
{
	int	len;
	int	min;
	int	max;
	int i;

	ft_find_min_and_max(stack_b, &min, &max);
	i = 0;
	len = ft_stack_len(stack_b);
	if(num > max || num < min)
		return (min);
	while (stack_b[i])
	{
		if(max != ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > num)
			max = ft_atoi(stack_b[i]);
		if(num > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > min)
			min = ft_atoi(stack_b[i]);
		i++;
	}
	return (max);
}

// a to b
int ft_find_range1(int num, char **stack_b)
{
	int	len;
	int	min;
	int	max;
	int i;

	ft_find_min_and_max(stack_b, &min, &max);
	i = 0;
	len = ft_stack_len(stack_b);
	if(num > max || num < min)
		return (max);
	while (stack_b[i])
	{
		if(max != ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > num)
			max = ft_atoi(stack_b[i]);
		if(num > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > min)
			min = ft_atoi(stack_b[i]);
		i++;
	}
	return (min);
}

void cmd_calc(int pst, char **stack, char l, t_cmd *cmd_stc)
{
	if(l == 'a')
	{
		if(pst == 0 || pst == 1)
			cmd_stc->sa = pst;
		else if(pst <= ft_stack_len(stack) / 2)
			cmd_stc->ra = pst;
		else
			cmd_stc->rra = ft_stack_len(stack) - pst;
	}
	else
	{
		if(pst == 1)
			cmd_stc->rb = 1;
		else if(pst <= ft_stack_len(stack) / 2)
			cmd_stc->rb = pst;
		else
			cmd_stc->rrb = ft_stack_len(stack) - pst;
	}
}

int cmd_calc2(t_cmd *c)
{
	if(c->rb >= c->ra && c->ra != 0)
	{
		c->rr = c->ra;
		c->rb = c->rb - c->ra;
		c->ra = 0;
	}
	if(c->ra > c->rb && c->rb != 0)
	{
		c->rr = c->rb;
		c->ra = c->ra - c->rb;
		c->rb = 0;
	}
	if(c->rrb >= c->rra && c->rra != 0)
	{
		c->rrr = c->rra;
		c->rrb = c->rrb - c->rra;
		c->rra = 0;
	}
	if(c->rra > c->rrb && c->rrb != 0)
	{
		c->rrr = c->rrb;
		c->rra = c->rra - c->rrb;
		c->rrb = 0;
	}
	return (c->rr + c->ra + c->rb + c->rrr + c->rra + c->rrb +
	c->ss + c->sa + c->sb);
}

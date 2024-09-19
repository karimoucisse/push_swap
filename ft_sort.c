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
	if (num < min)
		return (min);
	if(num > max)
		return (max);
	while (stack_b[i])
	{
		// if(max != ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > num)
		// 	max = ft_atoi(stack_b[i]);
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
		if(pst == 0)
			cmd_stc->sa = 1;
		else if(pst <= ft_stack_len(stack) / 2)
			cmd_stc->ra = cmd_stc->a_pst;
		else
			cmd_stc->rra = ft_stack_len(stack) - cmd_stc->a_pst;
	}
	else
	{
		if(pst == 0)
			cmd_stc->sb = 1;
		else if(pst <= ft_stack_len(stack) / 2)
			cmd_stc->rb = cmd_stc->b_pst;
		else
			cmd_stc->rrb = ft_stack_len(stack) - cmd_stc->b_pst;
	}
}

int cmd_calc2(t_cmd *cmd_stc)
{
	if(cmd_stc->rb > cmd_stc->ra)
	{
		cmd_stc->rr = cmd_stc->ra;
		cmd_stc->rb = cmd_stc->rb - cmd_stc->ra;
		cmd_stc->ra = 0;
	}
	if(cmd_stc->ra > cmd_stc->rb)
	{
		cmd_stc->rr = cmd_stc->rb;
		cmd_stc->ra = cmd_stc->ra - cmd_stc->rb;
		cmd_stc->rb = 0;
	}
	if(cmd_stc->rrb > cmd_stc->rra)
	{
		cmd_stc->rrr = cmd_stc->rra;
		cmd_stc->rrb = cmd_stc->rrb - cmd_stc->rra;
		cmd_stc->rra = 0;
	}
	if(cmd_stc->rra > cmd_stc->rrb)
	{
		cmd_stc->rrr = cmd_stc->rrb;
		cmd_stc->rra = cmd_stc->rra - cmd_stc->rrb;
		cmd_stc->rrb = 0;
	}
	return (cmd_stc->rr + cmd_stc->ra + cmd_stc->rb + cmd_stc->rrr + cmd_stc->rra + cmd_stc->rrb);
}

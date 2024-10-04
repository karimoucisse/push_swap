/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:46 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

void	ft_find_min_and_max(char **stack_b, int *min, int *max)
{
	int	i;

	i = -1;
	*min = ft_atoi(stack_b[0]);
	*max = ft_atoi(stack_b[0]);
	while (stack_b[++i])
	{
		if (ft_atoi(stack_b[i]) < *min)
			*min = ft_atoi(stack_b[i]);
		if (ft_atoi(stack_b[i]) > *max)
			*max = ft_atoi(stack_b[i]);
	}
}

int	ft_find_range2(int num, char **stack_b)
{
	int	len;
	int	min;
	int	max;
	int	i;

	ft_find_min_and_max(stack_b, &min, &max);
	i = 0;
	len = ft_stack_len(stack_b);
	if (num > max || num < min)
		return (min);
	while (stack_b[i])
	{
		if (max != ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i])
			&& ft_atoi(stack_b[i]) > num)
			max = ft_atoi(stack_b[i]);
		if (num > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > min)
			min = ft_atoi(stack_b[i]);
		i++;
	}
	return (max);
}

int	ft_find_range1(int num, char **stack_b)
{
	int	len;
	int	min;
	int	max;
	int	i;

	ft_find_min_and_max(stack_b, &min, &max);
	i = 0;
	len = ft_stack_len(stack_b);
	if (num > max || num < min)
		return (max);
	while (stack_b[i])
	{
		if (max != ft_atoi(stack_b[i]) && max > ft_atoi(stack_b[i])
			&& ft_atoi(stack_b[i]) > num)
			max = ft_atoi(stack_b[i]);
		if (num > ft_atoi(stack_b[i]) && ft_atoi(stack_b[i]) > min)
			min = ft_atoi(stack_b[i]);
		i++;
	}
	return (min);
}

void	cmd_calc_a_to_b(int pst, char **stack, char l, t_cmd *cmd_stc)
{
	if (l == 'a')
	{
		if (pst == 0 || pst == 1)
			cmd_stc->sa = pst;
		else if (pst <= ft_stack_len(stack) / 2)
			cmd_stc->ra = pst;
		else
			cmd_stc->rra = ft_stack_len(stack) - pst;
	}
	else
	{
		if (pst == 1)
			cmd_stc->rb = 1;
		else if (pst <= ft_stack_len(stack) / 2)
			cmd_stc->rb = pst;
		else
			cmd_stc->rrb = ft_stack_len(stack) - pst;
	}
}

void	cmd_calc_b_to_a(int pst, char **stack, char l, t_cmd *cmd_stc)
{
	if (l == 'b')
	{
		if (pst == 0 || pst == 1)
			cmd_stc->sb = pst;
		else if (pst <= ft_stack_len(stack) / 2)
			cmd_stc->rb = pst;
		else
			cmd_stc->rrb = ft_stack_len(stack) - pst;
	}
	else
	{
		if (pst == 1)
			cmd_stc->ra = 1;
		else if (pst <= ft_stack_len(stack) / 2)
			cmd_stc->ra = pst;
		else
			cmd_stc->rra = ft_stack_len(stack) - pst;
	}
}

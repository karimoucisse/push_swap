/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:21:29 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "../libft/libft.h"

void	get_number_in_order(t_cmd *cmd_stc, char **stack, int range)
{
	int	min;
	int	max;

	ft_find_min_and_max(stack, &min, &max);
	while (ft_atoi(stack[range]) != min)
	{
		if (!range)
		{
			if (ft_find_position(min, stack) >= ft_stack_len(stack) / 2)
				cmd_stc->total += ft_revs_rotate_array(stack, "rra\n");
			else
				cmd_stc->total += ft_rotate_array(stack, "ra\n");
		}
		else
		{
			if (ft_find_position(min, stack) >= ft_stack_len(stack) / 2)
				cmd_stc->total += ft_revs_rotate_array(stack, "rrb\n");
			else
				cmd_stc->total += ft_rotate_array(stack, "rb\n");
		}
	}
}

int	exec_1cmd(int *c, char **stc, char *cmd_name, int (*func)(char **, char *))
{
	int	res;

	res = 0;
	res = func(stc, cmd_name);
	*c -= 1;
	return (res);
}

int	exec_2cmd(int *c, char **a, char **b, int (*func)(char **, char **))
{
	int	res;

	res = 0;
	res = func(a, b);
	*c -= 1;
	return (res);
}

void	ft_push_a_to_b(char **stack_a, char **stack_b, t_cmd *cmd_stc)
{
	while (ft_stack_len(stack_a) > 3)
	{
		ft_find_best_position(cmd_stc, stack_a, stack_b, 'b');
		ft_exec_cmd(cmd_stc, stack_a, stack_b);
		cmd_stc->total += ft_push_elem(stack_a, stack_b, "pb\n");
		reset_cmd_struct(&cmd_stc);
	}
}

void	ft_push_b_to_a(char **stack_a, char **stack_b, t_cmd *cmd_stc)
{
	while (ft_stack_len(stack_b) > 0)
	{
		ft_find_best_position2(cmd_stc, stack_a, stack_b, 'a');
		ft_exec_cmd(cmd_stc, stack_a, stack_b);
		cmd_stc->total += ft_push_elem(stack_b, stack_a, "pa\n");
		reset_cmd_struct(&cmd_stc);
	}
}

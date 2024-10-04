/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:46:14 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

char	**char_tab(int ac, char **av)
{
	int		i;
	char	**tmp;

	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		if (!tmp)
			return (0);
	}
	else
	{
		i = 0;
		tmp = malloc(sizeof(char *) * (ac));
		if (!tmp)
			return (0);
		while (i < ac - 1)
		{
			tmp[i] = ft_strdup(av[i + 1]);
			if (!tmp[i])
				return (0);
			i++;
		}
		tmp[i] = 0;
	}
	return (tmp);
}

int	ft_stack_len(char **stack)
{
	int	len;

	len = 0;
	while (stack[len] != 0)
		len++;
	return (len);
}

int	ft_find_position(int num, char **stack)
{
	int	i;

	i = 0;
	while (ft_atoi(stack[i]) != num)
		i++;
	return (i);
}

void	ft_find_best_position(t_cmd *cmd_stc, char **a, char **b, char c)
{
	int	i;
	int	range;
	int	cmd_count;

	i = -1;
	cmd_count = 0;
	while (++i < ft_stack_len(a))
	{
		cmd_stc->a_pst = i;
		cmd_calc_a_to_b(cmd_stc->a_pst, a, 'a', cmd_stc);
		range = get_range(c, ft_atoi(a[i]), b);
		cmd_stc->b_pst = ft_find_position(range, b);
		cmd_calc_a_to_b(cmd_stc->b_pst, b, 'b', cmd_stc);
		cmd_stc->cmd_count = cmd_calc2(cmd_stc);
		if (cmd_count > cmd_stc->cmd_count || i == 0)
		{
			cmd_count = cmd_stc->cmd_count;
			cmd_stc->top_a_pst = cmd_stc->a_pst;
			cmd_stc->top_b_pst = cmd_stc->b_pst;
		}
		reset_cmd_struct(&cmd_stc);
	}
	cmd_calc_a_to_b(cmd_stc->top_a_pst, a, 'a', cmd_stc);
	cmd_calc_a_to_b(cmd_stc->top_b_pst, b, 'b', cmd_stc);
	cmd_calc2(cmd_stc);
}

void	ft_find_best_position2(t_cmd *cmd_stc, char **a, char **b, char c)
{
	int	i;
	int	range;
	int	cmd_count;

	i = -1;
	cmd_count = 0;
	while (++i < ft_stack_len(b))
	{
		cmd_stc->b_pst = i;
		cmd_calc_b_to_a(cmd_stc->b_pst, b, 'b', cmd_stc);
		range = get_range(c, ft_atoi(b[i]), a);
		cmd_stc->a_pst = ft_find_position(range, a);
		cmd_calc_b_to_a(cmd_stc->a_pst, a, 'a', cmd_stc);
		cmd_stc->cmd_count = cmd_calc2(cmd_stc);
		if (cmd_count > cmd_stc->cmd_count || i == 0)
		{
			cmd_count = cmd_stc->cmd_count;
			cmd_stc->top_b_pst = cmd_stc->b_pst;
			cmd_stc->top_a_pst = cmd_stc->a_pst;
		}
		reset_cmd_struct(&cmd_stc);
	}
	cmd_calc_b_to_a(cmd_stc->top_b_pst, b, 'b', cmd_stc);
	cmd_calc_b_to_a(cmd_stc->top_a_pst, a, 'a', cmd_stc);
	cmd_calc2(cmd_stc);
}

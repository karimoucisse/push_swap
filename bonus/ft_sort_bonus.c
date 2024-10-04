/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:21:29 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 20:12:47 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "../libft/libft.h"
#include "../gnl/get_next_line.h"

int	exec_1cmd(char **stack, int (*func)(char **))
{
	int	res;

	if (stack == NULL || ft_stack_len(stack) == 0)
		return (1);
	res = 0;
	res = func(stack);
	return (1);
}

int	exec_2cmd(char **a, char **b, int (*func)(char **, char **))
{
	int	res;

	res = 0;
	res = func(a, b);
	return (res);
}

int	handle_cmd_loop(char **a, char **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		if (ft_strlen(str) == 1 || str == NULL || ft_strlen(str) == 0)
			break ;
		if (!ft_exec_cmd(str, a, b))
		{
			free(str);
			return (0);
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
	return (1);
}

int	ft_exec_cmd(char *str, char **a, char **b)
{
	if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		return (exec_2cmd(a, b, ft_push_elem));
	if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		return (exec_2cmd(b, a, ft_push_elem));
	if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		return (exec_2cmd(a, b, ft_swap_positions));
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		return (exec_1cmd(a, ft_swap_position));
	if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		return (exec_1cmd(b, ft_swap_position));
	if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		return (exec_2cmd(a, b, ft_rotate_arrays));
	if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		return (exec_2cmd(a, b, ft_revs_rotate_arrays));
	if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		return (exec_1cmd(a, ft_rotate_array));
	if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		return (exec_1cmd(b, ft_rotate_array));
	if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		return (exec_1cmd(a, ft_revs_rotate_array));
	if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		return (exec_1cmd(b, ft_revs_rotate_array));
	return (0);
}

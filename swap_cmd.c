/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:46:11 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/20 18:46:12 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int	ft_swap_position(char **stack, char *cmd)
{
	char	*copy;

	copy = stack[0];
	if (!copy)
		return (0);
	stack[0] = stack[1];
	stack[1] = copy;
	write(1, cmd, 3);
	return (1);
}

int	ft_push_elem(char **stack_a, char **stack_b, char *cmd)
{
	int		i;
	char	*cpy_a;
	char	*cpy_b;

	i = 1;
	cpy_a = stack_a[0];
	while (stack_a[i])
	{
		stack_a[i - 1] = stack_a[i];
		i++;
	}
	stack_a[i - 1] = NULL;
	if (!stack_b[0])
		stack_b[0] = cpy_a;
	else
	{
		i = 0;
		while (stack_b[i])
		{
			cpy_b = stack_b[i];
			stack_b[i] = cpy_a;
			cpy_a = cpy_b;
			i++;
		}
		stack_b[i] = cpy_a;
	}
	write(1, cmd, 3);
	return (1);
}

int	ft_rotate_array(char **stack, char *cmd)
{
	int		i;
	char	*cpy;

	i = 1;
	cpy = stack[i - 1];
	while (stack[i])
	{
		stack[i - 1] = stack[i];
		i++;
	}
	stack[i - 1] = cpy;
	if(cmd)
		write(1, cmd, 3);
	return (1);
}

int	ft_rotate_arrays(char **stack_a, char **stack_b)
{
	ft_rotate_array(stack_a, NULL);
	ft_rotate_array(stack_b, NULL);
	write(1, "RR\n", 3);
	return (1);
}

int	ft_revs_rotate_array(char **stack, char *cmd)
{
	int		i;
	char	*cpy;

	i = ft_stack_len(stack) - 1;
	cpy = stack[i];
	while (i)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = cpy;
	if(cmd)
		write(1, cmd, 4);
	return (1);
}

int	ft_revs_rotate_arrays(char **stack_a, char **stack_b)
{
	ft_revs_rotate_array(stack_a, NULL);
	ft_revs_rotate_array(stack_b, NULL);
	write(1, "RRR\n", 4);
	return (1);
}

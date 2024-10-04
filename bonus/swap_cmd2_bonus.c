/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd2_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:34:18 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

int	ft_rotate_arrays(char **stack_a, char **stack_b)
{
	if (ft_stack_len(stack_a) > 0)
		ft_rotate_array(stack_a);
	if (ft_stack_len(stack_b) > 0)
		ft_rotate_array(stack_b);
	return (1);
}

int	ft_revs_rotate_arrays(char **stack_a, char **stack_b)
{
	if (ft_stack_len(stack_a) > 0)
		ft_revs_rotate_array(stack_a);
	if (ft_stack_len(stack_b) > 0)
		ft_revs_rotate_array(stack_b);
	return (1);
}

int	ft_swap_positions(char **stack_a, char **stack_b)
{
	if (ft_stack_len(stack_a) > 0)
		ft_swap_position(stack_a);
	if (ft_stack_len(stack_b) > 0)
		ft_swap_position(stack_b);
	return (1);
}

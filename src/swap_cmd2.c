/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_cmd2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:34:18 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_rotate_arrays(char **stack_a, char **stack_b)
{
	ft_rotate_array(stack_a, NULL);
	ft_rotate_array(stack_b, NULL);
	write(1, "rr\n", 3);
	return (1);
}

int	ft_revs_rotate_arrays(char **stack_a, char **stack_b)
{
	ft_revs_rotate_array(stack_a, NULL);
	ft_revs_rotate_array(stack_b, NULL);
	write(1, "rrr\n", 4);
	return (1);
}

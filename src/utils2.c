/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 16:43:02 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	get_range(char c, int value, char **b)
{
	if (c == 'b')
		return (ft_find_range1(value, b));
	else
		return (ft_find_range2(value, b));
}

void	calculate(int *a, int *b, int *result)
{
	if (*b >= *a && *a != 0)
	{
		*result = *a;
		*b -= *a;
		*a = 0;
	}
	if (*a > *b && *b != 0)
	{
		*result = *b;
		*a -= *b;
		*b = 0;
	}
}

int	cmd_calc2(t_cmd *c)
{
	calculate(&(c->ra), &(c->rb), &(c->rr));
	calculate(&(c->rra), &(c->rrb), &(c->rrr));
	return (c->rr + c->ra + c->rb + c->rrr + c->rra + c->rrb
		+ c->sa + c->sb);
}

int	ft_count_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			len++;
		i++;
	}
	if (len == 0)
		return (2);
	else
		return (len + 2);
}

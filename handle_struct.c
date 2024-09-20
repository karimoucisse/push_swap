/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:58 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/20 18:45:59 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"

int ft_fill_stack_a(int ac, char **av, t_stack *a)
{
	char **tmp;
	int num;
	int i;

	tmp = char_tab(ac, av);
	if (!tmp)
		return (0);
	i = 0;
	while (tmp[i])
	{
		num = ft_atoi(tmp[i]);
		a->stack[i] = ft_itoa(num);
		if (ft_strlen(tmp[i]) > 1 && a->stack[i] == 0)
			return (0);
		if ((ft_strlen(tmp[i]) == 1 && tmp[i][0] != 0) && a->stack[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

int init_stack_struct(int ac, char **av, t_stack *a, t_stack *b)
{
	int len;

	if (ac == 2)
		len = ft_strlen(av[1]);
	else
		len = ac;
	a->rev = 0;
	a->stack = malloc(sizeof(char *) * len);
	b->rev = 0;
	b->stack = malloc(sizeof(char *) * len);
	if (!a->stack || !b->stack)
		return (0);
	if (!ft_fill_stack_a(ac, av, a))
		return (0);
	b->stack[len] = 0;
	a->stack[len] = 0;
	return (1);
}

int init_cmd_struct(t_cmd **cmd)
{
	*cmd = malloc(sizeof(t_cmd));
	if (!cmd)
		return (0);
	(*cmd)->a_pst = 0;
	(*cmd)->b_pst = 0;
	(*cmd)->sb = 0;
	(*cmd)->sa = 0;
	(*cmd)->ss = 0;
	(*cmd)->top_a_pst = 0;
	(*cmd)->top_b_pst = 0;
	(*cmd)->ra = 0;
	(*cmd)->rb = 0;
	(*cmd)->rr = 0;
	(*cmd)->rra = 0;
	(*cmd)->rrb = 0;
	(*cmd)->rrr = 0;
	(*cmd)->total_count = 0;
	(*cmd)->cmd_count = 0;
	return (1);
}

void reset_cmd_struct(t_cmd **cmd)
{
	(*cmd)->a_pst = 0;
	(*cmd)->b_pst = 0;
	(*cmd)->sb = 0;
	(*cmd)->sa = 0;
	(*cmd)->ss = 0;
	(*cmd)->ra = 0;
	(*cmd)->rb = 0;
	(*cmd)->rr = 0;
	(*cmd)->rra = 0;
	(*cmd)->rrb = 0;
	(*cmd)->rrr = 0;
}

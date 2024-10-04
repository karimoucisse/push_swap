/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:58 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/03 19:57:48 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_fill_stack_a(int ac, char **av, char **stack_a)
{
	char	**tmp;
	int		num;
	int		i;

	tmp = char_tab(ac, av);
	if (tmp == NULL)
		return (free_char(tmp));
	i = 0;
	while (tmp[i])
	{
		num = ft_atoi(tmp[i]);
		printf("num = %d, num2 = ", num);
		stack_a[i] = ft_itoa(num);
		if((stack_a[i][0] == '-' && tmp[i][0] != '-')
			|| (stack_a[i][0] != '-' && tmp[i][0] == '-'))
			return (free_char(tmp));
		if (stack_a[i] == NULL || stack_a == NULL)
			return (free_char(tmp));
		if (ft_strlen(tmp[i]) > 1 && stack_a[i] == 0)
			return (free_char(tmp));
		if ((ft_strlen(tmp[i]) == 1 && tmp[i][0] != 0) && stack_a[i] == 0)
			return (free_char(tmp));
		i++;
	}
	free_char(tmp);
	return (1);
}

int	init_stack_chars(int ac, char **av, char ***a, char ***b)
{
	int	len;

	if (ac == 2)
		len = ft_count_space(av[1]);
	else
		len = ac;
	if (len == 2)
		return (len);
	*a = malloc(sizeof(char *) * len);
	*b = malloc(sizeof(char *) * len);
	if ((*a == NULL || *b == NULL))
		return (0);
	while (--len >= 0)
	{
		(*a)[len] = NULL;
		(*b)[len] = NULL;
	}
	if (!ft_fill_stack_a(ac, av, *a))
		return (0);
	return (1);
}

int	init_cmd_struct(t_cmd **cmd)
{
	*cmd = malloc(sizeof(t_cmd));
	if (!(*cmd))
		return (0);
	(*cmd)->a_pst = 0;
	(*cmd)->b_pst = 0;
	(*cmd)->sb = 0;
	(*cmd)->sa = 0;
	(*cmd)->top_a_pst = 0;
	(*cmd)->top_b_pst = 0;
	(*cmd)->ra = 0;
	(*cmd)->rb = 0;
	(*cmd)->rr = 0;
	(*cmd)->rra = 0;
	(*cmd)->rrb = 0;
	(*cmd)->rrr = 0;
	(*cmd)->total = 0;
	(*cmd)->cmd_count = 0;
	return (1);
}

void	reset_cmd_struct(t_cmd **cmd)
{
	(*cmd)->a_pst = 0;
	(*cmd)->b_pst = 0;
	(*cmd)->sb = 0;
	(*cmd)->sa = 0;
	(*cmd)->ra = 0;
	(*cmd)->rb = 0;
	(*cmd)->rr = 0;
	(*cmd)->rra = 0;
	(*cmd)->rrb = 0;
	(*cmd)->rrr = 0;
}

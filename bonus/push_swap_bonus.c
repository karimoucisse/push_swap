/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:13 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/03 20:00:17 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

int	ft_sort_tester(char **stack)
{
	int	i;

	if (ft_stack_len(stack) == 0)
		return (0);
	i = 0;
	while (stack[i])
	{
		if (stack[i + 1] && (ft_atoi(stack[i]) > ft_atoi(stack[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	char	**stack_a;
	char	**stack_b;
	int		status;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		exit(1);
	if (!ft_check_char(av, ac))
		ft_print_error();
	status = init_stack_chars(ac, av, &stack_a, &stack_b);
	if (status != 1)
		ft_free(stack_a, stack_b, status);
	if (!ft_check_duplicate(stack_a))
		free_chars(stack_a, stack_b, 0);
	if (!handle_cmd_loop(stack_a, stack_b))
		free_chars(stack_a, stack_b, 0);
	if (!ft_sort_tester(stack_a) || ft_stack_len(stack_b) != 0)
		print_res(stack_a, stack_b, 0);
	else
		print_res(stack_a, stack_b, 1);
}

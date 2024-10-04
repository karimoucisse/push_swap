/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:13 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/03 20:25:48 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_mini_sort(char **stack)
{
	int	total;

	total = 0;
	if (ft_stack_len(stack) == 1)
		return (0);
	while (!ft_sort_tester(stack))
	{
		if (ft_atoi(stack[0]) > ft_atoi(stack[1]))
			total += ft_swap_position(stack, "sa\n");
		if (stack[2] && (ft_atoi(stack[0]) > ft_atoi(stack[2])))
			total += ft_revs_rotate_array(stack, "rra\n");
		if (stack[2] && (ft_atoi(stack[1]) > ft_atoi(stack[2])))
			total += ft_rotate_array(stack, "ra\n");
	}
	return (total);
}

int	ft_sort_tester(char **stack)
{
	int	i;

	i = 0;
	while (stack[i])
	{
		if (stack[i + 1] && (ft_atoi(stack[i]) > ft_atoi(stack[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_sort_stack(char **stack_a, char **stack_b)
{
	int		cmd_count;
	t_cmd	*cmd_stc;
	int		total;

	cmd_count = 0;
	cmd_stc = NULL;
	if (!init_cmd_struct(&cmd_stc))
		return (0);
	cmd_stc->total += ft_push_elem(stack_a, stack_b, "pb\n");
	cmd_stc->total += ft_push_elem(stack_a, stack_b, "pb\n");
	ft_push_a_to_b(stack_a, stack_b, cmd_stc);
	cmd_stc->total = ft_mini_sort(stack_a);
	ft_push_b_to_a(stack_a, stack_b, cmd_stc);
	get_number_in_order(cmd_stc, stack_a, 0);
	total = cmd_stc->total;
	free(cmd_stc);
	return (1);
}

void	ft_exec_cmd(t_cmd *c, char **a, char **b)
{
	while ((c->sa + c->sb + c->rr + c->rrr + c->ra
			+ c->rb + c->rra + c->rrb) > 0)
	{
		if (c->sa)
			c->total += exec_1cmd(&(c->sa), a, "sa\n", ft_swap_position);
		if (c->sb)
			c->total += exec_1cmd(&(c->sb), b, "sb\n", ft_swap_position);
		if (c->rr)
			c->total += exec_2cmd(&(c->rr), a, b, ft_rotate_arrays);
		if (c->rrr)
			c->total += exec_2cmd(&(c->rrr), a, b, ft_revs_rotate_arrays);
		if (c->ra)
			c->total += exec_1cmd(&(c->ra), a, "ra\n", ft_rotate_array);
		if (c->rb)
			c->total += exec_1cmd(&(c->rb), b, "rb\n", ft_rotate_array);
		if (c->rra)
			c->total += exec_1cmd(&(c->rra), a, "rra\n", ft_revs_rotate_array);
		if (c->rrb)
			c->total += exec_1cmd(&(c->rrb), b, "rrb\n", ft_revs_rotate_array);
	}
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
	if (ft_sort_tester(stack_a))
		free_chars(stack_a, stack_b, 1);
	if (ft_stack_len(stack_a) <= 3)
	{
		ft_mini_sort(stack_a);
		free_chars(stack_a, stack_b, 1);
	}
	else if (!ft_sort_stack(stack_a, stack_b))
		free_chars(stack_a, stack_b, 0);
	free_chars(stack_a, stack_b, 1);
}

// void	sort_three(t_node *stack_a)
// {
// 	if (stack_a->content > stack_a->next->content)
// 	{
// 		if (stack_a->content < stack_a->next->next->content)
// 			execute(&stack_a, NULL, "sa", false);
// 		else if (stack_a->next->content > stack_a->next->next->content)
// 		{
// 			execute(&stack_a, NULL, "sa", false);
// 			execute(&stack_a, NULL, "rra", false);
// 		}
// 		else
// 			execute(&stack_a, NULL, "ra", false);
// 	}
// 	else if (stack_a->content < stack_a->next->content)
// 	{
// 		if (stack_a->content > stack_a->next->next->content)
// 			execute(&stack_a, NULL, "rra", false);
// 		else if (stack_a->next->content > stack_a->next->next->content)
// 		{
// 			execute(&stack_a, NULL, "sa", false);
// 			execute(&stack_a, NULL, "ra", false);
// 		}
// 	}
// }

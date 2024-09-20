#include "libft.h"
#include "push_swap.h"

void get_descending_order_stack(t_cmd *cmd_stc, char **stack)
{
	int min;
	int max;
	ft_find_min_and_max(stack, &min, &max);
	while (ft_atoi(stack[ft_stack_len(stack) - 1]) != min)
	{
		if (ft_find_position(min, stack) >= ft_stack_len(stack) / 2)
			cmd_stc->total_count += ft_revs_rotate_array(stack);
		else
			cmd_stc->total_count += ft_rotate_array(stack);
	}
}


void get_ascending_order_stack(t_cmd *cmd_stc, char **stack)
{
	int min;
	int max;
	ft_find_min_and_max(stack, &min, &max);
	while (ft_atoi(stack[0]) != min)
	{
		if (ft_find_position(min, stack) >= ft_stack_len(stack) / 2)
			cmd_stc->total_count += ft_revs_rotate_array(stack);
		else
			cmd_stc->total_count += ft_rotate_array(stack);
	}
}

void ft_mini_sort(t_cmd *cmd_stc, char **stack)
{
	while (!ft_sort_tester(stack))
	{
		if (ft_atoi(stack[0]) > ft_atoi(stack[1]))
			cmd_stc->total_count += ft_swap_position(stack);
		if (ft_atoi(stack[0]) > ft_atoi(stack[2]))
			cmd_stc->total_count += ft_revs_rotate_array(stack);
		if (ft_atoi(stack[1]) > ft_atoi(stack[2]))
			cmd_stc->total_count += ft_rotate_array(stack);
	}
}

int ft_sort_tester(char **stack)
{
	int i;

	i = 0;
	while (stack[i])
	{
		if (stack[i + 1] && ft_atoi(stack[i]) > ft_atoi(stack[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

int ft_sort_stack(t_stack *a, t_stack *b)
{
	int range;
	int i;
	int cmd_count;
	t_cmd *cmd_stc;

	i = 0;
	cmd_count = 0;
	if (!init_cmd_struct(&cmd_stc))
		return (0);
	cmd_stc->total_count += ft_push_elem(a->stack, b->stack);
	cmd_stc->total_count += ft_push_elem(a->stack, b->stack);
	ft_revs_rotate_array(b->stack);
	while (ft_stack_len(a->stack) > 3)
	{
		ft_find_best_position(cmd_stc, a->stack, b->stack, 'b');
		ft_exec_cmd(cmd_stc, a->stack, b->stack);
		cmd_stc->total_count += ft_push_elem(a->stack, b->stack);
		reset_cmd_struct(&cmd_stc);
		i++;
	}
	get_descending_order_stack(cmd_stc, b->stack);
	ft_mini_sort(cmd_stc, a->stack);
	while(ft_stack_len(b->stack) > 0)
	{
		ft_find_best_position(cmd_stc, b->stack, a->stack, 'a');
		ft_exec_cmd(cmd_stc, b->stack, a->stack);
		cmd_stc->total_count += ft_push_elem(b->stack, a->stack);
		reset_cmd_struct(&cmd_stc);
		i++;
	}
	// get_ascending_order_stack(cmd_stc, a->stack);
	return (cmd_stc->total_count);
}

int ft_exec_cmd(t_cmd *c, char **stack_a, char **stack_b)
{
	while ((c->sa + c->sb + c->ss + c->rr + c->rrr + c->ra + c->rb + c->rra + c->rrb) > 0)
	{
		if (c->sa)
		{
			c->total_count += ft_swap_position(stack_a);
			--c->sa;
		}
		if (c->sb)
		{
			c->total_count += ft_swap_position(stack_b);
			--c->sb;
		}
		if (c->ss)
		{
			c->total_count += ft_swap_position(stack_a);
			ft_swap_position(stack_b);
			--c->ss;
		}
		if (c->rr)
		{
			ft_rotate_array(stack_a);
			c->total_count += ft_rotate_array(stack_b);
			--c->rr;
		}
		if (c->rrr)
		{
			ft_revs_rotate_array(stack_a);
			c->total_count += ft_revs_rotate_array(stack_b);
			--c->rrr;
		}
		if (c->ra)
		{
			c->total_count += ft_rotate_array(stack_a);
			--c->ra;
		}
		if (c->rb)
		{
			c->total_count += ft_rotate_array(stack_b);
			--c->rb;
		}
		if (c->rra)
		{
			c->total_count += ft_revs_rotate_array(stack_a);
			--c->rra;
		}
		if (c->rrb)
		{
			c->total_count += ft_revs_rotate_array(stack_b);
			--c->rrb;
		}
	}
	return (1);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;
	int total;

	if (ac < 3)
		return (ft_print_error());
	if (!ft_check_char(av, ac))
		return (ft_print_error());
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	i = 0;
	total = 0;
	if (!init_stack_struct(ac, av, stack_a, stack_b))
		return (ft_print_error());
	total = ft_sort_stack(stack_a, stack_b);
	if (!total)
		return (ft_print_error());
	if(ft_sort_tester(stack_a->stack) && total < 700)
		printf("yes yes\n");
	else
		printf("NO NO\n");
	printf("Total = %d\n", total);
	// printf("a	b\n\n");
	// while (stack_a->stack[i] || stack_b->stack[i])
	// {
	// 	if (stack_a->stack[i])
	// 		printf("%s", stack_a->stack[i]);
	// 	printf("	");
	// 	if (stack_b->stack[i])
	// 		printf("%s", stack_b->stack[i]);
	// 	printf("\n");
	// 	i++;
	// }
}

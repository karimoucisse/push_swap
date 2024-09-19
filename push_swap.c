#include "libft.h"
#include "push_swap.h"

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
	ft_find_best_position(cmd_stc, a->stack, b->stack);
	ft_exec_cmd(cmd_stc, a->stack, b->stack);
	return (1);
}

int ft_exec_cmd(t_cmd *cmd_stc, char **stack_a, char **stack_b)
{
	if (cmd_stc->sa)
		ft_swap_position(stack_a);
	if (cmd_stc->sb)
		ft_swap_position(stack_b);
	if (cmd_stc->ss)
	{
		ft_swap_position(stack_a);
		ft_swap_position(stack_b);
	}
	if (cmd_stc->rr)
	{
		ft_rotate_array(stack_a);
		ft_rotate_array(stack_b);
	}
	if (cmd_stc->rrr)
	{
		ft_revs_rotate_array(stack_a);
		ft_revs_rotate_array(stack_b);
	}
	if (cmd_stc->ra)
		ft_rotate_array(stack_a);
	if (cmd_stc->rb)
		ft_rotate_array(stack_b);
	if (cmd_stc->rra)
		ft_revs_rotate_array(stack_a);
	if (cmd_stc->rrb)
		ft_revs_rotate_array(stack_b);
	return (1);
}

int main(int ac, char **av)
{
	t_stack *stack_a;
	t_stack *stack_b;
	int i;

	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		return (0);
	i = 0;
	if (ac < 2)
		return (ft_print_error());
	if (!ft_check_char(av, ac))
		return (ft_print_error());
	if (!init_stack_struct(ac, av, stack_a, stack_b))
		return (ft_print_error());
	if (!ft_sort_stack(stack_a, stack_b))
		return (ft_print_error());
	// ft_push_elem(stack_a->stack, stack_b->stack);
	// ft_push_elem(stack_a->stack, stack_b->stack);
	// // ft_rotate_array(stack_a->stack);
	printf("a	b\n\n");
	while (stack_a->stack[i] && ft_stack_len(stack_a->stack))
	{
		printf("%s	", stack_a->stack[i]);
		if (stack_b->stack[i] && ft_stack_len(stack_b->stack))
			printf("%s", stack_b->stack[i]);
		printf("\n");
		i++;
	}
}

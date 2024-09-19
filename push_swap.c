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
	if(!init_cmd_struct(&cmd_stc))
		return (0);
	cmd_stc->total_count += ft_push_elem(a->stack, b->stack);
	cmd_stc->total_count += ft_push_elem(a->stack, b->stack);
	while(i < ft_stack_len(a->stack))
	{
		cmd_stc->a_pst = i;
		cmd_calc(cmd_stc->a_pst, a->stack, 'a', cmd_stc);
		range = ft_find_range(atoi(a->stack[i]), b->stack);
		cmd_stc->b_pst = ft_find_position(range, b->stack);
		cmd_calc(cmd_stc->b_pst, b->stack, 'b', cmd_stc);
		cmd_stc->cmd_count = cmd_calc2(cmd_stc);
		if(cmd_count > cmd_stc->cmd_count)
		{
			cmd_count = cmd_stc->cmd_count;
			cmd_stc->top_a_pst = cmd_stc->a_pst;
			cmd_stc->top_b_pst = cmd_stc->b_pst;
		}
		reset_cmd_struct(&cmd_stc);
		i++;
	}
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

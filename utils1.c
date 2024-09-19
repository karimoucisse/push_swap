#include "libft.h"
#include "push_swap.h"

char **char_tab(int ac, char **av)
{
	int i;
	char **tmp;

	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
	{
		i = 0;
		tmp = malloc(sizeof(char *) * (ac));
		while (i < ac - 1)
		{
			tmp[i] = ft_strdup(av[i + 1]);
			if (!tmp[i])
			{
				return (0);
			}
			i++;
		}
		tmp[i] = 0;
	}
	return (tmp);
}

int ft_stack_len(char **stack)
{
	int len;

	len = 0;
	while (stack[len] != 0)
		len++;
	return (len);
}

int ft_find_position(int num, char **stack)
{
	int i;

	i = 0;
	while (ft_atoi(stack[i]) != num)
		i++;
	return (i);
}

void ft_find_best_position(t_cmd *cmd_stc, char **stack_a, char **stack_b)
{
	int i;
	int range;
	int cmd_count;

	i = 0;
	cmd_count = 0;
	while (i < ft_stack_len(stack_a))
	{
		cmd_stc->a_pst = i;
		cmd_calc(cmd_stc->a_pst, stack_a, 'a', cmd_stc);
		range = ft_find_range(ft_atoi(stack_a[i]), stack_b);
		cmd_stc->b_pst = ft_find_position(range, stack_b);
		cmd_calc(cmd_stc->b_pst, stack_b, 'b', cmd_stc);
		cmd_stc->cmd_count = cmd_calc2(cmd_stc);
		if (cmd_count > cmd_stc->cmd_count || i == 0)
		{
			cmd_count = cmd_stc->cmd_count;
			cmd_stc->top_a_pst = cmd_stc->a_pst;
			cmd_stc->top_b_pst = cmd_stc->b_pst;
		}
		reset_cmd_struct(&cmd_stc);
		i++;
	}
	cmd_calc(cmd_stc->top_a_pst, stack_a, 'a', cmd_stc);
	cmd_calc(cmd_stc->top_b_pst, stack_b, 'b', cmd_stc);
	cmd_calc2(cmd_stc);
}

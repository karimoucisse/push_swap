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

int init_struct(int ac, char **av, t_stack *a, t_stack *b)
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

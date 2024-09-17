#include "libft.h"
#include "push_swap.h"

char **char_tab(int ac, char **av, t_stack **a)
{
	int i;
	char **tmp;

	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	else
	{
		i = 0;
		tmp = malloc(sizeof(char *) * (ac));
		while(i < ac - 1)
		{
			tmp[i] = ft_strdup(av[i + 1]);
			if (!tmp[i])
			{
				return(0);
			}
			i++;
		}
		tmp[i] = 0;
	}
	return(tmp);
}

int ft_stack_len(char **stack)
{
	int	len;

	len = 0;
	while(stack[len])
		len++;
	return (len);
}


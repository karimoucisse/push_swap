/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_struct_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:58 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/04 10:34:39 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

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
		stack_a[i] = ft_itoa(num);
		if ((num == -2147483648 && tmp[i][0] != '-')
			|| (num == 2147483647 && tmp[i][0] == '-'))
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
	*a = malloc(sizeof(char *) * len);
	*b = malloc(sizeof(char *) * len);
	if ((*a == NULL || *b == NULL) || (a == NULL || b == NULL))
		return (0);
	while (--len >= 0)
	{
		(*a)[len] = NULL;
		(*b)[len] = NULL;
	}
	if (ft_stack_len(*a) == 1 && (ft_atoi((*a)[0]) == 0
		&& ft_strncmp((*a)[0], "0", ft_strlen((*a)[0]))))
		return (0);
	if (!ft_fill_stack_a(ac, av, *a))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:46:14 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

char	**char_tab(int ac, char **av)
{
	int		i;
	char	**tmp;

	if (ac == 2)
	{
		tmp = ft_split(av[1], ' ');
		if (!tmp)
			return (0);
	}
	else
	{
		i = 0;
		tmp = malloc(sizeof(char *) * (ac));
		if (!tmp)
			return (0);
		while (i < ac - 1)
		{
			tmp[i] = ft_strdup(av[i + 1]);
			if (!tmp[i])
				return (0);
			i++;
		}
		tmp[i] = 0;
	}
	return (tmp);
}

int	ft_stack_len(char **stack)
{
	int	len;

	len = 0;
	while (stack[len] != 0)
		len++;
	return (len);
}

int	ft_count_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			len++;
		i++;
	}
	if (len == 0)
		return (2);
	else
		return (len + 2);
}

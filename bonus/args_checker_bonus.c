/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:20 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

int	ft_check_espace(char *av, int ac)
{
	int	i;

	if (av[0] == ' ' || av[ft_strlen(av) - 1] == ' ')
		return (0);
	i = 0;
	while (*av)
	{
		if (*av == ' ' && ac > 2)
			return (0);
		else if (*av == ' ')
			i++;
		else
			i = 0;
		if (i > 1)
			return (0);
		av++;
	}
	return (1);
}

int	ft_check_val(char *av, int ac)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_strchr("+-0123456789", av[i]) && ac > 2)
			return (0);
		if (!ft_strchr("+-0123456789 ", av[i]) && ac == 2)
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_sign(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if ((av[i] == '+' || av[i] == '-') && !av[i + 1])
			return (0);
		if ((av[i] == '+' || av[i] == '-') && av[i + 1])
		{
			if (!ft_strchr("0123456789", av[i + 1]))
				return (0);
		}
		if ((av[i] == '+' || av[i] == '-') && av[i - 1])
		{
			if (ft_strchr("0123456789", av[i - 1]))
				return (0);
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate(char **stack)
{
	int	i;
	int	j;

	i = 0;
	while (stack[i])
	{
		j = i + 1;
		while (stack[j])
		{
			if (ft_atoi(stack[i]) == ft_atoi(stack[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_char(char **av, int ac)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (!ft_check_espace(av[i], ac))
			return (0);
		if (!ft_check_val(av[i], ac))
			return (0);
		if (!ft_check_sign(av[i]))
			return (0);
		i++;
	}
	return (1);
}

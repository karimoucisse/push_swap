/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:53 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:49:08 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap_bonus.h"

void	ft_free(char **a, char **b, int status)
{
	free(a);
	free(b);
	if (status == 0)
		ft_print_error();
	else
		exit(EXIT_SUCCESS);
}

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	free_char(char **tmp)
{
	int	i;

	i = 0;
	if (tmp == NULL)
		return (0);
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (0);
}

void	print_res(char **a, char **b, int status)
{
	if (!status)
	{
		write(1, "KO\n", 3);
		free_char(a);
		free_char(b);
		exit(EXIT_FAILURE);
	}
	else
	{
		write(1, "OK\n", 3);
		free_char(a);
		free_char(b);
		exit(EXIT_SUCCESS);
	}
}

void	free_chars(char **a, char **b, int status)
{
	free_char(a);
	free_char(b);
	if (!status)
		ft_print_error();
}

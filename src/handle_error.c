/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:45:53 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:22:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "push_swap.h"

int	ft_print_error(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	free_char(char **tmp)
{
	int	i;

	i = 0;
	if (tmp == NULL || !tmp)
		return (0);
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (0);
}

void	free_chars(char **a, char **b, int status)
{
	if (a[0] || a)
		free_char(a);
	if (b[0] || b)
		free_char(b);
	if (status == 0)
		ft_print_error();
	else
		exit(EXIT_SUCCESS);
}

void	ft_free(char **a, char **b, int status)
{
	free(a);
	free(b);
	if (status == 0)
		ft_print_error();
	else
		exit(EXIT_SUCCESS);
}

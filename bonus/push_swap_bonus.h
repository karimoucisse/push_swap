/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:46:08 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/29 19:49:19 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_cmd
{
	int	a_pst;
	int	b_pst;
	int	top_a_pst;
	int	top_b_pst;
	int	sb;
	int	sa;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
	int	cmd_count;
}t_cmd;

// MAIN
int		ft_sort_tester(char **stack);

// ARGS CHECKER
int		ft_check_espace(char *av, int ac);
int		ft_check_val(char *av, int ac);
int		ft_check_sign(char *av);
int		ft_check_duplicate(char **stack);
int		ft_check_char(char **av, int ac);

// HANDLE STRUCT
int		init_stack_chars(int ac, char **av, char ***a, char ***b);
int		ft_fill_stack_a(int ac, char **av, char **a);

// HANDLE ERROR
int		ft_print_error(void);
void	free_chars(char **stack1, char **stack2, int status);
int		free_char(char **tmp);
void	print_res(char **a, char **b, int status);

// UTILS 1
char	**char_tab(int ac, char **av);
int		ft_stack_len(char **stack);
int		ft_count_space(char *str);
void	free_chars(char **a, char **b, int status);
void	ft_free(char **a, char **b, int status);

// SWAP CMD 1
int		ft_swap_position(char **stack);
int		ft_rotate_array(char **stack);
int		ft_revs_rotate_array(char **stack);
int		ft_push_elem(char **stack_a, char **stack_b);

// SWAP CMD 2
int		ft_revs_rotate_arrays(char **stack_a, char **stack_b);
int		ft_rotate_arrays(char **stack_a, char **stack_b);
int		ft_swap_positions(char **stack_a, char **stack_b);

// FT_SORT
int		exec_1cmd(char **stc, int (*func)(char **));
int		exec_2cmd(char **a, char **b, int (*func)(char **, char **));
int		handle_cmd_loop(char **a, char **b);
int		ft_exec_cmd(char *str, char **a, char **b);
#endif

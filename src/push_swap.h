/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:46:08 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/04 10:45:17 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
int		ft_sort_stack(char **a, char **b);
void	ft_exec_cmd(t_cmd *cmd_stc, char **stack_a, char **stack_b);
int		ft_sort_tester(char **stack);
int		ft_mini_sort(char **stack);

// ARGS CHECKER
int		ft_check_espace(char *av, int ac);
int		ft_check_val(char *av, int ac);
int		ft_check_sign(char *av);
int		ft_check_duplicate(char **stack);
int		ft_check_char(char **av, int ac);

// HANDLE STRUCT
int		init_stack_chars(int ac, char **av, char ***a, char ***b);
int		ft_fill_stack_a(int ac, char **av, char **a);
int		init_cmd_struct(t_cmd **cmd);
void	reset_cmd_struct(t_cmd **cmd);

// HANDLE ERROR
int		ft_print_error(void);
void	free_chars(char **stack1, char **stack2, int status);
int		free_char(char **tmp);
void	ft_free(char **a, char **b, int status);

// UTILS 1
char	**char_tab(int ac, char **av);
int		ft_stack_len(char **stack);
int		ft_find_position(int num, char **stack);
void	ft_find_best_position(t_cmd *cmd_stc, char **a, char **b, char c);

// UTILS 2
int		get_range(char c, int value, char **b);
void	calculate(int *a, int *b, int *result);
int		cmd_calc2(t_cmd *cmd_stc);
int		ft_count_space(char *str);
int		handle_case_1(char **stack);

// SWAP CMD
int		ft_swap_position(char **stack, char *cmd);
int		ft_rotate_array(char **stack, char *cmd);
int		ft_revs_rotate_array(char **stack, char *cmd);
int		ft_push_elem(char **stack_a, char **stack_b, char *cmd);
int		ft_revs_rotate_arrays(char **stack_a, char **stack_b);
int		ft_rotate_arrays(char **stack_a, char **stack_b);

// FT_SORT 1
int		ft_find_range1(int num, char **stack_b);
int		ft_find_range2(int num, char **stack_b);
void	cmd_calc_a_to_b(int pst, char **stack, char l, t_cmd *cmd_stc);
void	cmd_calc_b_to_a(int pst, char **stack, char l, t_cmd *cmd_stc);
void	ft_find_min_and_max(char **stack_b, int *min, int *max);

// FT_SORT 2
void	get_number_in_order(t_cmd *cmd_stc, char **stack, int range);
int		exec_1cmd(int *cmd, char **stc, char *n, int (*func)(char **, char *));
int		exec_2cmd(int *cmd, char **a, char **b, int (*func)(char **, char **));
void	ft_push_a_to_b(char **stack_a, char **stack_b, t_cmd *cmd_stc);
void	ft_push_b_to_a(char **stack_a, char **stack_b, t_cmd *cmd_stc);

void	ft_find_best_position2(t_cmd *cmd_stc, char **a, char **b, char c);
#endif

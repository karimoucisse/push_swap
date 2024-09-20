/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:46:08 by kcisse            #+#    #+#             */
/*   Updated: 2024/09/20 19:10:20 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	char	**stack;
	int		rev;
}t_stack;

typedef struct s_cmd
{
	int	a_pst;
	int	b_pst;
	int	top_a_pst;
	int	top_b_pst;
	int	sb;
	int	sa;
	int	ss;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total_count;
	int	cmd_count;
}t_cmd;

// MAIN
int		ft_sort_stack(t_stack *a, t_stack *b);
int		ft_exec_cmd(t_cmd *cmd_stc, char **stack_a, char **stack_b);
int		ft_sort_tester(char **stack);
void	get_ascending_order_stack(t_cmd *cmd_stc, char **stack);
void	get_descending_order_stack(t_cmd *cmd_stc, char **stack);

// ARGS CHECKER
int		ft_check_espace(char *av, int ac);
int		ft_check_val(char *av, int ac);
int		ft_check_sign(char *av);
int		ft_check_char(char **av, int ac);

// HANDLE STRUCT
int		init_stack_struct(int ac, char **av, t_stack *a, t_stack *b);
int		ft_fill_stack_a(int ac, char **av, t_stack *a);
int		init_cmd_struct(t_cmd **cmd);
void	reset_cmd_struct(t_cmd **cmd);

// HANDLE ERROR
int		ft_print_error(void);

// UTILS
char	**char_tab(int ac, char **av);
int		ft_stack_len(char **stack);
int		ft_find_position(int num, char **stack);
void	ft_find_best_position(t_cmd *cmd_stc, char **a, char **b, char c);

// SWAP CMD
int		ft_swap_position(char **stack, char *cmd);
int		ft_rotate_array(char **stack, char *cmd);
int		ft_revs_rotate_array(char **stack, char *cmd);
int		ft_push_elem(char **stack_a, char **stack_b, char *cmd);
int		ft_revs_rotate_arrays(char **stack_a, char **stack_b);
int		ft_rotate_arrays(char **stack_a, char **stack_b);

// FT_SORT
int		ft_find_range1(int num, char **stack_b);
int		ft_find_range2(int num, char **stack_b);
void	cmd_calc(int pst, char **stack, char l, t_cmd *cmd_stc);
int		cmd_calc2(t_cmd *cmd_stc);
void	ft_find_min_and_max(char **stack_b, int *min, int *max);

#endif

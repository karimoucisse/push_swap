#ifndef PUSH_SWAP
#define PUSH_SWAP

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// SWAP COMMANDE
// Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
#define SWAP_B SB
#define SWAP_A SA
// sa + sb.
#define SWAP_A_AND_SWAP_B SS

// Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
#define PUSH_A PA
#define PUSH_B PB

// Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
#define ROTATE_A RA
#define ROTATE_B RB
// RA + RB.
#define ROTATE_A_AND_ROTATE_B RR

// Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
#define REV_ROTATE_A RRA
#define REV_ROTATE_B RRB
// RRA + RRB.
#define REV_ROTATE_A_AND_B RRB

typedef struct s_stack
{
	char **stack;
	int rev;
} t_stack;

typedef struct s_cmd
{
	int a_pst;
	int b_pst;
	int top_a_pst;
	int top_b_pst;
	int sb;
	int sa;
	int ss;
	int ra;
	int rb;
	int rr;
	int rra;
	int rrb;
	int rrr;
	int total_count;
	int cmd_count;
} t_cmd;

// MAIN
int ft_sort_stack(t_stack *a, t_stack *b);
int ft_exec_cmd(t_cmd *cmd_stc, char **stack_a, char **stack_b);
int ft_sort_tester(char **stack);
void get_ascending_order_stack(t_cmd *cmd_stc, char **stack);
void get_descending_order_stack(t_cmd *cmd_stc, char **stack);

// ARGS CHECKER
int ft_check_espace(char *av, int ac);
int ft_check_args(char **av, int ac, int *stack);
int ft_check_val(char *av, int ac);
int ft_check_sign(char *av);
int ft_check_char(char **av, int ac);

// HANDLE STRUCT
int init_stack_struct(int ac, char **av, t_stack *a, t_stack *b);
int ft_fill_stack_a(int ac, char **av, t_stack *a);
int init_cmd_struct(t_cmd **cmd);
void reset_cmd_struct(t_cmd **cmd);

// HANDLE ERROR
int ft_print_error(void);

// UTILS
char **char_tab(int ac, char **av);
int ft_stack_len(char **stack);
int ft_find_position(int num, char **stack);
void ft_find_best_position(t_cmd *cmd_stc, char **stack_a, char **stack_b, char c);

// SWAP CMD
int ft_swap_position(char **stack);
int ft_rotate_array(char **stack);
int ft_revs_rotate_array(char **stack);
int ft_push_elem(char **stack_a, char **stack_b);

// FT_SORT
int ft_find_range1(int num, char **stack_b);
int ft_find_range2(int num, char **stack_b);
void cmd_calc(int pst, char **stack, char l, t_cmd *cmd_stc);
int cmd_calc2(t_cmd *cmd_stc);
void ft_find_min_and_max(char **stack_b, int *min, int *max);

#endif

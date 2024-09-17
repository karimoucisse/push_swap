#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

// SWAP COMMANDE
// Intervertit les 2 premiers éléments au sommet de la pile a.
// Ne fait rien s’il n’y en a qu’un ou aucun.
# define SWAP_B SB
# define SWAP_A SA
// sa + sb.
# define SWAP_A_AND_SWAP_B SS

// Prend le premier élément au sommet de b et le met sur a.
// Ne fait rien si b est vide.
# define PUSH_A PA
# define PUSH_B PB

// Décale d’une position vers le haut tous les élements de la pile a.
// Le premier élément devient le dernier.
# define ROTATE_A RA
# define ROTATE_B RB
// RA + RB.
# define ROTATE_A_AND_ROTATE_B RR

// Décale d’une position vers le bas tous les élements de
// la pile a. Le dernier élément devient le premier.
# define REV_ROTATE_A RRA
# define REV_ROTATE_B RRB
// RRA + RRB.
# define REV_ROTATE_A_AND_B RRB

typedef struct s_stack
{
	int	*stack;
	int rev;
} t_stack;


// MAIN

// ARGS CHECKER
int ft_check_espace(char *av, int ac);
int ft_check_args(char **av, int ac, int *stack);
int ft_check_val(char *av, int ac);
int ft_check_sign(char *av);
int ft_check_char(char **av, int ac);

// HANDLE STRUCT
int init_struct(int ac, char **av, t_stack **a, t_stack **b);
int ft_fill_stack_a(int ac, char **av, t_stack **a);

// HANDLE ERROR
int ft_print_error(void);

// UTILS
char **char_tab(int ac, char **av, t_stack **a);

// SWAP CMD
int	ft_swap_position(int *stack);
#endif

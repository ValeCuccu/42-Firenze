/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:16:37 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

/* Nodo della lista stack */
typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}	t_node;

/* ----------- STACK UTILS (stack.c) ----------- */
t_node	*create_node(int value);
void	append_node(t_node **stack, t_node *new_node);
void	print_stack(t_node *stack);
void	free_stack(t_node **stack);
int		stack_size(t_node *stack);

/* ----------- VALIDATION (validation.c) ----------- */
int		is_number(char *str);
long	ft_atol(const char *str);
int		is_in_int_range(char *str);
int		has_duplicates(int *arr, int size);
void	print_error_and_exit(t_node **a, t_node **b, int *temp);

/* ----------- BUILD (build_stack.c) ----------- */
t_node	*build_stack(int argc, char **argv);

/* ----------- CHECK (check_sorted.c) ----------- */
int		is_sorted(t_node *stack);

/* ----------- SORTING UTILS (sort_utils.c) ----------- */
int		find_min(t_node *stack);
void	move_min_to_top(t_node **a);

/* ----------- SORTING FUNCTIONS SMALL (sort3.c, sort5.c) ----------- */
void	sort_3(t_node **a);
void	sort_5(t_node **a, t_node **b);

/* ----------- RADIX SORT (sort_large.c) ----------- */
void	index_stack(t_node **a);
void	radix_sort(t_node **a, t_node **b, int size);

/* Comandi con stampa */
void	sa(t_node **a);
void	sb(t_node **b);
void	ss(t_node **a, t_node **b);
void	pa(t_node **a, t_node **b);
void	pb(t_node **a, t_node **b);
void	ra(t_node **a);
void	rb(t_node **b);
void	rr(t_node **a, t_node **b);
void	rra(t_node **a);
void	rrb(t_node **b);
void	rrr(t_node **a, t_node **b);

/* Versioni silenti (senza stampa), usate nei comandi composti */
void	sa_silent(t_node **a);
void	sb_silent(t_node **b);
void	pa_silent(t_node **a, t_node **b);
void	pb_silent(t_node **a, t_node **b);
void	ra_silent(t_node **a);
void	rb_silent(t_node **b);
void	rra_silent(t_node **a);
void	rrb_silent(t_node **b);

#endif

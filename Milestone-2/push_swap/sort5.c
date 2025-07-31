/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:16:24 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <limits.h>

/*
** find_min_pos:
** Trova la posizione del valore minimo nello stack.
*/
static int	find_min_pos(t_node *stack, int min)
{
	int	pos;

	pos = 0;
	while (stack && stack->value != min)
	{
		pos++;
		stack = stack->next;
	}
	return (pos);
}

/*
** move_min_to_top:
** Porta il valore minimo in cima allo stack a usando ra o rra.
*/
void	move_min_to_top(t_node **a)
{
	int		min;
	int		pos;
	int		size;

	if (!a || !*a)
		return ;
	min = find_min(*a);
	pos = find_min_pos(*a, min);
	size = stack_size(*a);
	if (pos <= size / 2)
	{
		while ((*a)->value != min)
			ra(a);
	}
	else
	{
		while ((*a)->value != min)
			rra(a);
	}
}

/*
** push_two_min:
** Sposta i due elementi più piccoli da a a b.
*/
static void	push_two_min(t_node **a, t_node **b)
{
	int	count;

	count = 0;
	while (count < 2)
	{
		move_min_to_top(a);
		pb(a, b);
		count++;
	}
}

/*
** push_back_b:
** Riporta tutti gli elementi da b ad a.
*/
static void	push_back_b(t_node **a, t_node **b)
{
	while (stack_size(*b) > 0)
		pa(a, b);
}

/*
** sort_5:
** Ordina uno stack di 5 elementi spostando i due minimi in b,
** ordina i 3 rimanenti e reintegra gli elementi da b.
*/
void	sort_5(t_node **a, t_node **b)
{
	push_two_min(a, b);
	sort_3(a);
	push_back_b(a, b);
}

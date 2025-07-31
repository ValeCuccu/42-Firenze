/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:16:02 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/*
** rrb: Ruota lo stack b verso il basso (l'ultimo diventa il primo)
*/
void	rrb(t_node **b)
{
	t_node	*prev;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	prev = NULL;
	last = *b;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *b;
	*b = last;
	write(1, "rrb\n", 4);
}

/*
** rr: Ruota entrambi gli stack a e b verso l’alto (usa ra_silent e rb_silent)
*/
void	rr(t_node **a, t_node **b)
{
	ra_silent(a);
	rb_silent(b);
	write(1, "rr\n", 3);
}

/*
** rrr: Ruota entrambi gli stack a e b verso il basso
*/
void	rrr(t_node **a, t_node **b)
{
	rra_silent(a);
	rrb_silent(b);
	write(1, "rrr\n", 4);
}

/*
** sa: Scambia i primi due elementi dello stack a
*/
void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*a = second;
	write(1, "sa\n", 3);
}

/*
** sb: Scambia i primi due elementi dello stack b
*/
void	sb(t_node **b)
{
	t_node	*first;
	t_node	*second;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*b = second;
	write(1, "sb\n", 3);
}

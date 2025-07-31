/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:15:48 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <unistd.h>

// Sposta il primo elemento dello stack a in cima allo stack b
void	pb(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	write(1, "pb\n", 3);
}

// Sposta il primo elemento dello stack b in cima allo stack a
void	pa(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	write(1, "pa\n", 3);
}

// Ruota lo stack a verso l'alto
void	ra(t_node **a)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "ra\n", 3);
}

// Ruota lo stack a verso il basso
void	rra(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	write(1, "rra\n", 4);
}

// Ruota lo stack b verso l'alto
void	rb(t_node **b)
{
	t_node	*first;
	t_node	*last;

	if (!b || !*b || !(*b)->next)
		return ;
	first = *b;
	*b = (*b)->next;
	first->next = NULL;
	last = *b;
	while (last->next)
		last = last->next;
	last->next = first;
	write(1, "rb\n", 3);
}

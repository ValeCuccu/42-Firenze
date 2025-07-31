/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:15:57 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

void	ss(t_node **a, t_node **b)
{
	sa_silent(a);
	sb_silent(b);
	write(1, "ss\n", 3);
}

void	pb_silent(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!a || !*a)
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
}

void	pa_silent(t_node **a, t_node **b)
{
	t_node	*temp;

	if (!b || !*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
}

void	ra_silent(t_node **a)
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
}

void	rra_silent(t_node **a)
{
	t_node	*prev;
	t_node	*last;

	prev = NULL;
	if (!a || !*a || !(*a)->next)
		return ;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
}

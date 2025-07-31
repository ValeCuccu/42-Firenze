/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:16:32 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include <stdlib.h>

int	is_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

static void	bubble_sort(int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
}

static int	*copy_values(t_node *stack, int size)
{
	int	*arr;
	int	i;

	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size && stack)
	{
		arr[i] = stack->value;
		stack = stack->next;
		i++;
	}
	return (arr);
}

static void	assign_indices(t_node *stack, int *arr, int size)
{
	int	i;

	while (stack)
	{
		i = 0;
		while (i < size)
		{
			if (stack->value == arr[i])
			{
				stack->value = i;
				break ;
			}
			i++;
		}
		stack = stack->next;
	}
}

void	index_stack(t_node **stack)
{
	int		size;
	int		*arr;

	if (!stack || !*stack)
		return ;
	size = stack_size(*stack);
	arr = copy_values(*stack, size);
	if (!arr)
		print_error_and_exit(stack, NULL, NULL);
	bubble_sort(arr, size);
	assign_indices(*stack, arr, size);
	free(arr);
}

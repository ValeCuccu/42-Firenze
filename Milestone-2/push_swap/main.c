/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:15:20 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

static int	*parse_args(int argc, char **argv, t_node **stack)
{
	int		*temp;
	int		i;
	long	num;

	temp = malloc(sizeof(int) * (argc - 1));
	if (!temp)
		print_error_and_exit(stack, NULL, NULL);
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]) || !is_in_int_range(argv[i]))
		{
			free(temp);
			print_error_and_exit(stack, NULL, NULL);
		}
		num = ft_atol(argv[i]);
		temp[i - 1] = (int)num;
		i++;
	}
	return (temp);
}

static void	build_list(t_node **stack, int *temp, int size)
{
	t_node	*new;
	int		i;

	i = 0;
	while (i < size)
	{
		new = create_node(temp[i]);
		if (!new)
		{
			free(temp);
			print_error_and_exit(stack, NULL, NULL);
		}
		append_node(stack, new);
		i++;
	}
}

t_node	*build_stack(int argc, char **argv)
{
	t_node	*stack;
	int		*temp;

	stack = NULL;
	temp = parse_args(argc, argv, &stack);
	if (has_duplicates(temp, argc - 1))
	{
		free(temp);
		print_error_and_exit(&stack, NULL, NULL);
	}
	build_list(&stack, temp, argc - 1);
	free(temp);
	return (stack);
}

static void	sort_stack(t_node **stack_a, t_node **stack_b, int size)
{
	if (size == 3)
		sort_3(stack_a);
	else if (size == 5)
		sort_5(stack_a, stack_b);
	else
	{
		index_stack(stack_a);
		radix_sort(stack_a, stack_b, size);
	}
}

int	main(int argc, char **argv)
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size;

	if (argc < 2)
		return (0);
	stack_a = build_stack(argc, argv);
	stack_b = NULL;
	if (is_sorted(stack_a))
	{
		free_stack(&stack_a);
		return (0);
	}
	size = stack_size(stack_a);
	sort_stack(&stack_a, &stack_b, size);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 10:00:00 by anpastac          #+#    #+#             */
/*   Updated: 2025/07/28 22:16:44 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

/**
 * ft_atol:
 * Converte stringa in long (per controllare overflow).
 */
long	ft_atol(const char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (2147483648);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}

/**
 * is_number:
 * Controlla se una stringa è un intero valido (sintatticamente).
 */
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * is_in_int_range:
 * Controlla se il valore è nel range di un int.
 */
int	is_in_int_range(char *str)
{
	long	num;

	num = ft_atol(str);
	if (num < INT_MIN || num > INT_MAX)
		return (0);
	return (1);
}

/**
 * has_duplicates:
 * Controlla se un array di interi ha duplicati.
 */
int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * print_error_and_exit:
 * Stampa "Error" e termina il programma liberando memoria.
 */
void	print_error_and_exit(t_node **a, t_node **b, int *temp)
{
	if (temp)
		free(temp);
	if (a && *a)
		free_stack(a);
	if (b && *b)
		free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

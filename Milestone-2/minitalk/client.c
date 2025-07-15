/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vacuccu <vacuccu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:11:44 by vacuccu           #+#    #+#             */
/*   Updated: 2025/07/14 14:34:11 by vacuccu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int pid, char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(300);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 2)
		return (ft_printf("Missing message!\n"), 1);
	if (argc == 1)
		return (ft_printf("Missing PID and Message!\n"), 1);
	if (argc > 3)
		return (ft_printf("Too many arguments!\n"), 1);
	if (!argv[2] || argv[2][0] == '\0')
		return (ft_printf("Missing message!\n"), 1);
	if (ft_atoi(argv[1]) <= 0)
		return (ft_printf("Pid wrong!\n"), 1);
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		send_signal(pid, argv[2][i]);
		i++;
	}
	ft_printf("Message sent!\n");
	return (1);
}

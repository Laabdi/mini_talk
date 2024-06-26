/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:22 by moaregra          #+#    #+#             */
/*   Updated: 2024/04/07 20:50:17 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	send_string(pid_t pid, char *str)
{
	int				bits;
	unsigned char	c;

	while (*str)
	{
		bits = 7;
		c = *str++;
		while (bits >= 0)
		{
			if (c >> bits & 1)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(300);
			bits--;
		}
	}
	bits = 7;
	while (bits >= 0)
	{
		kill(pid, SIGUSR1);
		usleep(300);
		bits--;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 3 || !ft_strlen(argv[2]))
		return (1);
	if ((kill(ft_atoi(argv[1]), 0) != 0) || (ft_atoi(argv[1]) <= 0))
		return (ft_putstr_fd("PID NOT VALID", 1), 0);
	send_string(ft_atoi(argv[1]), argv[2]);
	return (0);
}

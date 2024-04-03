/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:39:22 by moaregra          #+#    #+#             */
/*   Updated: 2024/04/03 13:39:24 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	res;

	i = 0;
	s = 1;
	res = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57 && str[i])
	{
		res = (str[i] - 48) + (res * 10);
		i++;
	}
	return (res * s);
}

void	send_string(char *str, pid_t pid)
{
	int				bits;
	unsigned char	c;

	while (*str)
	{
		bits = 7;
		c = *str++;
		while (bits >= 0)
		{
			if ((c >> bits) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			bits--;
		}
	}
}

int	main(int ac, char *av[])
{
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		if (pid <= 0)
		{
			printf("invalid PID");
			return (1);
		}
		else
			send_string(av[2], pid);
		printf("string was sent");
		return (0);
	}
	printf("Invalid input");
	return (0);
}

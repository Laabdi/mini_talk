/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:44:11 by moaregra          #+#    #+#             */
/*   Updated: 2024/04/07 20:52:54 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	handle_signal(int sig)
{
	static int				i;
	static unsigned char	j;

	j |= (sig == SIGUSR2);
	if (++i == 8)
	{
		ft_putchar_fd(j, 1);
		i = 0;
		j = 0;
	}
	else
		j <<= 1;
}

int	main(void)
{
	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}

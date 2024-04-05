/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:44:11 by moaregra          #+#    #+#             */
/*   Updated: 2024/04/03 14:08:49 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signalmsg)
{
	static int	bit_counter;
	static char	character;

	if (SIGUSR1 == signalmsg)
	{
		bit_counter++;
		character <<= 1;
		character |= 1;
	}
	else if (SIGUSR2 == signalmsg)
	{
		bit_counter++;
		character <<= 1;
	}
	if (bit_counter == 8)
	{
		ft_printf("%c", character);
		bit_counter = 0;
		character = 0;
	}
}


int	main(void)
{
	int	nb;

	nb = getpid();
	ft_printf("server PID ----->%u\n", nb);
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	ft_printf("signal sent by the client ----->");
	while (1)
		pause();
}

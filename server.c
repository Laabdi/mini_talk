/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 13:44:11 by moaregra          #+#    #+#             */
/*   Updated: 2024/04/03 13:44:12 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	bit_writer(int bit_recieved)
{
	static int	bit;
	static int	set;

	bit = 7;
	set = 0;
	set += (bit_recieved << bit);
	if (bit == 0)
	{
		printf("%c", set);
		bit = 7;
		set = 0;
	}
	else
		bit--;
}

void	bit_handler(int bit_recieved)
{
	if (bit_recieved == SIGUSR1)
		bit_writer(1);
	else
		bit_writer(0);
}

int	main(void)
{
	int	nb;

	nb = getpid();
	printf("server PID ----->%u\n", nb);
	signal(SIGUSR1, bit_handler);
	signal(SIGUSR2, bit_handler);
	printf("signal sent by the client ----->");
	while (1)
		pause();
}

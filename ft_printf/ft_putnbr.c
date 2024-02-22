/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:42:58 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 20:22:53 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int			count;
	long int	n;

	count = 0;
	n = (long int)nb;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n > 9)
		count += ft_putnbr(n / 10);
	count += ft_putchar((n % 10) + '0');
	return (count);
}

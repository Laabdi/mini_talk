/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_addresse.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:32:03 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 20:21:48 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_lowh(unsigned long nb)
{
	int		count;
	char	*s;

	s = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += ft_print_lowh(nb / 16);
		count += ft_putchar(s[nb % 16]);
	}
	if (nb < 16)
		count += ft_putchar(s[nb]);
	return (count);
}

int	ft_print_addresse(void *ptr)
{
	unsigned long	num;
	int				count;

	count = 0;
	num = (unsigned long)ptr;
	count += write(1, "0x", 2);
	count += ft_print_lowh(num);
	return (count);
}

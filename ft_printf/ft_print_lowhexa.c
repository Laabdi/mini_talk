/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lowhexa.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:27:25 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 20:21:59 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_lowhexa(unsigned int nb)
{
	int		count;
	char	*s;

	s = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += ft_print_lowhexa(nb / 16);
		count += ft_putchar(s[nb % 16]);
	}
	if (nb < 16)
		count += ft_putchar(s[nb]);
	return (count);
}

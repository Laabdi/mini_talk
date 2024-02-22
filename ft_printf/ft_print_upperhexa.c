/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_upperhexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:23:49 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 20:23:03 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_upperhexa(unsigned int nb)
{
	int		count;
	char	*s;

	s = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
	{
		count += ft_print_upperhexa(nb / 16);
		count += ft_putchar(s[nb % 16]);
	}
	if (nb < 16)
		count += ft_putchar(s[nb]);
	return (count);
}

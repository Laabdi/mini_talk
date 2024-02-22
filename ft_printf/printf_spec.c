/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_spec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:49:13 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 21:45:56 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printf_spec(va_list arg, char c)
{
	int	count;

	count = 0;
	if (c == '%')
		count += ft_putchar('%');
	else if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'x')
		count += ft_print_lowhexa(va_arg(arg, unsigned int));
	else if (c == 'X')
		count += ft_print_upperhexa(va_arg(arg, unsigned int));
	else if (c == 'p')
		count += ft_print_addresse(va_arg(arg, void *));
	else if (c == 'd')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		count += ft_uputnbr(va_arg(arg, unsigned int));
	else
		count = -1;
	return (count);
}

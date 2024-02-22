/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:38:31 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 21:45:36 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	arg;

	i = -1;
	count = 0;
	if (!format)
		return (-1);
	va_start(arg, format);
	while (format[++i])
	{
		if (format[i] == '%' && format[i + 1] == '\0')
			return (-1);
		else if (format[i] == '%' && ft_strchr("csxXpdui%", format[i + 1]))
		{
			count += printf_spec(arg, format[i + 1]);
			i++;
		}
		else if (format[i] == '%' && !ft_strchr("csxXpdui%", format[i + 1]))
			i++;
		else
			count += ft_putchar(format[i]);
	}
	va_end (arg);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:45:54 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/04 20:22:41 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputnbr(unsigned int nb)
{
	int	count;

	count = 0;
	if (nb > 9)
		count += ft_uputnbr(nb / 10);
	count += ft_putchar((nb % 10) + '0');
	return (count);
}

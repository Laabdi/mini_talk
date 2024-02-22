/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moaregra <moaregra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:48:11 by moaregra          #+#    #+#             */
/*   Updated: 2024/02/08 20:57:29 by moaregra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

int		ft_print_addresse(void *ptr);
int		ft_putchar(char c);
int		ft_print_lowhexa(unsigned int nb);
int		ft_print_upperhexa(unsigned int nb);
int		ft_printf(const char *format, ...);
int		ft_putnbr(int nb);
int		ft_putstr(char *s);
int		ft_uputnbr(unsigned int nb);
int		printf_spec(va_list arg, char c);
char	*ft_strchr(const char *s, int c);

#endif

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

int		ft_atoi(char *str);
void	bit_write(int x);
void	bit_handler(int x);
void	ft_send_stringl(int pid, char *str);

#endif
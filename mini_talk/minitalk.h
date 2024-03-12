#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <signal.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>

typedef struct s_global_state
{
	char	data_byte;
	int		bits_count;
}			t_global_state;

void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
int		is_numeric(const char *str);
int		ft_atoi(const char *str);

#endif // MINITALK_H
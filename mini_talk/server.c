#include "minitalk.h"

void    handler_signal(int signal)
{
    static unsigned char    current_ch;
    static int              index_bit;

    current_ch |= (signal == SIGUSR1);
    index_bit++;
    if (index_bit == 8)
    {
        ft_putchar_fd(current_ch, 1);
        index_bit = 0;
        current_ch = 0;
    }
    else
        current_ch <<= 1;
}
int	main(int argc, char **argv)
{
    (void)argv;
	ft_putstr_fd("The server PID is : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	signal(SIGUSR1, handler_signal);
	signal(SIGUSR2, handler_signal);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
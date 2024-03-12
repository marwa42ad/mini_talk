#include "minitalk.h"

void    handler_signal(int signal, siginfo_t *info, void *context)
{
    static unsigned char    current_ch;
    static int              index_bit;

    (void)context;
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
    if (signal == SIGUSR1)
    {
        kill(info->si_pid, SIGUSR1);
        if (kill(info->si_pid, SIGUSR1) == -1)
            ft_putstr_fd("Faild to send SIGUSR1\n", 2);
        return ;
    }
    else if (signal == SIGUSR2)
    {
        kill(info->si_pid, SIGUSR2);
        if (kill(info->si_pid, SIGUSR2) == -1)
            ft_putstr_fd("Faild to send SIGUSR2\n", 2);
        return ;
    }
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	ft_putstr_fd("The server PID is : ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler_signal;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (argc == 1)
	{
		pause();
	}
	return (0);
}
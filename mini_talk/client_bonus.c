#include "minitalk.h"

void	read_signal_handler(int signal,  siginfo_t *info, void *context)
{
	static int  msg_print;
    (void)info;
	(void)context;

    msg_print = 0;
    if (!msg_print)
    {
        if (signal == SIGUSR1)
        {
            ft_putstr_fd("Message has received sccessfully\n", 1);
            msg_print = 1;
        }
    }
	else
		ft_putstr_fd("Error Message\n", 1);
}

void	send_char_signal(int server_pid, unsigned char ch)
{
	int	            i;
	unsigned char	tmp;

	i = 8;
    tmp = ch;
	while (i > 0)
	{
		i--;
        tmp = ch >> i;
		if (tmp % 2 == 0)
		{
			kill(server_pid, SIGUSR2);
		}
		else
		{
			kill(server_pid, SIGUSR1);
		}
		usleep(200);
	}
}
void	send_signal_to_server(int argc, char **argv, int server_pid)
{
	int		index_arg;
	char	*cur_arg;

	index_arg = 2;
	while (index_arg < argc)
	{
		cur_arg = argv[index_arg];
		while (*cur_arg)
		{
			send_char_signal(server_pid, *cur_arg);
			cur_arg++;
		}
		send_char_signal(server_pid, ' ');
		index_arg++;
	}
	send_char_signal(server_pid, '\n');
	send_char_signal(server_pid, '\0');
}

int	main(int argc, char **argv)
{
    struct sigaction	sa;
    int       server_pid;
    int         i;

    i = 0;
    while (argv[1][i])
    {
        if (!is_numeric(&argv[1][i]))
        {
            ft_putstr_fd("Invalid server PID\n", 2);
            exit(1);
        }
        i++;
    }
    if (argc < 3 )
	{
		ft_putstr_fd("ERROR\n", 2);
		exit(1);
	}
    else
    {
       sa.sa_sigaction = read_signal_handler;
       sigaction(SIGUSR1, &sa, NULL);
       sigaction(SIGUSR2, &sa, NULL);
       server_pid = ft_atoi(argv[1]);
       if (server_pid == 0)
       {
            ft_putstr_fd("Invalid server PID\n", 2);
            exit(1);
        }
        send_signal_to_server(argc, argv, server_pid);
    }
    return (0);
}

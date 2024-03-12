#include "minitalk.h"

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
		usleep(300);
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
	pid_t       server_pid;

	if (argc < 3)
	{
		ft_putstr_fd("INVALID NUMBER OF ARGUMENTS\n", 2);
		exit(1);
	}
	if (!is_numeric(argv[1]))
	{
		ft_putstr_fd("Invalid server PID\n", 2);
		exit(1);
	}
	server_pid = ft_atoi(argv[1]);
	if (server_pid == 0)
	{
		ft_putstr_fd("Invalid server PID conver\n", 2);
		exit(1);
	}
	send_signal_to_server(argc, argv, server_pid);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:28:59 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/08 10:46:28 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

volatile sig_atomic_t	g_sender_status = BUSY;

static void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		g_sender_status = READY;
	if (sig == SIGUSR2)
	{
		write(STDOUT_FILENO, "Message received!\n", 18);
		g_sender_status = READY;
		exit (0);
	}
	usleep(20);
}

/*Converts a char to binary and sends its value bit by bit to the pid process*/
static void	send_char(int pid, int c)
{
	char	*bits;
	int		i;

	i = 0;
	bits = ft_itobin(c);
	while (i < 8)
	{
		if (bits[i] == '0')
			kill(pid, SIGUSR2);
		else if (bits[i] == '1')
			kill(pid, SIGUSR1);
		while (g_sender_status == BUSY)
			;//usleep(20);
		i++;
		g_sender_status = BUSY;
	}
	free(bits);
}

/*Takes a pid to the server process and calls send_char sending char by char*/
static void	send_message(int pid, char *str)
{
	while (*str != '\0')
	{
		send_char(pid, (unsigned char)*str);
		str++;
	}
	send_char(pid, 0);
}

int	main(int args, char **argv)
{
	char				*arg_check;

	if (args != 3)
	{
		ft_printf("Wrong number of arguments.\nUse: ./client <PID> <message>");
		return (1);
	}
	arg_check = argv[1];
	while (*arg_check)
	{
		if (!ft_isdigit(*arg_check))
		{
			ft_printf("PID should be an integer number.");
			return (1);
		}
		arg_check++;
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	send_message(ft_atoi(argv[1]), argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgamiz-g <hgamiz-g@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 10:29:07 by hgamiz-g          #+#    #+#             */
/*   Updated: 2025/11/08 10:46:57 by hgamiz-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static volatile int	g_sender_pid = -1;

/*Manages the signals sent by the client and when a full char is received
  it's displayed on STDOUT*/
static void	sig_handler(int signum)
{
	static int				i;
	static char				bits[8];
	unsigned char			c;

	if (signum == SIGUSR1)
		bits[i] = '1';
	else if (signum == SIGUSR2)
		bits[i] = '0';
	i++;
	if (i == 8)
	{
		c = (unsigned char)ft_bintoi(bits);
		if (c == 0)
		{
			kill(g_sender_pid, SIGUSR2);
			write(STDOUT_FILENO, "\n", 1);
		}
		else
			write(STDOUT_FILENO, &c, 1);
		i = 0;
	}
	kill(g_sender_pid, SIGUSR1);
}

static void	get_pid(int sig, siginfo_t *info, void *context)
{
	(void)context;
	g_sender_pid = info->si_pid;
	sig_handler(sig);
	return ;
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = get_pid;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Server PID: %d\n", pid);
	while (1)
		pause();
	return (0);
}

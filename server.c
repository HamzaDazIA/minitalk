/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:31 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/07 04:03:42 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	handle_signal(int sig, siginfo_t *info, void *ucontext)
{
	static int				client_pid = 0;
	static unsigned char	c = 0;
	static int				bit = 0;

	(void)ucontext;
	if (client_pid == 0 || info->si_pid != client_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		bit = 0;
	}
	if (sig == SIGUSR1)
		c |= (1 << bit);
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 handler\n");
		return (1);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR2 handler\n");
		return (1);
	}
	while (1)
		pause();
	return (0);
}

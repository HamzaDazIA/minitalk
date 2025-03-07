/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:31 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/06 23:50:16 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void handel_signal(int sig, siginfo_t *info, void *ucontext)
{
    (void)ucontext;
    static int pid;
    static unsigned char c;
    int i;
    static int bit;

    bit = 0;
    i = 0;
    
    pid = 0;
    if (pid == 0 || info->si_pid != pid)
    {
        pid = info->si_pid;
        c = 0;
    }
    if(sig == SIGUSR1)
        c |= (1 << bit);
    bit++;
    if(bit == 8)
    {
        write(1, &c, 1);
        c = 0;
        bit = 0;
    }
}

int main()
{
   struct sigaction sg;
    
    ft_printf("the SERVER PID is : %d", getpid());
    
    sg.sa_sigaction = &handel_signal;
    sg.sa_flags = SA_SIGINFO;
    
    sigaction(SIGUSR1, &sg, NULL);
    sigaction(SIGUSR2, &sg, NULL);
    while(1)
        pause();
    
}

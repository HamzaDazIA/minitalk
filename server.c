/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:31 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/06 15:24:18 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void handel_signal(int, siginfo_t *info, void *uap)
{
    (void)uap;
    static int pid;
    static unsigned char c;
    int i;
    int bit;

    bit = 0;
    i = 0;
    
    pid = 0;
    if (pid == 0 || info->si_pid != pid)
    {
        pid = info->si_pid;
        c = 0;
    }
    while(i < 8)
    
}

int main(int argc , char **argv)
{
   struct sigaction sg;
    
    printf("the SERVER PID is : %d", getpid());
    
    sg.sa_sigaction = handel_signal;
    sa.sa_flags = SA_SIGINFO;
    
    sigaction(SIGUSR1, handel_signal, NULL);
    sigaction(SIGUSR2, handel_signal, NULL);
    
}

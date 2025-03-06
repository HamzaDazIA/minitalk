/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdazia <hdazia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:34:37 by hdazia            #+#    #+#             */
/*   Updated: 2025/03/06 23:14:58 by hdazia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"


int ft_atoi(char *str)
{
    int i;
    unsigned long  rs;

    rs = 0;
    i = 0;
    while(str[i] >= 9 && str[i] <= 13)
        i++;
    if (str[i] == '+' || str[i] == '-')
        return (-1);
    if (str[i] == '0')
        return (-1);
    while(str[i] >= '0' && str[i] <= '9')
    {
        rs = rs * 10 + str[i] - '0';
        if (rs > INT_MAX)
            return (-1);
        i++;
    }
    return (rs);
}
void send_signsl(char c, int pid)
{
    int i;

    i = 0;
    
    while (i < 8)
    {
        if (c & (1 << i))
        {
            if (kill(pid, SIGUSR1) < 0)
            {
                printf("Error: signal not sent\n");
                exit(1);
            }
        }
        else if (kill(pid, SIGUSR2) < 0)
        {
            printf("Error: signal not sent\n");
            exit(1);
        }
        usleep(200);
        usleep(200);
        i++;
    }
}
int main(int argc, char **argv)
{
    int pid;
    int i;
    
    if (argc != 3)
    {
        printf("Error: invalide number of arguments\n");
        printf("Usage: ./client [PID] [string] [signal]\n");
        return (1);
    }
    pid = ft_atoi(argv[1]);
    i = 0;
    if (pid == -1)
    {
        printf("Error: invalide PID\n");
        return (1);
    }
    while (argv[2][i] != '\0')
    {
        send_signsl(argv[2][i], pid);
        i++;
    }
    send_signsl('\0', pid);
    return (0);    
}

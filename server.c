/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:51:34 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/05 01:51:36 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void get_byte(int signal)
{
    static char rec_byte = 0;
    static int counter = 0;
    
 
    if (signal == SIGUSR2)
    {
        rec_byte |= 1;
    }
    
    if (counter == 7)
    {
        write(1, &rec_byte, 1);
        counter = 0;
        rec_byte = 0;
    }
    else
    {
        rec_byte = rec_byte << 1;
        counter++;
    }
}   
void ft_putnbr(int n) 
{
    char digit;
    
    if (n < 0) {
        write(1, "-", 1);
        n = -n;
    }
    if (n >= 10)
        ft_putnbr(n / 10);
    digit = '0' + (n % 10);
    write(1, &digit, 1);
}

int main(void)
{
	write(1, "Welcome to Minitalk!\n", 21);
	write(1, "Server PID:", 12);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	
	while (4)
	{
		signal(SIGUSR2, get_byte);
		signal(SIGUSR1, get_byte);
		pause();
	}
	return (0);
}

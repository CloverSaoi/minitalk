/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:51:05 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/05 01:51:10 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void send_byte(int pid, char c)
{
    int counter;

	counter = 0;
	while (counter < 8)
	{
		if ((c & 256) == 256)
			kill(pid, SIGUSR2);
		else 
			kill(pid, SIGUSR1);
		c = c << 1;
		usleep(314);
		counter++;
	}
	c++;
}

int main (int argc, char **argv)
{
	char	*str;
	int		pid;
	
	if (argc == 3)
	{
		pid = atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			send_byte(pid, *str);
			str++;

		}
	}
	else 
		return (write(1,"Invalid Entry! Please try again :)", 34));
}
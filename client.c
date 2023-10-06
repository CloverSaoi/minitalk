/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:51:05 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/06 10:42:38 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <stdio.h>

void	send_byte(int pid, char c)
{
	int	counter;

	counter = 0;
	while (counter < 8)
	{
		if ((c & 256) == 256)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		c = c << 1;
		usleep(100);
		counter++;
	}
	c++;
}

int	ft_atoi(const char *str)
{
	int	index;
	int	negative;
	int	return_val;

	index = 0;
	negative = 1;
	return_val = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			negative *= -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		return_val = (str[index] - '0') + (return_val * 10);
		index++;
	}
	return (return_val * negative);
}

int	main(int argc, char **argv)
{
	char	*str;
	int		pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		while (*str)
		{
			send_byte(pid, *str);
			str++;
		}
	}
	else
		return (write(1, "Invalid Entry! Please try again :)", 34));
	return (0);
}

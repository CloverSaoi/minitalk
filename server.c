/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddutta <ddutta@student.42adel.org.au>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 01:51:34 by ddutta            #+#    #+#             */
/*   Updated: 2023/10/06 19:55:49 by ddutta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	header_minitalk(void)
{
	write(1, "\t\t M)mm mmm  I)iii  N)n    n I)iii ", 35);
	write(1, " T)ttttt  A)aa   L)       K)   kk\n", 34);
	write(1, "\t\tM)  mm  mm   I)   N)nn  nn   I)  ", 35);
	write(1, "    T)   A)  aa  L)       K)  kk\n", 33);
	write(1, "\t\tM)  mm  mm   I)   N) nn nn   I)  ", 35);
	write(1, "    T)  A)    a  L)       K)kkk\n", 32);
	write(1, "\t\tM)  mm  mm   I)   N)  nnnn   I)  ", 35);
	write(1, "    T)  A)aaaaa  L)       K)  kk\n", 33);
	write(1, "\t\tM)      mm   I)   N)   nnn   I)  ", 35);
	write(1, "    T)  A)    a  L)       K)   kk\n", 34);
	write(1, "\t\tM)       m I)iii  N)     n I)iiii", 35);
	write(1, "    T)  A)    a  L)lllll  K)    kk\n", 35);
	write(1, "\n", 1);
	write(1, "\t\t\t\t    -- .. -. .. - .- .-.. -.-\n", 33);
	usleep(1000);
}

void	loadingbar(void)
{
	int	i;

	i = 0;
	write(1, "\n\n\t\t\t    Server is now loading: ", 33);
	while (i < 21)
	{
		write(1, "/", 1);
		usleep(99999);
		i++;
	}
}

void	get_byte(int signal)
{
	static char	rec_byte = 0;
	static int	counter = 0;

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

void	ft_putnbr(int n)
{
	char	digit;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	digit = '0' + (n % 10);
	write(1, &digit, 1);
}

int	main(void)
{
	header_minitalk();
	loadingbar();
	write(1, "\n\n\n\t\t\t\t    Welcome to Minitalk :)\n", 34);
	write(1, "\t\t\t\t      Server PID: ", 22);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	write(1, "\t\t\t\t      intra id: ddutta\n", 27);
	while (4)
	{
		signal(SIGUSR2, get_byte);
		signal(SIGUSR1, get_byte);
		pause();
	}
	return (0);
}

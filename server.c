/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:28:43 by eerika            #+#    #+#             */
/*   Updated: 2021/06/14 19:28:44 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

t_structure	g_out;

void	print_out_char(void)
{
	write(STDOUT_FILENO, &g_out.out_char, 1);
	g_out.count = 128;
	g_out.out_char = 0;
}

void	get_one(int signal)
{
	g_out.out_char += g_out.count;
	g_out.count /= 2;
	if (g_out.count == 0)
		print_out_char();
	(void)signal;
}

void	get_zero(int signal)
{
	g_out.count /= 2;
	if (g_out.count == 0)
		print_out_char();
	(void)signal;
}

int	main(void)
{
	struct sigaction	one;
	struct sigaction	zero;

	one.sa_handler = get_one;
	zero.sa_handler = get_zero;
	g_out.out_char = 0;
	g_out.count = 128;
	ft_putstr("Server pid: ");
	ft_putnbr(getpid());
	ft_putchar('\n');
	ft_putstr("Run the client as follows: ./client ");
	ft_putnbr(getpid());
	ft_putendl(" <message>");
	while (1)
	{	
		sigaction(SIGUSR1, &one, NULL);
		sigaction(SIGUSR2, &zero, NULL);
		pause();
	}
}

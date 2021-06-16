/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:28:29 by eerika            #+#    #+#             */
/*   Updated: 2021/06/14 19:28:30 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "libft/libft.h"

void	send_msg(int pid, char *msg)
{
	size_t	j;
	int		i;

	j = 0;
	while (msg[j])
	{
		i = 128;
		while (i >= 1)
		{
			if (i & msg[j])
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i /= 2;
			usleep(100);
		}
		j++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		send_msg(pid, argv[2]);
	}
	else
		ft_putstr("Usage: ./client <server_pid> <message>\n");
	return (0);
}

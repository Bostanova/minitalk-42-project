/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eerika <eerika@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 19:28:21 by eerika            #+#    #+#             */
/*   Updated: 2021/06/14 19:28:22 by eerika           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>

int		ft_atoi(const char *str);
int		ft_isspace(int c);
int		ft_isdigit(int c);
void	ft_putchar(char c);
int		ft_putstr(char *str);
void	ft_putnbr(int nbr);
void	ft_putendl(char *str);

#endif
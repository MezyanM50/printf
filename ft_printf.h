/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:33:31 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/24 11:47:28 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef	FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>

int	ft_putpointer(unsigned long n);
int	ft_putnbr(int nb);
int	ft_putuns(unsigned int nb);
int	ft_put_X(int nb);
int	ft_put_x(int nb);
int	ft_putstr(char *str);
int	ft_putchar(char c);

#endif


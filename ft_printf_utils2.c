/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:22:47 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/27 15:22:48 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_put_x(unsigned int nb)
{
	char	*a;
	char	s[32];
	int		i;
	
	if (nb == 0)
		return (ft_putchar('0'));
	i = 0;
	a = "0123456789abcdef";
	while (nb >= 16)
	{
		s[i++] = a[nb % 16];
		nb /= 16;
	}
	s[i++] = a[nb];
	s[i] = '\0';
	ft_strrev(s,i);
	return (i);
}

int	ft_put_gx(unsigned int nb)
{
	char	*a;
	char	s[32];
	int		i;

	i = 0;
	a = "0123456789ABCDEF";
	if (nb == 0)
		return (ft_putchar('0'));
	while (nb >= 16)
	{
		s[i++] = a[nb % 16];
		nb /= 16;
	}
	s[i++] = a[nb];
	s[i] = '\0';
	ft_strrev(s,i);
	return (i);
}

int	ft_putpointer(unsigned long n)
{
	char	*a;
	char	s[17];
	int		i;

	i = 0;
	a = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("0x0"));
	write(1, "0x", 2);
	while (n)
	{
		s[i++] = a[n % 16];
		n /= 16;
	}
	s[i] = '\0';
	ft_strrev(s,i);
	return (i + 2);
}


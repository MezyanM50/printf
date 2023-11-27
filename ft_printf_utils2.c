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
	int		count;
	char	*a;
	char	s[100];
	int		i;

	count = 0;
	i = 0;
	a = "0123456789abcdef";
	while (nb > 0)
	{
		s[i++] = a[nb % 16];
		nb /= 16;
		count ++;
	}
	s[i] = '\0';
	ft_strrev(s,i);
	return (count);
}

int	ft_put_gx(unsigned int nb)
{
	int		count;
	char	*a;
	char	s[100];
	int		i;

	count = 0;
	i = ft_number_size_x(nb);
	a = "0123456789ABCDEF";
	count += 2;
	while (nb)
	{
		s[i++] = a[nb % 16];
		nb /= 16;
		count ++;
	}
	s[i] = '\0';
	ft_strrev(s,i);
	return (count);
}

int	ft_putpointer(unsigned long n)
{
	int		count;
	char	*a;
	char	s[17];
	int		i;

	count = 0;
	i = 0;
	a = "0123456789abcdef";
	if (!n)
		return (write(1, "0x0", 3));
	write(1, "0x", 2);
	count += 2;
	while (n)
	{
		s[i++] = a[n % 16];
		n /= 16;
		count ++;
	}
	s[i] = '\0';
	ft_strrev(s,i);
	return (count);
}

unsigned int	ft_number_size_x(unsigned int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number /= 10;
		length++;
	}
	return (length);
}

unsigned int	ft_number_size_pointer(unsigned long number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		return (1);
	while (number > 0)
	{
		number /= 16;
		length++;
	}
	return (length);
}

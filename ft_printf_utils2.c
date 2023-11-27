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
	int count;
	char *a;
	char *s;
	int i;

	count = 0;
	i = ft_number_size_xX(nb);
	a = "0123456789abcdef";
	s = malloc(i + 1);
	count += 2;
	s[i] = '\0';
	while (nb)
	{
		s[--i] = a[nb %16];
		nb /= 16;
		count ++;
	}
	ft_putstr(s);
	free(s);
	return (count);
}

int	ft_put_X(unsigned int nb)
{
	int count;
	char *a;
	char *s;
	int i;

	count = 0;
	i = ft_number_size_xX(nb);
	a = "0123456789ABCDEF";
	s = malloc(ft_number_size_pointer(nb)+ 1);
	count += 2;
	s[i] = '\0';
	while (nb)
	{
		s[--i] = a[nb %16];
		nb /= 16;
		count ++;
	}
	ft_putstr(s);
	free(s);
		return (count);
}

int	ft_putpointer(unsigned long n)
{
	int count;
	char *a;
	char *s;
	int i;

	count = 0;
	i = ft_number_size_pointer(n);
	a = "0123456789abcdef";
	s = malloc(ft_number_size_pointer(n)+ 1);
	if(write(1, "0x0", 3) == -1)
		return (-1);
	count += 3;
	s[i] = '\0';
	while (n)
	{
		s[--i] = a[n %16];
		n /= 16;
		count ++;
	}
	ft_putstr(s);
	free(s);
	return (count);
}

unsigned int	ft_number_size_xX(unsigned int number)
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

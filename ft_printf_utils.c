/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:48 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/27 14:36:57 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	
	if (!str)
		return (write(1,"(null)",6));
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
			return (-1);
		i++;
	}
	return (i);
}

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

int	ft_putuns(unsigned int nb)
{
	int count;

	count = 0;
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + 48;
		count+=write(1, &nb, 1);
	}
	else
	{
		count+=ft_putnbr(nb / 10);
		count+=ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putnbr(int nb)
{
	int count;

	count = 0;
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return(11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1);
		count++;
	}
	else if (nb >= 0 && nb <= 9)
	{
		nb = nb + 48;
		count+=write(1, &nb, 1);
		
	}
	else
	{
		count+=ft_putnbr(nb / 10);
		count+=ft_putnbr(nb % 10);
	}
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
	if (number < 0)
		length += 1;
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
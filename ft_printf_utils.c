/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:48 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/25 18:16:47 by mmezyan          ###   ########.fr       */
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
	
	count = 0; 
	a = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
		count+=ft_putchar(a[nb]);
	else
	{
		count+=ft_putnbr(nb / 16);
		count+=ft_putnbr(nb % 16);
	}
	return(count);
}

int	ft_put_X(unsigned int nb)
{
	int count;
	char *a ;
	
	a = "0123456789ABCDEF";
	count = 0;
	if (nb >= 0 && nb < 16)
		count+=ft_putchar(a[nb]);
	else
	{
		count+=ft_putnbr(nb / 16);
		count+=ft_putnbr(nb % 16);
	}
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

	count = 0;
	if (!n)
		return(ft_putstr("0x0"));
	if (write(1,"0x",2) == -1)
		return (-1);
	a = "0123456789abcdef";
	if (n >= 0 && n <= 16)
		count+=ft_putchar(a[n]);
	else
	{
		count+=ft_putpointer(n / 16);
		count+=ft_putpointer(n % 16);
	}
	return (count + 2);
}
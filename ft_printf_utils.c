/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:48 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/24 11:46:06 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	if (!c)
		return (NULL);
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (write(1,"(null)",6));
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_put_x(int nb)
{
	int count;
	char a[16];
	
	count = 0; 
	a[16] = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
		count += ft_putchar(a[nb]);
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
}

int	ft_put_X(int nb)
{
	int count;
	char a[16] ;
	
	a[16]= "0123456789ABCDEF";
	count = 0;
	if (nb >= 0 && nb < 16)
	{
		count += ft_putchar(a[nb]);
	}
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
}

int	ft_putuns(unsigned int nb)
{
	int count;

	count = 0;
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + 48;
		write(1, &nb, 1);
		count++;
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
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
		write(1, &nb, 1);
		count++;
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	return (count);
}

int	ft_putpointer(unsigned long n)
{
	int count;
	count = 0;
	if (!n)
		return(ft_putstr("0x0"));
	write(1,"0x",2);
	count += ft_put_x(n);
	return (count + 2);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:48 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/23 18:18:12 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	if (!c)
		return (NULL);
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;
	
	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
		write(1, &str[i++], 1);
}

void ft_put_x(int	nb)
{
	char a[] = "0123456789abcdef";
	if (nb >= 0 && nb < 16)
		ft_putchar(a[nb]);
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
}

void ft_put_X(int	nb)
{
	char a[] = "0123456789ABCDEF";
	if (nb >= 0 && nb < 16)
		ft_putchar(a[nb]);
	else
	{
		ft_putnbr(nb / 16);
		ft_putnbr(nb % 16);
	}
}

void	ft_putuns(unsigned int nb)
{
	
	if (nb >= 0 && nb <= 9)
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
	}
	else if (nb < 0)
	{
		write(1, "-", 1);
		ft_putnbr(nb * -1);
	}
	else if (nb >= 0 && nb <= 9)
	{
		nb = nb + 48;
		write(1, &nb, 1);
	}
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}

void ft_putpointer(void *p)
{
	unsigned long	*n;	
}
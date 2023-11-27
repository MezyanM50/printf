/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:48 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/27 15:22:13 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

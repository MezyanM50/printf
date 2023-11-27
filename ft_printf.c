/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 13:34:44 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/27 14:37:05 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_p2(char c, int *count, va_list args)
{
			if (c == 'd' || c == 'i')
				*count += ft_putnbr(va_arg(args, int));
			else if (c == 'p')
				*count += ft_putpointer(va_arg(args,unsigned long));
			else if (c == 's')
				*count += ft_putstr(va_arg(args,char *));
			else if (c == 'c')
				*count +=ft_putchar(va_arg(args,int));
			else if (c == 'u')
				*count += ft_putuns(va_arg(args,unsigned int));
			else if (c == 'x')
				*count +=ft_put_x(va_arg(args,unsigned int));
			else if (c == 'X')
				*count +=ft_put_gx(va_arg(args,unsigned int));
			else if (c == '%')
				*count += ft_putchar('%');
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		count;
	va_list	args;

	va_start(args,str);
	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			ft_p2(str[i], &count, args);
		}
		else if (str[i] != '%')
			count += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

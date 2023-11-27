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
			if (str[i] == 'd' || str[i] == 'i')
				count += ft_putnbr(va_arg(args, int));
			else if (str[i] == 'p')
				count += ft_putpointer(va_arg(args,unsigned long));
			else if (str[i] == 's')
				count += ft_putstr(va_arg(args,char *));
			else if (str[i] == 'c')
				count +=ft_putchar(va_arg(args,int));
			else if (str[i] == 'u')
				count += ft_putuns(va_arg(args,unsigned int));
			else if (str[i] == 'x')
				count +=ft_put_x(va_arg(args,unsigned int));
			else if (str[i] == 'X')
				count +=ft_put_X(va_arg(args,unsigned int));
			else if (str[i] == '%')
				count += ft_putchar('%');
		}
		else if (str[i] != '%')
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (count);
}

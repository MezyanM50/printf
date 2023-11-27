/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmezyan <mmezyan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:33:31 by mmezyan           #+#    #+#             */
/*   Updated: 2023/11/27 10:50:55 by mmezyan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void			ft_p2(char c, int *count, va_list args);
void			ft_strrev(char *s, int len);
int				ft_printf(const char *str, ...);
int				ft_putpointer(unsigned long n);
int				ft_putnbr(int nb);
int				ft_putuns(unsigned int nb);
int				ft_put_gx(unsigned int nb);
int				ft_put_x(unsigned int nb);
int				ft_putstr(char *str);
int				ft_putchar(char c);
unsigned int	ft_number_size_pointer(unsigned long number);
unsigned int	ft_number_size_x(unsigned int number);

#endif

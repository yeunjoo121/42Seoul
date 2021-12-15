/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 17:23:16 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:04:11 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunnbr_fd(unsigned int n, int fd)
{
	if (n < 10 && n >= 0)
	{
		ft_putchar_fd(n + '0', fd);
	}
	else if (n > 0)
	{
		ft_putunnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

int	type_division(char ch, va_list *ap, int *length)
{
	if (ch == 'c')
		(*length) += ft_printf_c(va_arg(*ap, int));
	else if (ch == 's')
		(*length) += ft_printf_s(va_arg(*ap, char *));
	else if (ch == '%')
		(*length) += ft_printf_percent();
	else if (ch == 'd' || ch == 'i')
		(*length) += ft_printf_di(va_arg(*ap, int));
	else if (ch == 'u')
		(*length) += ft_printf_u(va_arg(*ap, unsigned int));
	else if (ch == 'p')
		(*length) += ft_printf_p((unsigned long)(va_arg(*ap, void *)));
	else if (ch == 'x')
		(*length) += ft_printf_xlow((unsigned int)(va_arg(*ap, void *)));
	else if (ch == 'X')
		(*length) += ft_printf_xupper(va_arg(*ap, unsigned int));
	else
		return (-1);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		length;

	length = 0;
	va_start(ap, format);
	while (*format != 0 && format != 0)
	{
		if (*format == '%')
		{
			format++;
			if (type_division(*format, &ap, &length) < 0)
			{
				return (-1);
			}
		}
		else
			length += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (length);
}

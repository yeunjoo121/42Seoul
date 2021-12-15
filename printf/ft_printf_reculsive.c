/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_reculsive.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:49:48 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:06:11 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_pointer_p(unsigned long pointer, int length)
{
	if (pointer == 0 && length == 0)
	{
		ft_putchar_fd('0', 1);
		length++;
	}
	if (pointer > 0)
	{
		length = ft_print_pointer_p(pointer / 16, length + 1);
		ft_putchar_fd(HEX_LOW[pointer % 16], 1);
	}
	return (length);
}

int	ft_print_pointer_xlow(unsigned int pointer, int length)
{
	if (pointer == 0 && length == 0)
	{
		ft_putchar_fd('0', 1);
		length++;
	}
	if (pointer > 0)
	{
		length = ft_print_pointer_xlow(pointer / 16, length + 1);
		ft_putchar_fd(HEX_LOW[pointer % 16], 1);
	}
	return (length);
}

int	ft_print_pointer_xupper(unsigned int pointer, int length)
{
	if (pointer == 0 && length == 0)
	{
		ft_putchar_fd('0', 1);
		length++;
	}
	if (pointer > 0)
	{
		length = ft_print_pointer_xupper(pointer / 16, length + 1);
		ft_putchar_fd(HEX_UPPER[pointer % 16], 1);
	}
	return (length);
}

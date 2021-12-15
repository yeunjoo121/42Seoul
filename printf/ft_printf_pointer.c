/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:49:06 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:10:37 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_p(unsigned long pointer)
{
	ft_putstr_fd("0x", 1);
	return (2 + ft_print_pointer_p(pointer, 0));
}

int	ft_printf_xlow(unsigned int pointer)
{
	return (ft_print_pointer_xlow(pointer, 0));
}

int	ft_printf_xupper(unsigned int pointer)
{
	return (ft_print_pointer_xupper(pointer, 0));
}

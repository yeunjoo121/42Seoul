/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:51:24 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:09:23 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_c(char ch)
{
	ft_putchar_fd(ch, 1);
	return (1);
}

int	ft_printf_s(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (ft_strlen("(null)"));
	}
	else
	{
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
}

int	ft_printf_percent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

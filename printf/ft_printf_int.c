/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:52:07 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:07:10 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_di(int printint)
{
	ft_putnbr_fd(printint, 1);
	return (ft_nbrlength(printint));
}

int	ft_printf_u(unsigned int printint)
{
	ft_putunnbr_fd(printint, 1);
	return (ft_unnbrlength(printint));
}

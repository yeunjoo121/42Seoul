/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 20:53:07 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:16:09 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "./libft/libft.h"

# define HEX_LOW "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_printf_c(char ch);
int		ft_printf_s(char *str);
int		ft_printf_percent(void);
int		ft_printf_di(int printint);
int		ft_printf_u(unsigned int printint);
int		ft_nbrlength(int n);
int		ft_unnbrlength(unsigned int n);
int		ft_printf_p(unsigned long pointer);
int		ft_printf_xlow(unsigned int pointer);
int		ft_printf_xupper(unsigned int pointer);
int		ft_print_pointer_p(unsigned long pointer, int length);
int		ft_print_pointer_xlow(unsigned int pointer, int length);
int		ft_print_pointer_xupper(unsigned int pointer, int length);
void	ft_putunnbr_fd(unsigned int n, int fd);
int		ft_printf(const char *format, ...);

#endif

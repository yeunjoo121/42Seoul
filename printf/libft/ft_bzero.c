/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:54:14 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:22:06 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ret;
	size_t			index;

	index = 0;
	ret = (unsigned char *)s;
	while (index < n)
	{
		ret[index] = 0;
		index++;
	}
}

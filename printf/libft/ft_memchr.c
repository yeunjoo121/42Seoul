/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:03:55 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:39:56 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *ptr, int value, size_t num)
{
	size_t	index;

	index = 0;
	while (index < num)
	{
		if (((unsigned char *)ptr)[index] == (unsigned char)(value))
		{
			return ((void *)ptr + index);
		}
		index++;
	}
	return ((void *)(0));
}

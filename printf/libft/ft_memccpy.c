/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:00:33 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:39:00 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t	index;
	int		flag;

	flag = 0;
	index = 0;
	while (index < n)
	{
		if (((unsigned char *)src)[index] == (unsigned char)(c))
		{
			((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
			index++;
			flag = 1;
			break ;
		}
		((unsigned char *)dest)[index] = ((unsigned char *)src)[index];
		index++;
	}
	if (flag == 0)
		return ((void *)(0));
	else
		return ((void *)dest + index);
}

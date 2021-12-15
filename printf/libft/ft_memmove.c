/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:42:45 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/09/29 21:41:01 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t num)
{
	size_t	index;

	if (!src && !dest)
		return (NULL);
	index = 0;
	if (dest < src)
	{
		while (index < num)
		{
			((char *)dest)[index] = ((char *)src)[index];
			index++;
		}
	}
	else
	{
		while (index < num)
		{
			((char *)dest)[num - 1 - index] = ((char *)src)[num - 1 - index];
			index++;
		}
	}
	return (dest);
}

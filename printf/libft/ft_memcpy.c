/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:21:33 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/10 12:54:46 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *source, size_t num)
{
	size_t	index;

	index = 0;
	if (source == dest)
	{
		return (dest);
	}
	while (index < num)
	{
		((unsigned char *)dest)[index] = ((unsigned char *)source)[index];
		index++;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:13:21 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/10 12:41:46 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dstlen;
	size_t	srclen;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen + 1)
	{
		return (srclen + size);
	}
	while (dstlen + 1 + index < size && src[index] != '\0')
	{
		dst[index + dstlen] = src[index];
		index++;
	}
	dst[dstlen + index] = '\0';
	return (dstlen + srclen);
}

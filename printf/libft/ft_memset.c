/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:31:16 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/05 18:54:05 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*ret;

	index = 0;
	ret = (unsigned char *)b;
	while (index < len)
	{
		ret[index] = (unsigned char)c;
		index++;
	}
	return (ret);
}

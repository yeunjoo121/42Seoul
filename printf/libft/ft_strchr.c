/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:55:35 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/05 17:17:15 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;

	index = 0;
	while (s[index] != '\0')
	{
		if ((char)c == s[index])
		{
			return ((char *)(&s[index]));
		}
		index++;
	}
	if ((char)c == s[index])
	{
		return ((char *)(&s[index]));
	}
	return (NULL);
}

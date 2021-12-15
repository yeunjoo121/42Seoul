/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 16:55:35 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/05 18:05:06 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	index;
	char	*res;

	index = 0;
	res = NULL;
	while (s[index] != '\0')
	{
		if (s[index] == (char)c)
		{
			res = (char *)&s[index];
		}
		index++;
	}
	if ((char)c == 0)
	{
		res = (char *)&s[ft_strlen(s)];
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 13:42:05 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/13 15:58:29 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	strindex;
	unsigned int	sindex;

	sindex = 0;
	strindex = 0;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!(str))
	{
		return (NULL);
	}
	while (s[sindex] != '\0')
	{
		if (sindex >= start && strindex < len)
		{
			str[strindex++] = s[sindex];
		}
		sindex++;
	}
	str[strindex] = '\0';
	return (str);
}

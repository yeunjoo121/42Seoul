/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:56:09 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/13 14:21:37 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*p;
	size_t		slen;
	size_t		index;

	index = 0;
	slen = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (slen + 1));
	if (!(p))
	{
		return (0);
	}
	while (index < slen)
	{
		p[index] = s1[index];
		index++;
	}
	p[index] = '\0';
	return (p);
}

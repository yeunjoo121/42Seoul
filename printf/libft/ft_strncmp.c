/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 18:11:47 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/05 18:27:44 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		index;

	index = 0;
	while (s1[index] != '\0' && index < n)
	{
		if (s1[index] != s2[index])
		{
			return ((unsigned char)(s1[index])
			 - (unsigned char)(s2[index]));
		}
		index++;
	}
	if (s1[index] == '\0' && index < n)
	{
		return (s1[index] - s2[index]);
	}
	return (0);
}

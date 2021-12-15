/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yeonjkim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:50:05 by yeonjkim          #+#    #+#             */
/*   Updated: 2021/05/13 18:27:03 by yeonjkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isin(char find, char const *str)
{
	int		index;

	index = 0;
	while (str[index] != '\0')
	{
		if (find == str[index])
		{
			return (1);
		}
		index++;
	}
	return (0);
}

static int	ft_findstart(char const *s1, char const *set)
{
	int		index;

	index = 0;
	while (s1[index] != '\0')
	{
		if (ft_isin(s1[index], set) == 0)
		{
			return (index);
		}
		index++;
	}
	return (-1);
}

static int	ft_findend(char const *s1, char const *set)
{
	int		index;

	index = ft_strlen(s1) - 1;
	while (index >= 0)
	{
		if (ft_isin(s1[index], set) == 0)
		{
			return (index);
		}
		index--;
	}
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;
	int		index;

	str = NULL;
	index = 0;
	start = ft_findstart(s1, set);
	end = ft_findend(s1, set);
	if (start == -1 || end == -1)
	{
		str = (char *)malloc(1);
		str[0] = 0;
		return (str);
	}
	str = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!(str))
		return (NULL);
	while (start <= end)
		str[index++] = s1[start++];
	str[index] = '\0';
	return (str);
}

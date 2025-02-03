/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:47 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/03 15:42:55 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_sublen(char *s, unsigned int start, size_t len)
{
	if (start > ft_strlen(s))
		return (0);
	if (len > ft_strlen(s + start))
		return (ft_strlen(s + start));
	return (len);
}

char	*ft_substr_free(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_sublen(s, start, len) + 1));
	if (!str)
		return (NULL);
	if ((size_t)start < ft_strlen(s))
	{
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	}
	str[i] = 0;
	free(s);
	return (str);
}

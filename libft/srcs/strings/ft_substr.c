/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:06:29 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/29 15:14:17 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*ptr;

	if (ft_strlen(str) < start || !str)
	{
		len = 0;
		start = 0;
	}
	if (ft_strlen(str + start) < len)
		len = ft_strlen(str + start);
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, str + start, len + 1);
	return (ptr);
}

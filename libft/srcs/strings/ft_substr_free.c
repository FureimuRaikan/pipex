/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:50:39 by unmugviolet       #+#    #+#             */
/*   Updated: 2025/02/04 18:54:26 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

char	*ft_substr_free(char *str, unsigned int start, size_t len)
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
	free(str);
	return (ptr);
}

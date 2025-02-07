/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: unmugviolet <unmugviolet@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:58:23 by pjaguin           #+#    #+#             */
/*   Updated: 2025/01/29 15:14:17 by unmugviolet      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "str_utils.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*last_find;

	i = 0;
	last_find = NULL;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			last_find = (char *)(str + i);
		i++;
	}
	if (str[i] == (unsigned char)c)
		last_find = (char *)(str + i);
	return (last_find);
}

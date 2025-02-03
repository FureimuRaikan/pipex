/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 08:45:34 by yguinio           #+#    #+#             */
/*   Updated: 2025/02/03 15:43:12 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	i;
	int		is_word;
	size_t	words_count;

	i = 0;
	is_word = 0;
	words_count = 0;
	while (str[i])
	{
		if (str[i] == c)
			is_word = 0;
		else if (!is_word)
		{
			is_word = 1;
			words_count++;
		}
		i++;
	}
	return (words_count);
}

static size_t	ft_word_len(const char *str, char c)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = 0;
	while (str[i])
	{
		if (str[i] && str[i] != c)
		{
			while (str[i] && str[i] != c)
			{
				size++;
				i++;
			}
			return (size);
		}
		i++;
	}
	return (size);
}

static char	**write_split(char **array, const char *str, char c,
		size_t word_count)
{
	size_t	i;
	size_t	word_len;

	i = 0;
	while (i < word_count)
	{
		word_len = ft_word_len(str, c);
		while (*str == c)
			str++;
		array[i] = (char *)ft_calloc(sizeof(char), word_len + 1);
		if (!array[i])
			return (ft_free_split(array), NULL);
		ft_strlcpy(array[i], str, word_len + 1);
		str += word_len;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *str, char c)
{
	char	**array;
	size_t	word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str, c);
	array = (char **)ft_calloc(sizeof(char *), (word_count + 1));
	if (!array)
		return (NULL);
	return (write_split(array, str, c, word_count));
}

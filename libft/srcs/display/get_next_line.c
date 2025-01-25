/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:11:22 by yguinio           #+#    #+#             */
/*   Updated: 2025/01/23 17:00:16 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*read_file(int fd, char *main_str)
{
	char	*buff;
	int		count;

	count = 1;
	buff = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(main_str, '\n') && count != 0)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count == -1)
		{
			if (buff)
				free(buff);
			if (main_str)
				free(main_str);
			return (NULL);
		}
		buff[count] = 0;
		main_str = ft_strjoin_free(main_str, buff);
	}
	free(buff);
	return (main_str);
}

char	*ft_get_line(char *main_str)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!main_str[i])
		return (NULL);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	str = ft_calloc(sizeof(char), (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (main_str[i] && main_str[i] != '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	if (main_str[i] == '\n')
	{
		str[i] = main_str[i];
		i++;
	}
	str[i] = 0;
	return (str);
}

char	*ft_get_next_content(char *main_str)
{
	size_t	i;
	size_t	j;
	char	*str;
	size_t	main_str_len;

	i = 0;
	j = 0;
	main_str_len = ft_strlen(main_str);
	while (main_str[i] && main_str[i] != '\n')
		i++;
	if (!main_str[i])
	{
		free(main_str);
		return (NULL);
	}
	str = ft_calloc(sizeof(char), main_str_len - i + 1);
	if (!str)
		return (NULL);
	while (main_str[++i])
		str[j++] = main_str[i];
	str[j] = 0;
	free(main_str);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*main_str[4096];

	if (fd < 0)
		return (NULL);
	main_str[fd] = read_file(fd, main_str[fd]);
	if (!main_str[fd])
		return (NULL);
	line = ft_get_line(main_str[fd]);
	main_str[fd] = ft_get_next_content(main_str[fd]);
	return (line);
}

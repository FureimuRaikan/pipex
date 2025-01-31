/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:23:30 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/29 13:27:40 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_split(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array[i]);
	free(array);
}

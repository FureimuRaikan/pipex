/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:55:44 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/30 16:14:03 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_check_access(int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 9) && access(av[1], R_OK) == -1)
	{
		perror("Error file 1");
		exit(EXIT_FAILURE);
	}
	if (access(av[ac - 1], F_OK) == -1)
		return ;
	if (access(av[ac - 1], R_OK | W_OK) == -1)
	{
		perror("Error file 2");
		exit(EXIT_FAILURE);
	}
}

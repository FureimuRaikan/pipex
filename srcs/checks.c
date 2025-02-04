/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:55:44 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/04 11:21:57 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_arg_check(int ac, char **av)
{
	if (ac < 6 && !ft_strncmp("here_doc", av[1], 10))
	{
		ft_putstr_fd("Not enough arguments. ", 2);
		ft_putstr_fd("Usage: ./pipex here_doc LIMITER cmd1 cmd2 file2\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (ac < 5 && ft_strncmp("here_doc", av[1], 10))
	{
		ft_putstr_fd("Not enough arguments. ", 2);
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 ..cmd[n] file2\n", 2);
		exit(EXIT_FAILURE);
	}
}

void	ft_check_access(int ac, char **av)
{
	if (ft_strncmp(av[1], "here_doc", 9) && access(av[1], R_OK) == -1)
		perror("Error file 1");
	if (access(av[ac - 1], F_OK) == -1)
		return ;
	if (access(av[ac - 1], R_OK | W_OK) == -1)
	{
		perror("Error file 2");
		exit(EXIT_FAILURE);
	}
}

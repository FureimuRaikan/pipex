/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:36:46 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/30 16:14:50 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_struct_init(t_pipex *pipex, int ac, char **av, char **env)
{
	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		pipex->in_fd = STDIN_FILENO;
		pipex->here_doc = 1;
		pipex->out_fd = open(av[ac - 1], O_RDWR | O_APPEND | O_CREAT, 0644);
		if (pipex->out_fd == -1)
			ft_exit_error(*pipex, "Error opening file 2");
	}
	else
	{
		pipex->in_fd = open(av[1], O_RDONLY);
		pipex->here_doc = 0;
		if (pipex->in_fd == -1)
			ft_exit_error(*pipex, "Error opening file 1");
		pipex->out_fd = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0644);
		if (pipex->out_fd == -1)
			ft_exit_error(*pipex, "Error opening file 2");
	}
	pipex->cmd_count = ac - 3;
	pipex->env = env;
	pipex->current_cmd = NULL;
}

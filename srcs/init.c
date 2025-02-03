/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguinio <yguinio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:36:46 by fureimu           #+#    #+#             */
/*   Updated: 2025/02/03 12:45:19 by yguinio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_get_path_from_env(char **env)
{
	char	**path;
	int		i;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	path = ft_split(env[i] + 5, ':');
	i = -1;
	while (path[++i])
		path[i] = ft_strjoin_free(path[i], "/");
	return (path);
}

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

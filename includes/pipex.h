/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:54:30 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/30 14:14:43 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		cmd_count;
	int		pipefd[2];
	int		here_doc;
	char	**env;
	char	**current_cmd;
}			t_pipex;

void	ft_check_access(int ac, char **av);
void	ft_struct_init(t_pipex *pipex, int ac, char **av, char **env);
void	ft_exit_error(t_pipex pipex, char *str);
void	ft_close_all(t_pipex pipex, char *curr_str);

#endif
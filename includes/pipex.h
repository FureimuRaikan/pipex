/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 13:54:30 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/28 16:44:50 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"

# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_pipex
{
	int		in_fd;
	int		out_fd;
	int		pipefd[2];
	int		cmd_count;
	char	**env;
	bool	here_doc;
}			t_pipex;

int		ft_check_access_create(int ac, char **av);
bool	is_struct_init(t_pipex pipex, int ac, char **av, char **env);

#endif

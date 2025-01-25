/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:43 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/25 19:09:19 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int main(int ac, char **av)
{
	int fd1;
	int fd2;
	char	**cmd;
	int	i;
	char const	*path = "/bin/";
	(void)ac;
	if (access(av[1], R_OK) == -1)
	{
		perror("Error accessing first file");
		return (1);
	}
	if (access(av[3], R_OK | W_OK) == -1)
	{
		perror("Error accessing second file");
		return (1);
	}
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[3], O_RDWR | O_TRUNC);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	cmd = ft_split(av[2], ' ');
	for (i = 0; cmd[i] != NULL; i++)
		ft_printf("%s\n", cmd[i]);
	if (execve(ft_strjoin(path, cmd[0]), cmd, NULL) == -1)
	{
		perror("Command");
		return (1);
	}
	pid_t pid = fork();
	if (pid == -1)
	{
        perror("Error during fork");
        close(fd1);
		close(fd2);
        return (1);
    }
	
    return (0);
}
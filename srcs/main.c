/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 14:28:43 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/28 16:44:20 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	t_pipex	pipex;

	if (ac < 5)
		return (ft_putstr_fd("Wrong number of args.", 2), EXIT_FAILURE);
	if (!is_struct_init(pipex, ac, av, env))
		return (EXIT_FAILURE);
    return (0);
}

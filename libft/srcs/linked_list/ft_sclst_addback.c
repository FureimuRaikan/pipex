/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 16:42:36 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/23 16:56:24 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sclst_addback(t_sclist **stack, t_sclist *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		if (ft_sclstlast(*stack))
		{
			ft_sclstlast(*stack)->next = new;
			if (new)
				new->next = *stack;
		}
	}
}

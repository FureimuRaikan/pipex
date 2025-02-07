/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sclst_addback.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjaguin <pjaguin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 10:59:56 by pjaguin           #+#    #+#             */
/*   Updated: 2025/02/05 11:03:40 by pjaguin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linked_list.h"

void	ft_sclst_addback(t_sclist **stack, t_sclist *new)
{
	if (!stack)
		return ;
	if (!*stack)
		*stack = new;
	else
	{
		if (ft_sclst_last(*stack))
		{
			ft_sclst_last(*stack)->next = new;
			if (new)
				new->next = *stack;
		}
	}
}

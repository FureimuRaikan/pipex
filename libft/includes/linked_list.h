/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fureimu <fureimu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 10:29:34 by fureimu           #+#    #+#             */
/*   Updated: 2025/01/23 16:49:16 by fureimu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKED_LIST_H
# define LINKED_LIST_H

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);

t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new_element);
void		ft_lstadd_back(t_list **lst, t_list *new_element);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void *));

void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

typedef struct s_sclist
{
	int				value;
	struct s_sclist	*next;
}					t_sclist;

int			ft_sclst_size(t_sclist *sclist);
void		ft_sclst_clean(t_sclist **sclst);
void		ft_sclst_print(t_sclist **sclst, char c);
int			ft_sclst_max(t_sclist *sclist);
int			ft_sclst_min(t_sclist *sclist);
void		ft_sclist_addback(t_sclist **stack, t_sclist *new);
t_sclist	*ft_sclstlast(t_sclist *stack);
t_sclist	*ft_sclist_new(int content);

#endif
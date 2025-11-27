/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:14:59 by jodone            #+#    #+#             */
/*   Updated: 2025/11/27 15:15:34 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*psh_lstnew(int value, int index)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	ft_memset(newnode, -1, sizeof(t_stack));
	newnode->value = value;
	newnode->index = index;
	newnode->next = NULL;
	return (newnode);
}

t_stack	*psh_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
void	psh_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!lst)
		return ;
	tmp = psh_lstlast(*lst);
	if (!tmp)
		*lst = new;
	else
		tmp->next = new;
}

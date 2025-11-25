/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_lstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 14:37:06 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 15:14:11 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

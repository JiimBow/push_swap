/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psh_lstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:58:14 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 15:14:17 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*psh_lstnew(int value)
{
	t_stack	*newnode;

	newnode = malloc(sizeof(t_stack));
	if (!newnode)
		return (NULL);
	newnode->value = value;
	newnode->next = NULL;
	return (newnode);
}

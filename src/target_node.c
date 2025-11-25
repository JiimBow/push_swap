/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:43:25 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 17:58:11 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	target_node(int	value, t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*index_stack;

	tmp = stack;
	index_stack = stack;
	while (tmp)
	{
		if (value > tmp->value)
		{
			if (index_stack->value < tmp->value)
				index_stack = tmp;
		}
		tmp = tmp->next;
	}
	return (index_stack->index);
}

int	move_counter(int index, int nb_param)
{
	if (index < (nb_param / 2) + 1)
		return (1);
	return (0);
}

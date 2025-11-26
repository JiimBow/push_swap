/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 16:43:25 by jodone            #+#    #+#             */
/*   Updated: 2025/11/26 18:13:43 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	target_node(int	rank, t_stack **stack)
{
	t_stack	*tmp;
	int		t_rank;

	if (!stack)
		return (0);
	tmp = *stack;
	t_rank = -1;
	while (tmp)
	{
		if (tmp->rank < rank && tmp->rank > t_rank)
			t_rank = tmp->rank;
		tmp = tmp->next;
	}
	return (t_rank);
}

int	half_check(int index, int nb_param)
{
	if (index < (nb_param / 2) + 1)
		return (1);
	return (0);
}

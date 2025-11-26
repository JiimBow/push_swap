/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:39:18 by jodone            #+#    #+#             */
/*   Updated: 2025/11/26 17:35:26 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	lowest_value(t_stack *stack, int pre_lowest)
{
	int		lowest;
	t_stack	*tmp;

	lowest = 2147483647;
	tmp = stack;
	while (tmp)
	{
		if (pre_lowest == -2147483648)
		{
			if (tmp->value < lowest)
				lowest = tmp->value;
		}
		else if (tmp->value > pre_lowest && tmp->value < lowest)
			lowest = tmp->value;
		tmp = tmp->next;
	}
	return (lowest);
}

int	rank_check(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->rank == -1)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	rank_param(t_stack *stack)
{
	t_stack	*tmp;
	int		lowest;
	int		rank;

	lowest = -2147483648;
	rank = 0;
	while (1)
	{
		lowest = lowest_value(stack, lowest);
		tmp = stack;
		while (tmp)
		{
			if (tmp->value == lowest)
				tmp->rank = rank;
			tmp = tmp->next;
		}
		if (rank_check(stack) == 0)
			break ;
	}
}

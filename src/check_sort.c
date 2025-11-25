/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:15:56 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 15:16:03 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_sort(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack);
	while (tmp)
	{
		if (tmp->next && tmp->next->value < tmp->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 15:55:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_param(t_stack **stack)
{
	t_stack	*tmp;
	int	count;

	count = 0;
	tmp = *stack;
	while (tmp)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	push(stack_a, stack_b);
	ft_printf("pb\npb\n");
	while (1)
	{
		if (count_param(stack_a) == 3)
			sort_three(stack_a);
		else
		{
			
		}
	}
}
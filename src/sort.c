/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 18:02:05 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 	push les deux premiers de a à b
	*/

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
	int	index;
	int	counter;

	push(stack_a, stack_b);
	push(stack_a, stack_b);
	set_index(*stack_a);
	set_index(*stack_b);
	ft_printf("pb\npb\n");
	while (1)
	{
		if (count_param(stack_a) == 3)
			sort_three(stack_a);
		else
		{
			index = target_node((*stack_a)->value, *stack_b);
			if (index != 0)
			{
				if (move_counter(index, count_param(stack_b)) == 1)
				{
					counter = index + 1;
					while (counter > 0)
					{
						rotate(stack_b);
						ft_printf("rb\n");
						counter--;
					}
				}
				else
				{
					counter = count_param(stack_b) - index + 1;
					while (counter > 0)
					{
						reverse_rotate(stack_b);
						ft_printf("rrb\n");
						counter--;
					}
				}
			}
			push(stack_a, stack_b);
			ft_printf("pb\n");
		}
		if (check_sort(stack_a) == 0)
			break ;
	}
}

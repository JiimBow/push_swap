/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:29:04 by jodone            #+#    #+#             */
/*   Updated: 2025/11/27 16:10:39 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	count_move_b(t_stack *stack, int rank)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->rank != rank)
		tmp = tmp->next;
	return (tmp->index);
}

void	rotate_push(t_stack **stack_a, t_stack **stack_b, int rank)
{
	int	target_rank;

	target_rank = -1;
	while ((*stack_a)->rank != rank)
		rotate(stack_a, 'a');
	if ((*stack_b))
	{
		target_rank = target_node(rank, stack_b);
		while ((*stack_b)->rank != target_rank)
		{
			if (count_move_b(*stack_b, target_rank) < (count_param(stack_b) / 2) + 1)
				rotate(stack_b, 'b');
			else
				reverse_rotate(stack_b, 'b');
		}
	}
	push(stack_a, stack_b, 'b');
}

void	r_rotate_push(t_stack **stack_a, t_stack **stack_b, int rank)
{
	int	target_rank;

	target_rank = -1;
	while ((*stack_a)->rank != rank)
		reverse_rotate(stack_a, 'a');
	if ((*stack_b))
	{
		target_rank = target_node(rank, stack_b);
		while ((*stack_b)->rank != target_rank)
		{
			if (count_move_b(*stack_b, target_rank) < (count_param(stack_b) / 2) + 1)
				rotate(stack_b, 'b');
			else
				reverse_rotate(stack_b, 'b');
		}
	}
	push(stack_a, stack_b, 'b');
}

void	rotate_push_back(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*tmp;
	int		target_rank;

	tmp = *stack_b;
	target_rank = -1;
	while (tmp)
	{
		if (tmp->rank > target_rank)
			target_rank = tmp->rank;
		tmp = tmp->next;
	}
	if (count_move_b(*stack_b, target_rank) < (count_param(stack_b) / 2) + 1)
	{
		while ((*stack_b)->rank != target_rank)
			rotate(stack_b, 'b');
	}
	else
	{
		while ((*stack_b)->rank != target_rank)
			reverse_rotate(stack_b, 'b');
	}
	while (*stack_b)
		push(stack_b, stack_a, 'a');
}

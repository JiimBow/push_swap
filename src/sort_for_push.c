/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:29:04 by jodone            #+#    #+#             */
/*   Updated: 2025/11/26 18:09:42 by jodone           ###   ########.fr       */
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

	target_rank = target_node(rank, stack_b);
	while ((*stack_a)->rank != rank)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	while ((*stack_b)->rank != target_rank)
	{
		if (count_move_b(*stack_b, target_rank) < (count_param(stack_b) / 2) + 1)
		{
			rotate(stack_b);
			ft_printf("rb\n");
		}
		else
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
		}
	}
	push(stack_a, stack_b);
}

void	r_rotate_push(t_stack **stack_a, t_stack **stack_b, int rank)
{
	int	target_rank;

	target_rank = target_node(rank, stack_b);
	while ((*stack_a)->rank != rank)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
	while ((*stack_b)->rank != target_rank)
	{
		if (count_move_b(*stack_b, target_rank) < (count_param(stack_b) / 2) + 1)
		{
			rotate(stack_b);
			ft_printf("rb\n");
		}
		else
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
		}
	}
	push(stack_a, stack_b);
}

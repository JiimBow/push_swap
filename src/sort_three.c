/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:09:30 by jodone            #+#    #+#             */
/*   Updated: 2025/11/27 15:20:28 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three_a(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
		rotate(stack, 'a');
	if ((*stack)->next->value > (*stack)->value
		&& (*stack)->next->value > (*stack)->next->next->value)
		reverse_rotate(stack, 'a');
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, 'a');
}

void	sort_three_b(t_stack **stack)
{
	if ((*stack)->value < (*stack)->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		rotate(stack, 'b');
	if ((*stack)->next->value < (*stack)->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		reverse_rotate(stack, 'b');
	if ((*stack)->value < (*stack)->next->value)
		swap(stack, 'b');
}

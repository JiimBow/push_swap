/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:09:30 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 15:14:20 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_three(t_stack **stack)
{
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->value > (*stack)->next->next->value)
	{
		rotate(stack);
		ft_printf("ra\n");
	}
	if ((*stack)->next->value > (*stack)->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		reverse_rotate(stack);
		ft_printf("rra\n");
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		swap(stack);
		ft_printf("sa\n");
	}
}

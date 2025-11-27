/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   both_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:25:35 by jodone            #+#    #+#             */
/*   Updated: 2025/11/27 15:07:38 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 'r');
	rotate(stack_b, 'r');
	ft_printf("rr\n");
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a, 'r');
	reverse_rotate(stack_b, 'r');
	ft_printf("rrr\n");
}

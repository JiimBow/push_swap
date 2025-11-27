/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 11:26:46 by jodone            #+#    #+#             */
/*   Updated: 2025/11/27 15:11:02 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **stack_from, t_stack **stack_to, char c)
{
	t_stack	*tmpfrom;
	t_stack	*tmpto;

	if (!(*stack_from))
		return ;
	tmpfrom = (*stack_from)->next;
	tmpto = (*stack_to);
	(*stack_to) = (*stack_from);
	(*stack_to)->next = tmpto;
	(*stack_from) = tmpfrom;
	set_index(*stack_from);
	set_index(*stack_to);
	ft_printf("p%c\n", c);
}

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp1;
	t_stack	*tmp2;

	if (!(*stack) || !(*stack)->next)
		return ;
	tmp1 = *stack;
	tmp2 = (*stack)->next;
	tmp1->next = tmp2->next;
	tmp2->next = tmp1;
	(*stack) = tmp2;
	set_index(*stack);
	ft_printf("s%c\n", c);
}

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (!(*stack))
		return ;
	tmp = (*stack);
	(*stack) = psh_lstlast(*stack);
	(*stack)->next = tmp;
	(*stack) = tmp->next;
	tmp->next = NULL;
	set_index(*stack);
	if (c == 'a' || c == 'b')
		ft_printf("r%c\n", c);
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*tmp_last;

	if (!(*stack))
		return ;
	tmp = (*stack);
	tmp_last = psh_lstlast(*stack);
	while (tmp->next && tmp->next != tmp_last)
	{
		tmp = tmp->next;
	}
	tmp_last->next = (*stack);
	(*stack) = tmp_last;
	tmp->next = NULL;
	set_index(*stack);
	if (c == 'a' || c == 'b')
		ft_printf("rr%c\n", c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/27 16:33:30 by jodone           ###   ########.fr       */
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

int	get_rank(t_stack **stack, int index)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->index != index)
		tmp = tmp->next;
	return (tmp->rank);
}

int	count_move_rra(t_stack **stack, int max_rank)
{
	t_stack	*tmp;
	int		index_rr;

	index_rr = 0;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->rank <= max_rank)
			index_rr = tmp->index;
		tmp = tmp->next;
	}
	return (index_rr);
}

int	count_move_ra(t_stack **stack, int max_rank)
{
	t_stack	*tmp;
	int		index_r;

	tmp = *stack;
	index_r = 0;
	while (tmp)
	{
		if (tmp->rank <= max_rank)
			break ;
		tmp = tmp->next;
	}
	return (tmp->index);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	chunk;
	int	nbrank;
	int	i;
	int	index_r;
	int	index_rr;

	nbrank = ((count_param(stack_a) / 10));
	chunk = 0;
	if (nbrank == 0)
		nbrank++;
	i = 0;
	while (1)
	{
		if (count_param(stack_a) == 3)
		{
			sort_three_a(stack_a);
			rotate_push_back(stack_b, stack_a);
			break ;
		}
		if (count_param(stack_a) == 2)
		{
			if ((*stack_a)->value > (*stack_a)->next->value)
				swap(stack_a, 'a');
			rotate_push_back(stack_b, stack_a);
			break ;
		}
		if (count_param(stack_a) == 1)
		{
			rotate_push_back(stack_b, stack_a);
			break ;
		}
		chunk += nbrank;
		while (*stack_a && i < chunk)
		{
			if (count_param(stack_b) == 3)
				sort_three_b(stack_b);
			index_r = count_move_ra(stack_a, chunk - 1);
			index_rr = count_move_rra(stack_a, chunk - 1);
			if (index_r < count_param(stack_a) - index_rr)
				rotate_push(stack_a, stack_b, get_rank(stack_a, index_r));
			else
				r_rotate_push(stack_a, stack_b, get_rank(stack_a, index_rr));
			i++;
		}
		if ((check_sort(stack_a) == 1 && !(*stack_b)) || !(*stack_a))
		{
			rotate_push_back(stack_b, stack_a);
			break ;
		}
	}
}

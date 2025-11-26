/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 15:15:26 by jodone            #+#    #+#             */
/*   Updated: 2025/11/26 17:48:47 by jodone           ###   ########.fr       */
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
	int	i;
	int	rank_r;
	int	rank_rr;

	chunk = ((count_param(stack_a) / 5));
	if (chunk == 0)
		chunk++;
	i = 0;
	while (check_sort(stack_a) && !(*stack_b))
	{
		if (count_param(stack_a) == 3)
		{
			sort_three(stack_a);
			while (stack_b)
			{
				push(stack_b, stack_a);
				(*stack_b) = (*stack_b)->next;
			}
		}
		chunk = chunk * (1 + i);
		while (i < chunk)
		{
			rank_r = count_move_ra(stack_a, chunk - 1);
			rank_rr = count_move_rra(stack_a, chunk - 1);
			if (rank_r < count_param(stack_a) - rank_rr)
				rotate_push(*stack_a, *stack_b, rank_r);
			else
				r_rotate_push(*stack_a, *stack_b, rank_rr);
			i++;
		}
	}
}

/*
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
					counter = index;
					while (counter > 0)
					{
						rotate(stack_b);
						ft_printf("rb\n");
						counter--;
					}
				}
				else
				{
					counter = count_param(stack_b) - index;
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
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 11:24:41 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 17:36:49 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack		*psh_lstnew(int value, int index);
void		psh_lstadd_back(t_stack **lst, t_stack *new);
t_stack		*psh_lstlast(t_stack *lst);
void		swap(t_stack **stack);
int			move_counter(int index, int nb_param);
void		set_index(t_stack *stack);
int			target_node(int	value, t_stack *stack);
void		push(t_stack **stack_from, t_stack **stack_to);
void		reverse_rotate(t_stack **stack);
void		sort_three(t_stack **stack);
void		big_sort(t_stack **stack_a, t_stack **stack_b);
void		rotate(t_stack **stack);
int			check_sort(t_stack **stack);
void		rotate_both(t_stack **stack_a, t_stack **stack_b);
void		reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

#endif
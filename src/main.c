/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodone <jodone@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 12:50:56 by jodone            #+#    #+#             */
/*   Updated: 2025/11/25 15:50:10 by jodone           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	i = 2;
	if (ac <= 1)
		return (0);
	stack_a = psh_lstnew(ft_atoi(av[1]));
	while (i < ac)
	{
		psh_lstadd_back(&stack_a, psh_lstnew(ft_atoi(av[i])));
		i++;
	}
	if (ac == 3)
	{
		if (check_sort(&stack_a) == 1)
		{
			swap(&stack_a);
			ft_printf("sa\n");
		}
	}
	else if (ac == 4)
		sort_three(&stack_a);
	else
		big_sort(&stack_a, &stack_b);
	ft_printf("\n---------\n\n");
	while (stack_a)
	{
		ft_printf("%i ", stack_a->value);
		stack_a = stack_a->next;
		ft_printf("\n");
	}
	ft_printf("\nstack\n");
}

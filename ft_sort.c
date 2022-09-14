/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:05:23 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:06:53 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(int argc, t_stack **stack_a, t_stack **stack_b)
{
	if (argc == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
	}
	else if (argc == 4)
		ft_sort_three(stack_a);
	else if (argc == 5)
		ft_sort_four(stack_a, stack_b);
	else if (argc == 6)
		ft_sort_five(stack_a, stack_b);
	else
		ft_radix(stack_a, stack_b);
}

void	ft_sort_five(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_smallest_a(stack_a, stack_b);
	ft_push_smallest_a(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_four(t_stack **stack_a, t_stack **stack_b)
{
	ft_push_smallest_a(stack_a, stack_b);
	ft_sort_three(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_three_help(t_stack **stack_a, int *numbers)
{
	if (numbers[0] > numbers[1] && numbers[1] > numbers[2])
	{
		ft_ra(stack_a);
		ft_sa(stack_a);
	}
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2]
		&& numbers[0] < numbers[2])
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
}

void	ft_sort_three(t_stack **stack_a)
{
	t_stack	*temp;
	int		numbers[3];
	int		i;

	i = 0;
	temp = *stack_a;
	while (temp != 0)
	{
		numbers[i] = temp -> content;
		temp = temp -> next;
		i++;
	}
	if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[0] < numbers[2])
		ft_sa(stack_a);
	else if (numbers[0] < numbers[1] && numbers[1] > numbers[2]
		&& numbers[0] > numbers[2])
		ft_rra(stack_a);
	else if (numbers[0] > numbers[1] && numbers[1] < numbers[2]
		&& numbers[0] > numbers[2])
		ft_ra(stack_a);
	else
		ft_sort_three_help(stack_a, numbers);
}

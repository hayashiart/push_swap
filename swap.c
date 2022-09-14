/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:06:24 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:06:26 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_stack **stack_a)
{
	t_stack	*temp;

	if (stack_a && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack	**stack_b)
{
	t_stack	*temp;

	if (stack_b && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (stack_a && (*stack_a)->next != NULL)
	{
		temp = (*stack_a)->next;
		(*stack_a)->next = temp->next;
		temp->next = *stack_a;
		*stack_a = temp;
	}
	if (stack_b && (*stack_b)->next != NULL)
	{
		temp = (*stack_b)->next;
		(*stack_b)->next = temp->next;
		temp->next = *stack_b;
		*stack_b = temp;
	}
	write(1, "ss\n", 3);
}

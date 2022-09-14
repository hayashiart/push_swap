/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:06:18 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:06:20 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*temp;

	if ((*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lst_add_back(&temp, *stack_a);
	*stack_a = temp;
	write(1, "ra\n", 3);
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*temp;

	if ((*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lst_add_back(&temp, *stack_b);
	*stack_b = temp;
	write(1, "rb\n", 3);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if ((*stack_a)->next == NULL)
		return ;
	temp = (*stack_a)->next;
	(*stack_a)->next = NULL;
	ft_lst_add_back(&temp, *stack_a);
	*stack_a = temp;
	if ((*stack_b)->next == NULL)
		return ;
	temp = (*stack_b)->next;
	(*stack_b)->next = NULL;
	ft_lst_add_back(&temp, *stack_b);
	*stack_b = temp;
	write(1, "rr\n", 3);
}

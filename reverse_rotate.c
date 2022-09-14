/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:06:11 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:06:13 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	new = ft_lst_new(temp->content);
	temp = *stack_a;
	while (temp->next != NULL)
	{
		if ((temp->next)->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
		}
		else
			temp = temp->next;
	}
	ft_lst_add_back(&new, *stack_a);
	*stack_a = new;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next != NULL)
		temp = temp -> next;
	new = ft_lst_new(temp -> content);
	temp = *stack_b;
	while (temp->next != NULL)
	{
		if ((temp->next)->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
		}
		else
			temp = temp->next;
	}
	ft_lst_add_back(&new, *stack_b);
	*stack_b = new;
	write(1, "rrb\n", 4);
}

void	ft_rra_prem(t_stack **stack_a)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_a)->next == NULL)
		return ;
	temp = *stack_a;
	while (temp->next != NULL)
		temp = temp->next;
	new = ft_lst_new(temp->content);
	temp = *stack_a;
	while (temp->next != NULL)
	{
		if ((temp->next)->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
		}
		else
			temp = temp->next;
	}
	ft_lst_add_back(&new, *stack_a);
	*stack_a = new;
}

void	ft_rrb_prem(t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*new;

	if ((*stack_b)->next == NULL)
		return ;
	temp = *stack_b;
	while (temp->next != NULL)
		temp = temp->next;
	new = ft_lst_new(temp->content);
	temp = *stack_b;
	while (temp->next != NULL)
	{
		if ((temp->next)->next == NULL)
		{
			free(temp->next);
			temp->next = NULL;
		}
		else
			temp = temp->next;
	}
	ft_lst_add_back(&new, *stack_b);
	*stack_b = new;
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra_prem(stack_a);
	ft_rrb_prem(stack_b);
	write(1, "rrr\n", 4);
}

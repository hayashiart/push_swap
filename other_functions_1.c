/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:05:38 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:46:22 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_if_sorted(int argc, t_stack **stack)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	i = 0;
	while (temp)
	{
		if (temp->next != NULL && temp->content < temp->next->content)
		{
			temp = temp->next;
			i++;
		}
		else if (temp->next == NULL)
		{
			i++;
			if (i == argc)
				return (1);
		}
		else
			break ;
	}
	return (0);
}

void	ft_push_smallest_a_help(t_stack **stack_a, int i, int n)
{
	if (n < 3)
	{
		i = 0;
		while (i < n)
		{
			ft_ra(stack_a);
			i++;
		}
	}
	else
	{
		while (i >= n)
		{
			ft_rra(stack_a);
			i--;
		}
	}
}

void	ft_push_smallest_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		x;
	int		n;
	t_stack	*temp;

	i = 0;
	n = 0;
	temp = *stack_a;
	x = temp -> content;
	while (temp->next != NULL)
	{
		temp = temp->next;
		i++;
		if (x > temp->content)
		{
			n = i;
			x = temp->content;
		}
	}
	if (n != 0)
		ft_push_smallest_a_help(stack_a, i, n);
	ft_pb(stack_a, stack_b);
}

void	ft_swap_element(t_stack *elem1, t_stack *elem2)
{
	int	tmp;

	tmp = elem1->content;
	elem1->content = elem2->content;
	elem2->content = tmp;
}

void	ft_sort_copy(t_stack *copy, int size_stack)
{
	int		i;
	t_stack	*elem1;
	t_stack	*elem2;

	elem1 = copy;
	elem2 = copy->next;
	i = 0;
	while (i < size_stack - 1)
	{
		while (elem2 != NULL)
		{
			if (elem2->content < elem1->content)
			{
				ft_swap_element(elem1, elem2);
				elem2 = elem2->next;
			}
			else
			{
				elem2 = elem2->next;
			}
		}
		i++;
		elem1 = elem1->next;
		elem2 = elem1->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:07:51 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:07:53 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	nbr_become_pos(t_stack **stack_a, int size_stack)
{
	int			i;
	t_stack		*tmp;

	i = 0;
	tmp = *stack_a;
	while (i < size_stack)
	{
		tmp->content = tmp->pos;
		tmp = tmp->next;
		i++;
	}
}

void	attribute_order(t_stack **stack_a, t_stack **copy, int size_stack)
{
	int			i;
	t_stack		*cmp1;
	t_stack		*cmp2;

	i = 0;
	cmp1 = *stack_a;
	cmp2 = *copy;
	while (i < size_stack)
	{
		if (cmp2->content == cmp1->content)
		{
			cmp1->pos = i;
			i++;
			cmp2 = cmp2->next;
			cmp1 = *stack_a;
		}
		else
		{
			cmp1 = cmp1->next;
		}
	}
	nbr_become_pos(stack_a, size_stack);
}

void	ft_convert_stack(t_stack **stack_a, int size_stack)
{
	t_stack	*copy;

	copy = NULL;
	ft_lst_copy(stack_a, &copy);
	ft_sort_copy(copy, size_stack);
	attribute_order(stack_a, &copy, size_stack);
	ft_lst_free(&copy);
}

void	push_bit(t_stack **stack_a, t_stack **stack_b, int num_max_bit)
{
	int		i;
	int		nbr;
	int		size_stack;

	i = 0;
	size_stack = ft_lst_size(stack_a);
	while (i < size_stack)
	{
		nbr = (*stack_a)->content;
		if (((nbr >> num_max_bit) & 1) == 0)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a);
		i++;
	}
}

void	ft_radix(t_stack **stack_a, t_stack **stack_b)
{
	int	size_stack;
	int	num_max_bit;

	size_stack = ft_lst_size(stack_a);
	ft_convert_stack(stack_a, size_stack);
	num_max_bit = 0;
	while ((size_stack - 1) >> num_max_bit != 0)
	{
		push_bit(stack_a, stack_b, num_max_bit);
		while (*stack_b != NULL)
			ft_pa(stack_a, stack_b);
		num_max_bit++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:05:15 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:05:16 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_fill_list(int argc, char **input)
{
	int		i;
	t_stack	*head;
	t_stack	*temp;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		temp = ft_lst_new(ft_atol(input[i]));
		if (temp == NULL)
		{
			ft_lst_free(&head);
			break ;
		}
		ft_lst_add_back(&head, temp);
		i++;
	}
	ft_free_array(input);
	return (head);
}

t_stack	*ft_lst_new(long long content)
{
	t_stack	*head;

	if (content < -2147483648 || content > 2147483647)
	{
		head = NULL;
		return (head);
	}
	head = malloc(sizeof(t_stack));
	if (head == NULL)
		return (0);
	head->content = content;
	head->next = NULL;
	return (head);
}

void	ft_lst_add_back(t_stack **head, t_stack *new)
{
	t_stack	*current;

	if (*head == NULL)
		*head = new;
	else
	{
		current = *head;
		while (current -> next != NULL)
			current = current -> next;
		current -> next = new;
	}
}

void	ft_lst_copy(t_stack **input, t_stack **output)
{
	t_stack	*temp;
	t_stack	*current;

	if (*output != NULL)
		ft_lst_free(output);
	temp = *input;
	*output = ft_lst_new(temp -> content);
	current = *output;
	while (temp != NULL)
	{
		temp = temp -> next;
		if (temp == NULL)
			return ;
		current -> next = ft_lst_new(temp -> content);
		current = current -> next;
		if (temp -> next == NULL)
			break ;
	}
}

int	ft_lst_size(t_stack **stack)
{
	t_stack	*current;
	int		i;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		current = current -> next;
		i++;
	}
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:04:53 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:04:56 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lst_free(t_stack **alist)
{
	t_stack	*temp;

	temp = NULL;
	if (alist)
	{
		while (*alist)
		{
			temp = (*alist)->next;
			free(*alist);
			*alist = temp;
		}
		alist = NULL;
	}
}

void	ft_free_array(char **str)
{
	int	i;

	i = 0;
	while (str && str[i] != NULL)
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
}

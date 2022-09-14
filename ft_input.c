/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:05:04 by slin              #+#    #+#             */
/*   Updated: 2022/07/07 05:33:25 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int	ft_input(char **argv, char **input)
{
	char	**split;
	int		i;
	int		j;
	int		end;

	end = 0;
	i = 0;
	j = 0;
	while (argv[j] != NULL)
	{
		split = ft_split(argv[j], ' ');
		i = 0;
		while (split[i] != NULL)
		{
			input[end] = ft_strdup(split[i]);
			i++;
			end++;
		}
		ft_free_array(split);
		j++;
	}
	return (end);
}

int	ft_input_error(char **input)
{
	int					i;
	int					j;

	j = 1;
	while (input[j] != NULL)
	{
		i = 0;
		if ((ft_atol(input[j]) < -2147483648)
			|| (ft_atol(input[j]) > 2147483647)
			|| (ft_strlen(input[j]) > 11) || (ft_strlen(input[j]) == 0))
			return (1);
		if ((input[j][i] == '+' || input[j][i] == '-') &&
			(ft_isdigit(input[j][i + 1])))
			i++;
		while (input[j][i] != '\0')
		{
			if (!ft_isdigit(input[j][i]))
				return (1);
			i++;
		}
		if (ft_doubles(input) == 1)
			return (1);
		j++;
	}
	return (0);
}

int	ft_doubles(char **input)
{
	int	i;
	int	j;

	i = 1;
	while (input[i])
	{
		j = i + 1;
		while (input[j])
		{
			if (ft_atol(input[i]) == ft_atol(input[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

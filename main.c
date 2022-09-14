/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:05:30 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:05:31 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_empty_inputs(char **argv)
{
	int	i;

	i = 0;
	while (argv && argv[i])
	{
		if (ft_strlen(argv[i++]) == 0)
			return (write(2, "Error\n", 6), 1);
	}
	return (0);
}

int	ft_test(int argc, char **input, t_stack **list_a)
{
	if (ft_input_error(input) == 1)
	{
		write(2, "Error\n", 6);
		ft_free_array(input);
		return (1);
	}
	*list_a = ft_fill_list(argc, input);
	if (list_a == NULL)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*list_a;
	t_stack	*list_b;
	char	**input;
	int		i;

	list_a = NULL;
	list_b = NULL;
	if (argc < 2 || ft_check_empty_inputs(argv + 1))
		return (0);
	if (argv[1][0] == '\0' && argc == 1)
		return (0);
	input = ft_calloc(50000, sizeof(char **));
	argc = ft_input(argv, input);
	i = ft_test(argc, input, &list_a);
	if (i == 1)
		return (1);
	if (ft_if_sorted(argc, &list_a) == 1)
	{
		ft_lst_free(&list_a);
		return (0);
	}
	ft_sort(argc, &list_a, &list_b);
	ft_lst_free(&list_a);
	ft_lst_free(&list_b);
	return (0);
}

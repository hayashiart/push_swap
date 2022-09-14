/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:05:58 by slin              #+#    #+#             */
/*   Updated: 2022/04/19 23:05:59 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stddef.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				pos;
	struct s_stack	*next;
}					t_stack;

/* input functions */
t_stack	*ft_fill_list(int argc, char **input);
int		ft_input(char **argv, char **input);
int		ft_input_error(char **input);
int		ft_doubles(char **input);
/*list functions*/
t_stack	*ft_fill_list(int argc, char **input);
t_stack	*ft_lst_new(long long content);
void	ft_lst_add_back(t_stack **head, t_stack *new);
void	ft_lst_copy(t_stack **input, t_stack **output);
int		ft_lst_size(t_stack **list);
/*free functions*/
void	ft_lst_free(t_stack **alist);
void	ft_free_array(char **str);
/*actions functions*/
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack **stack_a);
void	ft_rrb(t_stack **stack_b);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack **stack_a);
void	ft_rb(t_stack **stack_b);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_sa(t_stack **stack_a);
void	ft_sb(t_stack **stack_b);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
/*sort functions*/
void	ft_sort(int argc, t_stack **stack_a, t_stack **stack_b);
void	ft_sort_five(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_four(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_three(t_stack **stack_a);
/*radix functions*/
void	ft_swap_element(t_stack *elem1, t_stack *elem2);
void	ft_radix(t_stack **stack_a, t_stack **stack_b);
/*other functions*/
int		ft_if_sorted(int argc, t_stack **stack);
void	ft_push_smallest_a(t_stack **stack_a, t_stack **stack_b);
int		ft_if_sorted(int argc, t_stack **stack);
void	ft_print_list(t_stack *list);
void	ft_sort_copy(t_stack *copy, int size_stack);

#endif

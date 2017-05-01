/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:19:36 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:19:37 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define FIRST_DEFENSE
#define SAFETY_NET

void			free_stacks(t_two_stacks *stacks)
{
	free_arr(stacks->stack_a);
	free_arr(stacks->stack_b);
	free_dyn_move_history(stacks->move_history);
	free(stacks);
}

t_two_stacks	*create_two_stacks(int capacity)
{
	t_two_stacks *ret;

	ret = malloc(sizeof(t_two_stacks));
	ret->stack_a = create_arr(capacity);
	ret->stack_b = create_arr(capacity);
	ret->move_history = create_dyn_move_history(8);
	return (ret);
}

t_two_stacks	*copy_stacks(t_two_stacks *stacks)
{
	t_two_stacks	*copy;
	int				old_cap;

	copy = malloc(sizeof(t_two_stacks));
	copy->stack_a = copy_arr(stacks->stack_a);
	copy->stack_b = copy_arr(stacks->stack_b);
	old_cap = stacks->move_history->capacity;
	copy->move_history = create_dyn_move_history(old_cap);
	return (copy);
}

t_two_stacks	*initialize_two_stacks(char **integers, int number_of_integers)
{
	int				i;
	int				curr_int;
	t_two_stacks	*ret;

	ret = create_two_stacks(number_of_integers);
	i = 0;
	while (i < number_of_integers)
	{
		curr_int = ft_atoi(integers[i]);
		unshift((ret->stack_a), curr_int);
		i++;
	}
	return (ret);
}

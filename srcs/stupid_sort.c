/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:18:48 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:18:49 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	three_sort(t_two_stacks *stacks)
{
	int	max_i;
	int	top;
	int	middle;

	max_i = max_idx(stacks->stack_a);
	if (max_i == 2)
		execute_move(stacks, RA);
	else if (max_i == 1)
		execute_move(stacks, RRA);
	top = value_for(stacks->stack_a, 2);
	middle = value_for(stacks->stack_a, 1);
	if (top > middle)
		execute_move(stacks, SA);
}

void	two_sort(t_two_stacks *stacks, int is_stack_a)
{
	int		top_of_stack;
	int		bottom_of_stack;
	t_arr	*stack;
	t_move	move;

	if (is_stack_a)
	{
		stack = stacks->stack_a;
		move = SA;
	}
	else
	{
		stack = stacks->stack_b;
		move = SB;
	}
	top_of_stack = value_for(stack, 1);
	bottom_of_stack = value_for(stack, 0);
	if (((top_of_stack > bottom_of_stack) && is_stack_a) ||
		((top_of_stack < bottom_of_stack) && !is_stack_a))
	{
		execute_move(stacks, move);
	}
}

void	quick_sort(t_two_stacks *stacks)
{
	push_two_mins(stacks);
	two_sort(stacks, 0);
	if (stacks->stack_a->length == 3)
		three_sort(stacks);
	else
		two_sort(stacks, 1);
	fill_a_sorted(stacks);
}

void	stupid_sort(t_two_stacks *stacks)
{
	if (stacks->stack_a->length == 2)
		two_sort(stacks, 1);
	else if (stacks->stack_a->length == 3)
		three_sort(stacks);
	else
	{
		quick_sort(stacks);
	}
}

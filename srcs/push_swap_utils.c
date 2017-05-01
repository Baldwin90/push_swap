/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:35 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:36 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		b_idx_of_needed_top(t_two_stacks *stacks, int num_to_place)
{
	int		i;
	int		max_lesser_num_idx;
	int		max_idx;
	t_arr	*stack_b;

	stack_b = stacks->stack_b;
	i = -1;
	max_idx = -1;
	max_lesser_num_idx = -1;
	while (++i < stack_b->length)
	{
		if (max_idx == -1 || \
			value_for(stack_b, i) > value_for(stack_b, max_idx))
			max_idx = i;
		if (value_for(stack_b, i) < num_to_place)
			if (max_lesser_num_idx == -1 || \
				value_for(stack_b, max_lesser_num_idx) < value_for(stack_b, i))
				max_lesser_num_idx = i;
	}
	if (max_idx == max_lesser_num_idx || max_lesser_num_idx == -1)
		return (max_idx);
	else
		return (max_lesser_num_idx);
}

void	rotate_sort(t_two_stacks *stacks)
{
	if (!is_sorted(stacks))
	{
		if (stacks->stack_a->length < 6)
		{
			stupid_sort(stacks);
		}
		else
		{
			prepare_b_for_algo(stacks);
			fill_b_sorted(stacks);
			prepare_b_for_emptying(stacks);
			fill_a_sorted(stacks);
		}
	}
}

void	prepare_b_for_algo(t_two_stacks *stacks)
{
	a_to_b(stacks);
	a_to_b(stacks);
}

void	fill_b_sorted(t_two_stacks *stacks)
{
	while (stacks->stack_a->length != 0)
	{
		find_and_execute_optimal_move(stacks);
	}
}

void	prepare_b_for_emptying(t_two_stacks *stacks)
{
	int upshifts_required;
	int downshifts_required;
	int i;

	upshifts_required = b_upshifts_required(stacks, 0, 1);
	downshifts_required = b_downshifts_required(stacks, 0, 1);
	i = 0;
	if (downshifts_required < upshifts_required)
	{
		execute_move_loop(stacks, 0, downshifts_required, RRB);
	}
	else
	{
		execute_move_loop(stacks, 0, upshifts_required, RB);
	}
}

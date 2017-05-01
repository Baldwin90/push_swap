/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_four.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:12 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:13 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	execute_move_loop(t_two_stacks *stacks, int start_idx, \
	int limit, t_move move)
{
	int	i;

	i = start_idx;
	while (i < limit)
	{
		execute_move(stacks, move);
		i++;
	}
}

void	fill_a_sorted(t_two_stacks *stacks)
{
	execute_move_loop(stacks, 0, stacks->stack_b->length, PA);
}

void	execute_move_sequence(t_two_stacks *stacks, \
	t_dyn_move_history *move_sequence)
{
	int	i;

	i = 0;
	while (i < move_sequence->length)
	{
		execute_move(stacks, move_sequence->internal_arr[i]);
		i++;
	}
}

int		b_upshifts_required(t_two_stacks *stacks, int num_to_place, \
	int find_max)
{
	int	idx_to_shift;

	if (find_max)
	{
		idx_to_shift = find_max_idx(stacks->stack_b);
	}
	else
	{
		idx_to_shift = b_idx_of_needed_top(stacks, num_to_place);
	}
	return (stacks->stack_b->length - 1 - idx_to_shift);
}

int		b_downshifts_required(t_two_stacks *stacks, int num_to_place, \
	int find_max)
{
	int	idx_to_shift;
	int	last_idx;

	last_idx = stacks->stack_b->length - 1;
	if (find_max)
	{
		idx_to_shift = find_max_idx(stacks->stack_b);
	}
	else
	{
		idx_to_shift = b_idx_of_needed_top(stacks, num_to_place);
	}
	return (last_idx == idx_to_shift ? 0 : idx_to_shift + 1);
}

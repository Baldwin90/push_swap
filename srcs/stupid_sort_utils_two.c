/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort_utils_two.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:19:25 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:19:27 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define A stacks, to_push_idx1, to_push_idx2, stacks->stack_a->length - 1

void	push_closest_min(t_two_stacks *stacks, int min_idx_1, int min_idx_2, \
	int last_idx)
{
	int	upshifts_required_1;
	int	downshifts_required_1;
	int	upshifts_required_2;
	int	downshifts_required_2;
	int	times;

	upshifts_required_1 = last_idx - min_idx_1;
	upshifts_required_2 = last_idx - min_idx_2;
	downshifts_required_1 = last_idx == min_idx_1 ? 0 : min_idx_1 + 1;
	downshifts_required_2 = last_idx == min_idx_2 ? 0 : min_idx_2 + 1;
	times = min(downshifts_required_1, downshifts_required_2);
	if (times <= min(upshifts_required_1, upshifts_required_2))
	{
		execute_move_loop(stacks, 0, times, RRA);
	}
	else
	{
		times = min(upshifts_required_1, upshifts_required_2);
		execute_move_loop(stacks, 0, times, RA);
	}
	execute_move(stacks, PB);
}

void	push_curr_min(t_two_stacks *stacks, int min_idx, int last_idx)
{
	int	upshifts_required;
	int	downshifts_required;

	upshifts_required = last_idx - min_idx;
	downshifts_required = last_idx == min_idx ? 0 : min_idx + 1;
	if (upshifts_required < downshifts_required)
		execute_move_loop(stacks, 0, upshifts_required, RA);
	else
		execute_move_loop(stacks, 0, downshifts_required, RRA);
	execute_move(stacks, PB);
}

void	push_two_mins(t_two_stacks *stacks)
{
	int	to_push_idx1;
	int	to_push_idx2;

	to_push_idx1 = min_idx(stacks->stack_a);
	to_push_idx2 = second_min_idx(stacks->stack_a, to_push_idx1);
	push_closest_min(A);
	to_push_idx1 = min_idx(stacks->stack_a);
	push_curr_min(stacks, to_push_idx1, stacks->stack_a->length - 1);
}

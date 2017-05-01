/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:19 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:20 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define A writeoffs_a, deductable_b_shifts, solo_b_shifts, direction
#define TWENTY_SIX 	t_move_seqs *move_seqs;t_dyn_move_history *move_seq;

t_move_seqs			*optimize_neutral_sequence(int upshifts_required, \
	int downshifts_required)
{
	TWENTY_SIX;
	move_seqs = create_move_seqs(2);
	if (downshifts_required < upshifts_required)
	{
		move_seq = make_move_sequence(0, downshifts_required, RRB);
		push_move_history(&move_seq, PB);
		push_move_seq(&move_seqs, move_seq);
	}
	else if (upshifts_required < downshifts_required || upshifts_required == 0)
	{
		move_seq = make_move_sequence(0, upshifts_required, RB);
		push_move_history(&move_seq, PB);
		push_move_seq(&move_seqs, move_seq);
	}
	else
	{
		move_seq = make_move_sequence(0, downshifts_required, RRB);
		push_move_history(&move_seq, PB);
		push_move_seq(&move_seqs, move_seq);
		move_seq = make_move_sequence(0, upshifts_required, RB);
		push_move_history(&move_seq, PB);
		push_move_seq(&move_seqs, move_seq);
	}
	return (move_seqs);
}

t_dyn_move_history	*opposite_shift_seq(int writeoffs_a, int opposite_shifts, \
	t_direction_shifted direction)
{
	t_dyn_move_history	*move_seq;

	move_seq = make_move_sequence(0, writeoffs_a, direction == UP ? RA : RRA);
	write_move_seq(&move_seq, 0, opposite_shifts, direction == UP ? RRB : RB);
	push_move_history(&move_seq, PB);
	return (move_seq);
}

t_dyn_move_history	*double_shift_seq(int writeoffs_a, \
	int deductable_b_shifts, int solo_b_shifts, t_direction_shifted direction)
{
	t_dyn_move_history	*move_seq;
	int					double_shifts;
	int					solo_a_shifts;

	double_shifts = deductable_b_shifts - solo_b_shifts;
	solo_a_shifts = writeoffs_a - double_shifts;
	move_seq = make_move_sequence(0, double_shifts, direction == UP ? RR : RRR);
	write_move_seq(&move_seq, 0, solo_b_shifts, direction == UP ? RB : RRB);
	write_move_seq(&move_seq, 0, solo_a_shifts, direction == UP ? RA : RRA);
	push_move_history(&move_seq, PB);
	return (move_seq);
}

t_move_seqs			*optimize_seq(int deductable_b_shifts, int writeoffs_a, \
	int opposite_shifts, t_direction_shifted direction)
{
	int					solo_b_shifts;

	TWENTY_SIX;
	move_seqs = create_move_seqs(2);
	solo_b_shifts = deductable_b_shifts - writeoffs_a;
	if (solo_b_shifts < 0)
		solo_b_shifts = 0;
	if (solo_b_shifts > opposite_shifts)
	{
		move_seq = opposite_shift_seq(writeoffs_a, opposite_shifts, direction);
		push_move_seq(&move_seqs, move_seq);
	}
	else if (solo_b_shifts < opposite_shifts)
	{
		move_seq = double_shift_seq(A);
		push_move_seq(&move_seqs, move_seq);
	}
	else
	{
		move_seq = opposite_shift_seq(writeoffs_a, opposite_shifts, direction);
		push_move_seq(&move_seqs, move_seq);
		move_seq = double_shift_seq(A);
		push_move_seq(&move_seqs, move_seq);
	}
	return (move_seqs);
}

void				write_move_seq(t_dyn_move_history **move_seq, \
	int start_idx, int limit, t_move move)
{
	int	i;

	i = start_idx;
	while (i < limit)
	{
		push_move_history(move_seq, move);
		i++;
	}
}

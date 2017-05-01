/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_util_three.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:24 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:25 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define A upshifts_required, times_a_rotated, downshifts_required, direction
#define B downshifts_required, times_a_rotated, upshifts_required, direction
#define C upshifts_required, downshifts_required
#define D stacks->stack_a, (stacks->stack_a->length - 1 - i)

t_dyn_move_history	*make_move_sequence(int start_idx, int limit, t_move move)
{
	int					i;
	t_dyn_move_history	*sequence;

	sequence = create_dyn_move_history(8);
	i = start_idx;
	while (i < limit)
	{
		push_move_history(&sequence, move);
		i++;
	}
	return (sequence);
}

t_move_seqs			*optimize_move_sequence(t_two_stacks *stacks, \
	int num_to_place, int times_a_rotated, t_direction_shifted direction)
{
	int			upshifts_required;
	int			downshifts_required;
	t_move_seqs	*move_seqs;

	upshifts_required = b_upshifts_required(stacks, num_to_place, 0);
	downshifts_required = b_downshifts_required(stacks, num_to_place, 0);
	if (direction == UP)
		move_seqs = optimize_seq(A);
	else if (direction == DOWN)
		move_seqs = optimize_seq(B);
	else
		move_seqs = optimize_neutral_sequence(C);
	return (move_seqs);
}

t_move_seqs			*compare_sequences(t_move_seqs *seq1, t_move_seqs *seq2)
{
	int len1;
	int len2;

	len1 = seq1->internal_arr[0]->length;
	len2 = seq2->internal_arr[0]->length;
	if (len1 < len2)
	{
		free_all_of_move_seqs(seq2);
		return (seq1);
	}
	else if (len2 < len1)
	{
		free_all_of_move_seqs(seq1);
		return (seq2);
	}
	else
	{
		concat_and_free(&seq1, seq2);
		return (seq1);
	}
}

t_dyn_move_history	*find_optimal_seq(t_two_stacks *stacks, \
	t_move_seqs *equal_seqs)
{
	t_dyn_move_history	*optimal_seq;
	int					i;
	t_two_stacks		*dup;
	int					max_tie;

	max_tie = moves_in_tie_threshold(0);
	if (equal_seqs->length == 1 ||
		equal_seqs->internal_arr[0]->length < max_tie)
		return (copy_move_seq(equal_seqs->internal_arr[0]));
	i = -1;
	while (++i < equal_seqs->length)
	{
		dup = copy_stacks(stacks);
		execute_move_sequence(dup, equal_seqs->internal_arr[i]);
		fill_b_sorted(dup);
		if (i == 0)
			optimal_seq = copy_move_seq(dup->move_history);
		else
		{
			if (dup->move_history->length < optimal_seq->length)
				optimal_seq = copy_move_seq(dup->move_history);
		}
		free_stacks(dup);
	}
	return (optimal_seq);
}

void				find_and_execute_optimal_move(t_two_stacks *stacks)
{
	t_move_seqs			*best_seqs;
	int					i;
	int					rotated_a_num;
	t_move_seqs			*move_seqs;
	t_dyn_move_history	*optimal_seq;

	i = 0;
	best_seqs = optimize_move_sequence(stacks, \
		value_for(stacks->stack_a, stacks->stack_a->length - 1), 0, NEUTRAL);
	while (++i < stacks->stack_a->length)
	{
		if ((i + 1) >= (best_seqs->internal_arr[0])->length)
			break ;
		rotated_a_num = value_for(D);
		move_seqs = optimize_move_sequence(stacks, rotated_a_num, i, UP);
		best_seqs = compare_sequences(best_seqs, move_seqs);
		rotated_a_num = value_for(stacks->stack_a, (i - 1));
		move_seqs = optimize_move_sequence(stacks, rotated_a_num, i, DOWN);
		best_seqs = compare_sequences(best_seqs, move_seqs);
	}
	optimal_seq = find_optimal_seq(stacks, best_seqs);
	free_all_of_move_seqs(best_seqs);
	execute_move_sequence(stacks, optimal_seq);
	free_dyn_move_history(optimal_seq);
}

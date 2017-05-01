/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 22:19:31 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 22:19:33 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define NORMINETTE_HAS_FINAL_SAY static int threshold = 15;

typedef	struct		s_arr
{
	int	*internal_arr;
	int	length;
	int	first_idx;
	int	capacity;
}					t_arr;

typedef	enum		e_move
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}					t_move;

typedef	struct		s_dyn_move_history
{
	t_move	*internal_arr;
	int		length;
	int		capacity;
}					t_dyn_move_history;

typedef	struct		s_move_seqs
{
	t_dyn_move_history	**internal_arr;
	int					length;
	int					capacity;
}					t_move_seqs;

typedef	struct		s_two_stacks
{
	t_arr				*stack_a;
	t_arr				*stack_b;
	t_dyn_move_history	*move_history;
}					t_two_stacks;

typedef	enum		e_direction_shifted
{
	NEUTRAL,
	UP,
	DOWN
}					t_direction_shifted;

typedef	struct		s_str_arr
{
	int		length;
	char	**internal_arr;
}					t_str_arr;

t_arr				*create_arr(int capacity);
void				free_arr(t_arr *arr);
void				push(t_arr *arr, int value);
int					internal_first_free_idx(t_arr *arr);
int					pop(t_arr *arr);
void				unshift(t_arr *arr, int value);
int					shift(t_arr *arr);
int					internal_idx(t_arr *arr, int external_idx);
int					value_for(t_arr *arr, int external_idx);
int					idx_wrapped_around(t_arr *arr, int idx);
int					find_max_idx(t_arr *stack);
t_dyn_move_history	*create_dyn_move_history(int capacity);
void				free_dyn_move_history(t_dyn_move_history *move_history);
t_move				pop_move_history(t_dyn_move_history *arr);
void				resize_move_history(t_dyn_move_history **move_history);
void				push_move_history(t_dyn_move_history **move_history, \
	t_move value);
void				free_stacks(t_two_stacks *stacks);
int					overflows_int(char *nbr_str);
t_two_stacks		*create_two_stacks(int capacity);
t_two_stacks		*initialize_two_stacks(char **integers, \
	int number_of_integers);
t_two_stacks		*initialize_two_stacks(char **integers, \
	int number_of_integers);
void				swap_a(t_two_stacks *stacks, int swapped_both);
void				swap_b(t_two_stacks *stacks, int swapped_both);
void				swap_both(t_two_stacks *stacks);
void				a_to_b(t_two_stacks *stacks);
void				b_to_a(t_two_stacks *stacks);
void				rotate_a_up(t_two_stacks *stacks, int rotated_both);
void				rotate_b_up(t_two_stacks *stacks, int rotated_both);
void				rotate_both_up(t_two_stacks *stacks);
void				rotate_b_down(t_two_stacks *stacks, int rotated_both);
void				rotate_a_down(t_two_stacks *stacks, int rotated_both);
void				rotate_both_down(t_two_stacks *stacks);
void				print_move(t_move curr_move);
void				display_move_history(t_two_stacks *stacks);
void				prepare_b_for_algo(t_two_stacks *stacks);
void				find_and_execute_optimal_move(t_two_stacks *stacks);
void				fill_b_sorted(t_two_stacks *stacks);
void				prepare_b_for_emptying(t_two_stacks *stacks);
void				fill_a_sorted(t_two_stacks *stacks);
void				rotate_sort(t_two_stacks *stacks);
void				execute_move_sequence(t_two_stacks *stacks, \
	t_dyn_move_history *move_sequence);
int					b_upshifts_required(t_two_stacks *stacks, \
	int num_to_place, int find_max);
int					b_downshifts_required(t_two_stacks *stacks, \
	int num_to_place, int find_max);
int					b_idx_of_needed_top(t_two_stacks *stacks, int num_to_place);
void				execute_move(t_two_stacks *stacks, t_move curr_move);
void				execute_move_loop(t_two_stacks *stacks, int start_idx, \
	int limit, t_move move);
int					is_empty(t_arr *stack);
int					is_sorted(t_two_stacks *stacks);
int					has_duplicates(t_two_stacks *stacks);
void				print_error(int err_nbr, t_two_stacks *stacks, \
	t_str_arr *str_arr_container);
int					execute_command(char *cmd, t_two_stacks *stacks);
int					validate_args(char *nbr_strs[], int len);
int					max_idx(t_arr *stack);
int					moves_in_tie_threshold(int do_decrement);
t_move_seqs			*create_move_seqs(int capacity);
void				free_move_seqs(t_move_seqs *move_seqs);
void				free_all_of_move_seqs(t_move_seqs *move_seqs);
void				resize_move_seqs(t_move_seqs **move_seqs);
void				push_move_seq(t_move_seqs **move_seqs, \
	t_dyn_move_history *move_seq);
void				concat_and_free(t_move_seqs **concat_to, \
	t_move_seqs *add_on);
t_move_seqs			*compare_sequences(t_move_seqs *seq1, t_move_seqs *seq2);
t_move_seqs			*optimize_move_sequence(t_two_stacks *stacks, \
	int num_to_place, int times_a_rotated, t_direction_shifted direction);
t_move_seqs			*optimize_neutral_sequence(int upshifts_required, \
	int downshifts_required);
t_move_seqs			*optimize_seq(int deductable_b_shifts, int writeoffs_a, \
	int opposite_shifts, t_direction_shifted direction);
void				write_move_seq(t_dyn_move_history **move_seq, \
	int start_idx, int limit, t_move move);
t_dyn_move_history	*make_move_sequence(int start_idx, int limit, t_move move);
t_dyn_move_history	*opposite_shift_seq(int writeoffs_a, int opposite_shifts, \
	t_direction_shifted direction);
t_dyn_move_history	*double_shift_seq(int writeoffs_a, \
	int deductable_b_shifts, int solo_b_shifts, \
	t_direction_shifted direction);
t_dyn_move_history	*find_optimal_seq(t_two_stacks *stacks, \
	t_move_seqs *equal_seqs);
t_arr				*copy_arr(t_arr *orig);
void				copy_values(t_dyn_move_history *new_seq, \
	t_dyn_move_history *old_seq);
t_dyn_move_history	*copy_move_seq(t_dyn_move_history *orig);
t_two_stacks		*copy_stacks(t_two_stacks *stacks);
t_str_arr			*ft_split_whitespaces(char *sen);
char				*get_word(char *sen, int first_ltr_idx);
int					get_first_letter_idxs(char *sen, int *first_ltr_idxs);
void				free_str_arr(t_str_arr *arr);
void				push_str_arr(t_str_arr *arr, char *new_str);
t_str_arr			*create_str_arr(int capacity);
int					is_first_letter_of_word(char *sen, int i);
int					ft_is_whitespace(char c);
char				**prepare_str_arr(int argc, char **argv, \
	t_str_arr **str_arr_container, int *str_arr_len);
void				stupid_sort(t_two_stacks *stacks);
void				push_two_mins(t_two_stacks *stacks);
int					min(int a, int b);
int					second_min_idx(t_arr *stack, int min_idx);
int					min_idx(t_arr *stack);
void				display_stacks(t_two_stacks *stacks);

#endif

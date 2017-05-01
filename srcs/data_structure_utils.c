/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_structure_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:16:17 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:16:18 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define T_D_M_H t_dyn_move_history

T_D_M_H	*copy_move_seq(T_D_M_H *orig)
{
	T_D_M_H *copy;

	copy = create_dyn_move_history(orig->capacity);
	copy->length = orig->length;
	copy_values(copy, orig);
	return (copy);
}

void	copy_values(T_D_M_H *new_seq, T_D_M_H *old_seq)
{
	int i;

	i = 0;
	while (i < old_seq->length)
	{
		new_seq->internal_arr[i] = old_seq->internal_arr[i];
		i++;
	}
}

void	concat_and_free(t_move_seqs **concat_to, t_move_seqs *add_on)
{
	int	i;

	i = 0;
	while (i < add_on->length)
	{
		push_move_seq(concat_to, add_on->internal_arr[i]);
		i++;
	}
	free_move_seqs(add_on);
}

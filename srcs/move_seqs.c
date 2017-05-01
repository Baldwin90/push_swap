/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_seqs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:16:50 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:16:51 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_move_seqs	*create_move_seqs(int capacity)
{
	t_move_seqs *ret;

	ret = malloc(sizeof(t_move_seqs));
	ret->internal_arr = malloc(sizeof(t_dyn_move_history*) * capacity);
	ret->length = 0;
	ret->capacity = capacity;
	return (ret);
}

void		free_move_seqs(t_move_seqs *move_seqs)
{
	free(move_seqs->internal_arr);
	free(move_seqs);
}

void		free_all_of_move_seqs(t_move_seqs *move_seqs)
{
	int i;

	i = 0;
	while (i < move_seqs->length)
	{
		free_dyn_move_history((move_seqs->internal_arr)[i]);
		i++;
	}
	free_move_seqs(move_seqs);
}

void		resize_move_seqs(t_move_seqs **move_seqs)
{
	t_move_seqs	*resized_move_seqs;
	int			i;

	resized_move_seqs = create_move_seqs((*move_seqs)->capacity * 2);
	resized_move_seqs->length = (*move_seqs)->length;
	i = 0;
	while (i < (*move_seqs)->length)
	{
		resized_move_seqs->internal_arr[i] = ((*move_seqs)->internal_arr)[i];
		i++;
	}
	free_move_seqs(*move_seqs);
	*move_seqs = resized_move_seqs;
}

void		push_move_seq(t_move_seqs **move_seqs, t_dyn_move_history *move_seq)
{
	int new_length;

	new_length = (*move_seqs)->length + 1;
	if (new_length > (*move_seqs)->capacity)
	{
		resize_move_seqs(move_seqs);
	}
	((*move_seqs)->internal_arr)[(*move_seqs)->length] = move_seq;
	(*move_seqs)->length = new_length;
}

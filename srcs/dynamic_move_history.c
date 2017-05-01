/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_move_history.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:16:40 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:16:44 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define T_D_M_H t_dyn_move_history

T_D_M_H	*create_dyn_move_history(int capacity)
{
	T_D_M_H	*ret;

	ret = malloc(sizeof(T_D_M_H));
	ret->internal_arr = malloc(sizeof(t_move) * capacity);
	ret->length = 0;
	ret->capacity = capacity;
	return (ret);
}

void	free_dyn_move_history(T_D_M_H *move_history)
{
	free(move_history->internal_arr);
	free(move_history);
}

t_move	pop_move_history(T_D_M_H *arr)
{
	t_move	popped;

	(arr->length)--;
	popped = (arr->internal_arr)[arr->length];
	return (popped);
}

void	resize_move_history(T_D_M_H **move_history)
{
	T_D_M_H	*resized_moves_arr;

	resized_moves_arr = create_dyn_move_history((*move_history)->capacity * 2);
	resized_moves_arr->length = (*move_history)->length;
	copy_values(resized_moves_arr, *move_history);
	free_dyn_move_history(*move_history);
	*move_history = resized_moves_arr;
}

void	push_move_history(T_D_M_H **move_history, t_move value)
{
	int	new_length;

	new_length = (*move_history)->length + 1;
	if (new_length > (*move_history)->capacity)
	{
		resize_move_history(move_history);
	}
	((*move_history)->internal_arr)[(*move_history)->length] = value;
	(*move_history)->length = new_length;
}

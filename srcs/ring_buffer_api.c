/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_buffer_api.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:50 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:51 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		pop(t_arr *arr)
{
	int	popped;
	int	last_occupied_idx;

	(arr->length)--;
	last_occupied_idx = internal_first_free_idx(arr);
	popped = (arr->internal_arr)[last_occupied_idx];
	return (popped);
}

void	push(t_arr *arr, int value)
{
	int	first_free_idx;

	first_free_idx = internal_first_free_idx(arr);
	(arr->internal_arr)[first_free_idx] = value;
	(arr->length)++;
}

void	unshift(t_arr *arr, int value)
{
	(arr->length)++;
	(arr->first_idx)--;
	if (arr->first_idx == -1)
	{
		arr->first_idx = (arr->capacity) - 1;
	}
	(arr->internal_arr)[arr->first_idx] = value;
}

int		shift(t_arr *arr)
{
	int		shifted;

	shifted = (arr->internal_arr)[arr->first_idx];
	arr->first_idx = idx_wrapped_around(arr, (arr->first_idx + 1));
	(arr->length)--;
	return (shifted);
}

int		value_for(t_arr *arr, int external_idx)
{
	int idx;

	idx = internal_idx(arr, external_idx);
	return ((arr->internal_arr)[idx]);
}

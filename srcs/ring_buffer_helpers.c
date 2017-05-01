/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_buffer_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:18:20 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:18:21 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	internal_first_free_idx(t_arr *arr)
{
	int	external_idx;

	external_idx = arr->first_idx + arr->length;
	return (idx_wrapped_around(arr, external_idx));
}

int	internal_idx(t_arr *arr, int external_idx)
{
	return (idx_wrapped_around(arr, arr->first_idx + external_idx));
}

int	idx_wrapped_around(t_arr *arr, int idx)
{
	return (idx % arr->capacity);
}

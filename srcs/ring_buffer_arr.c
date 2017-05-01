/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring_buffer_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:55 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:56 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_arr	*create_arr(int capacity)
{
	t_arr	*ret;

	ret = malloc(sizeof(t_arr));
	ret->internal_arr = malloc(sizeof(int) * capacity);
	ret->length = 0;
	ret->capacity = capacity;
	ret->first_idx = 0;
	return (ret);
}

t_arr	*copy_arr(t_arr *orig)
{
	t_arr	*copy;
	int		i;
	int		curr_val;

	i = 0;
	copy = create_arr(orig->capacity);
	while (i < orig->length)
	{
		curr_val = value_for(orig, i);
		push(copy, curr_val);
		i++;
	}
	return (copy);
}

void	free_arr(t_arr *arr)
{
	free(arr->internal_arr);
	free(arr);
}

int		find_max_idx(t_arr *stack)
{
	int	i;
	int	max_idx;
	int	curr_num;

	i = 0;
	max_idx = i;
	while (++i < stack->length)
	{
		curr_num = value_for(stack, i);
		if (curr_num > value_for(stack, max_idx))
			max_idx = i;
	}
	return (max_idx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stupid_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:19:17 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:19:19 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	max_idx(t_arr *stack)
{
	int	max;
	int	max_idx;
	int	i;
	int	curr_val;

	i = 0;
	max_idx = i;
	max = value_for(stack, i);
	while (++i < stack->length)
	{
		curr_val = value_for(stack, i);
		if (curr_val > max)
		{
			max = curr_val;
			max_idx = i;
		}
	}
	return (max_idx);
}

int	second_max_idx(t_arr *stack, int max_idx)
{
	int	second_max;
	int	second_max_idx;
	int	i;
	int	curr_val;

	i = max_idx == 0 ? 1 : 0;
	second_max_idx = i;
	second_max_idx = value_for(stack, i);
	while (++i < stack->length)
	{
		if (i == max_idx)
			continue;
		curr_val = value_for(stack, i);
		if (curr_val > second_max)
		{
			second_max = curr_val;
			second_max_idx = i;
		}
	}
	return (second_max_idx);
}

int	min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	min_idx(t_arr *stack)
{
	int	min;
	int	min_idx;
	int	i;
	int	curr_val;

	i = 0;
	min_idx = i;
	min = value_for(stack, i);
	while (++i < stack->length)
	{
		curr_val = value_for(stack, i);
		if (curr_val < min)
		{
			min = curr_val;
			min_idx = i;
		}
	}
	return (min_idx);
}

int	second_min_idx(t_arr *stack, int min_idx)
{
	int	second_min;
	int	second_min_idx;
	int	i;
	int	curr_val;

	i = min_idx == 0 ? 1 : 0;
	second_min_idx = i;
	second_min = value_for(stack, i);
	while (++i < stack->length)
	{
		if (i == min_idx)
			continue;
		curr_val = value_for(stack, i);
		if (curr_val < second_min)
		{
			second_min = curr_val;
			second_min_idx = i;
		}
	}
	return (second_min_idx);
}

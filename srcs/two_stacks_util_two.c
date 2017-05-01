/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_util_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:19:51 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:19:52 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	a_to_b(t_two_stacks *stacks)
{
	int popped;

	push_move_history(&(stacks->move_history), PB);
	if (stacks->stack_a->length > 0)
	{
		popped = pop(stacks->stack_a);
		push(stacks->stack_b, popped);
	}
}

void	b_to_a(t_two_stacks *stacks)
{
	int popped;

	push_move_history(&(stacks->move_history), PA);
	if (stacks->stack_b->length > 0)
	{
		popped = pop(stacks->stack_b);
		push(stacks->stack_a, popped);
	}
}

void	rotate_a_up(t_two_stacks *stacks, int rotated_both)
{
	int old_top;

	if (!rotated_both)
	{
		push_move_history(&(stacks->move_history), RA);
	}
	if (stacks->stack_a->length > 1)
	{
		old_top = pop(stacks->stack_a);
		unshift(stacks->stack_a, old_top);
	}
}

void	rotate_b_up(t_two_stacks *stacks, int rotated_both)
{
	int old_top;

	if (!rotated_both)
	{
		push_move_history(&(stacks->move_history), RB);
	}
	if (stacks->stack_b->length > 1)
	{
		old_top = pop(stacks->stack_b);
		unshift(stacks->stack_b, old_top);
	}
}

void	rotate_both_up(t_two_stacks *stacks)
{
	push_move_history(&(stacks->move_history), RR);
	rotate_a_up(stacks, 1);
	rotate_b_up(stacks, 1);
}

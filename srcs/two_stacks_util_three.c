/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_util_three.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:19:57 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:19:58 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	rotate_a_down(t_two_stacks *stacks, int rotated_both)
{
	int	new_top;

	if (!rotated_both)
	{
		push_move_history(&(stacks->move_history), RRA);
	}
	if (stacks->stack_a->length > 1)
	{
		new_top = shift(stacks->stack_a);
		push(stacks->stack_a, new_top);
	}
}

void	rotate_b_down(t_two_stacks *stacks, int rotated_both)
{
	int	new_top;

	if (!rotated_both)
	{
		push_move_history(&(stacks->move_history), RRB);
	}
	if (stacks->stack_b->length > 1)
	{
		new_top = shift(stacks->stack_b);
		push(stacks->stack_b, new_top);
	}
}

void	rotate_both_down(t_two_stacks *stacks)
{
	push_move_history(&(stacks->move_history), RRR);
	rotate_a_down(stacks, 1);
	rotate_b_down(stacks, 1);
}

void	print_move(t_move curr_move)
{
	if (curr_move == 0)
		ft_putstr("sa\n");
	else if (curr_move == 1)
		ft_putstr("sb\n");
	else if (curr_move == 2)
		ft_putstr("ss\n");
	else if (curr_move == 3)
		ft_putstr("pa\n");
	else if (curr_move == 4)
		ft_putstr("pb\n");
	else if (curr_move == 5)
		ft_putstr("ra\n");
	else if (curr_move == 6)
		ft_putstr("rb\n");
	else if (curr_move == 7)
		ft_putstr("rr\n");
	else if (curr_move == 8)
		ft_putstr("rra\n");
	else if (curr_move == 9)
		ft_putstr("rrb\n");
	else if (curr_move == 10)
		ft_putstr("rrr\n");
}

void	execute_move(t_two_stacks *stacks, t_move curr_move)
{
	if (curr_move == SA)
		swap_a(stacks, 0);
	else if (curr_move == SB)
		swap_b(stacks, 0);
	else if (curr_move == SS)
		swap_both(stacks);
	else if (curr_move == PA)
		b_to_a(stacks);
	else if (curr_move == PB)
		a_to_b(stacks);
	else if (curr_move == RA)
		rotate_a_up(stacks, 0);
	else if (curr_move == RB)
		rotate_b_up(stacks, 0);
	else if (curr_move == RR)
		rotate_both_up(stacks);
	else if (curr_move == RRA)
		rotate_a_down(stacks, 0);
	else if (curr_move == RRB)
		rotate_b_down(stacks, 0);
	else if (curr_move == RRR)
		rotate_both_down(stacks);
}

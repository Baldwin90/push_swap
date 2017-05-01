/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks_util_one.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:19:45 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:19:46 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	display_move_history(t_two_stacks *stacks)
{
	int		i;
	t_move	curr_move;

	i = 0;
	while (i < (stacks->move_history->length))
	{
		curr_move = stacks->move_history->internal_arr[i];
		print_move(curr_move);
		i++;
	}
}

void	display_stacks(t_two_stacks *stacks)
{
	int		i;
	t_arr	*stack_a;
	t_arr	*stack_b;
	int		curr_num;

	stack_a = stacks->stack_a;
	stack_b = stacks->stack_b;
	i = 0;
	ft_printf("Stack 1:");
	while (i < stack_a->length)
	{
		curr_num = value_for(stack_a, i);
		ft_printf(" %d", curr_num);
		i++;
	}
	ft_printf("\nStack 2:");
	i = 0;
	while (i < stack_b->length)
	{
		curr_num = value_for(stack_b, i);
		ft_printf(" %d", curr_num);
		i++;
	}
	ft_printf("\n");
}

void	swap_a(t_two_stacks *stacks, int swapped_both)
{
	int	prev_top;
	int	new_top;

	if (!swapped_both)
	{
		push_move_history(&(stacks->move_history), SA);
	}
	if (stacks->stack_a->length > 1)
	{
		prev_top = pop(stacks->stack_a);
		new_top = pop(stacks->stack_a);
		push(stacks->stack_a, prev_top);
		push(stacks->stack_a, new_top);
	}
}

void	swap_b(t_two_stacks *stacks, int swapped_both)
{
	int	prev_top;
	int	new_top;

	if (!swapped_both)
	{
		push_move_history(&(stacks->move_history), SB);
	}
	if (stacks->stack_b->length > 1)
	{
		prev_top = pop(stacks->stack_b);
		new_top = pop(stacks->stack_b);
		push(stacks->stack_b, prev_top);
		push(stacks->stack_b, new_top);
	}
}

void	swap_both(t_two_stacks *stacks)
{
	push_move_history(&(stacks->move_history), SS);
	swap_a(stacks, 1);
	swap_b(stacks, 1);
}

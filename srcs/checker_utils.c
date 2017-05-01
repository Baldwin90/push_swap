/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:16:10 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:16:11 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int		execute_command(char *cmd, t_two_stacks *stacks)
{
	if (!ft_strcmp(cmd, "sa"))
		swap_a(stacks, 0);
	else if (!ft_strcmp(cmd, "sb"))
		swap_b(stacks, 0);
	else if (!ft_strcmp(cmd, "ss"))
		swap_both(stacks);
	else if (!ft_strcmp(cmd, "pa"))
		b_to_a(stacks);
	else if (!ft_strcmp(cmd, "pb"))
		a_to_b(stacks);
	else if (!ft_strcmp(cmd, "ra"))
		rotate_a_up(stacks, 0);
	else if (!ft_strcmp(cmd, "rb"))
		rotate_b_up(stacks, 0);
	else if (!ft_strcmp(cmd, "rr"))
		rotate_both_up(stacks);
	else if (!ft_strcmp(cmd, "rra"))
		rotate_a_down(stacks, 0);
	else if (!ft_strcmp(cmd, "rrb"))
		rotate_b_down(stacks, 0);
	else if (!ft_strcmp(cmd, "rrr"))
		rotate_both_down(stacks);
	else
		return (0);
	return (1);
}

void	print_error(int err_nbr, t_two_stacks *stacks, t_str_arr *str_arr_tain)
{
	ft_putstr_fd("Error\n", 2);
	if (stacks)
		free_stacks(stacks);
	free_str_arr(str_arr_tain);
	exit(err_nbr);
}

int		is_empty(t_arr *stack)
{
	return (stack->length == 0);
}

int		is_sorted(t_two_stacks *stacks)
{
	int i;

	if (!is_empty(stacks->stack_b))
		return (0);
	i = 0;
	while (i < stacks->stack_a->length - 1)
	{
		if (value_for(stacks->stack_a, i) <
			value_for(stacks->stack_a, i + 1))
			return (0);
		i++;
	}
	return (1);
}

int		has_duplicates(t_two_stacks *stacks)
{
	int i;
	int j;
	int len;

	len = stacks->stack_a->length;
	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (value_for(stacks->stack_a, i) == \
				value_for(stacks->stack_a, j))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

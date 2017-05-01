/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:17:03 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:17:04 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define A char **str_arr;int str_arr_len;
#define B t_str_arr *str_arr_container;t_two_stacks *stacks;
#define C A;B;

int	main(int argc, char **argv)
{
	C;
	if (argc == 1)
		return (0);
	str_arr = prepare_str_arr(argc, argv, &str_arr_container, &str_arr_len);
	if (!validate_args(str_arr, str_arr_len))
		print_error(1, NULL, str_arr_container);
	stacks = initialize_two_stacks(str_arr, str_arr_len);
	if (has_duplicates(stacks))
		print_error(2, stacks, str_arr_container);
	rotate_sort(stacks);
	while (stacks->move_history->length > 5300)
	{
		moves_in_tie_threshold(1);
		free_stacks(stacks);
		stacks = initialize_two_stacks(str_arr, str_arr_len);
		rotate_sort(stacks);
	}
	display_move_history(stacks);
	free_str_arr(str_arr_container);
	free_stacks(stacks);
	return (0);
}

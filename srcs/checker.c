/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:16:03 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:16:05 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

#define CHECKER_V t_two_stacks	*stacks;char *buf;char ret;int str_arr_len;

int	main(int argc, char *argv[])
{
	char		**str_arr;
	t_str_arr	*str_arr_container;

	CHECKER_V;
	if (argc == 1)
		exit(1);
	str_arr = prepare_str_arr(argc, argv, &str_arr_container, &str_arr_len);
	if (!validate_args(str_arr, str_arr_len))
		print_error(1, NULL, str_arr_container);
	stacks = initialize_two_stacks(str_arr, str_arr_len);
	if (has_duplicates(stacks))
		print_error(2, stacks, str_arr_container);
	while ((ret = get_next_line(0, &buf) == 1))
	{
		if (!*buf)
			break ;
		if (!execute_command(buf, stacks))
			print_error(3, stacks, str_arr_container);
	}
	if (ret == -1)
		print_error(4, stacks, str_arr_container);
	is_sorted(stacks) ? ft_putstr("OK\n") : ft_putstr("KO\n");
	free_stacks(stacks);
	free_str_arr(str_arr_container);
	return (0);
}

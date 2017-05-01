/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:18:34 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:18:35 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

t_str_arr	*create_str_arr(int capacity)
{
	t_str_arr *ret;

	ret = malloc(sizeof(t_str_arr));
	ret->internal_arr = malloc(sizeof(char*) * (capacity));
	ret->length = 0;
	return (ret);
}

void		push_str_arr(t_str_arr *arr, char *new_str)
{
	arr->internal_arr[arr->length] = new_str;
	(arr->length)++;
}

void		free_str_arr(t_str_arr *arr)
{
	int	i;

	i = 0;
	while (i < arr->length)
	{
		free(arr->internal_arr[i]);
		i++;
	}
	free(arr->internal_arr);
	free(arr);
}

char		**prepare_str_arr(int argc, char **argv, \
	t_str_arr **str_arr_container, int *str_arr_len)
{
	char	**str_arr;

	*str_arr_container = ft_split_whitespaces(argv[1]);
	if ((*str_arr_container)->length <= 1)
	{
		str_arr = argv + 1;
		*str_arr_len = argc - 1;
	}
	else
	{
		str_arr = (*str_arr_container)->internal_arr;
		*str_arr_len = (*str_arr_container)->length;
	}
	return (str_arr);
}

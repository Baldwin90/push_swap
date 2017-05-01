/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:20:14 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:20:16 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	moves_in_tie_threshold(int do_decrement)
{
	NORMINETTE_HAS_FINAL_SAY;
	if (do_decrement)
		threshold -= 2;
	return (threshold);
}

int	validate_args(char *nbr_strs[], int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (nbr_strs[i][0] == '-' || nbr_strs[i][0] == '+')
		{
			if (!(ft_isnumeric(nbr_strs[i] + 1)))
			{
				return (FALSE);
			}
		}
		else if (!(ft_isnumeric(nbr_strs[i])))
		{
			return (FALSE);
		}
		if (overflows_int(nbr_strs[i]))
		{
			return (FALSE);
		}
		i += 1;
	}
	return (TRUE);
}

int	overflows_int(char *nbr_str)
{
	int	i;
	int	prev;
	int	cur;
	int	polarity;

	i = (nbr_str[0] == '-' || nbr_str[0] == '+' ? 1 : 0);
	if (!ft_isnumeric(&nbr_str[i]))
	{
		return (-1);
	}
	polarity = (nbr_str[0] == '-' ? -1 : 1);
	cur = 0;
	while (nbr_str[i] != '\0')
	{
		prev = cur;
		cur *= 10;
		cur += (nbr_str[i] - '0') * polarity;
		if ((cur < prev && polarity == 1) || (cur > prev && polarity == -1))
		{
			return (TRUE);
		}
		i += 1;
	}
	return (FALSE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 20:18:27 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 20:18:28 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int			ft_is_whitespace(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int			is_first_letter_of_word(char *sen, int i)
{
	if (!ft_is_whitespace(sen[i]))
	{
		if (i == 0 || ft_is_whitespace(sen[i - 1]))
			return (1);
	}
	return (0);
}

int			get_first_letter_idxs(char *sen, int *first_ltr_idxs)
{
	int	curr_first_letter_idx;
	int	i;

	curr_first_letter_idx = 0;
	i = 0;
	while (sen[i])
	{
		if (is_first_letter_of_word(sen, i))
		{
			first_ltr_idxs[curr_first_letter_idx] = i;
			curr_first_letter_idx++;
		}
		i++;
	}
	return (curr_first_letter_idx);
}

char		*get_word(char *sen, int first_ltr_idx)
{
	int		terminator;
	int		null_idx;
	char	*word;
	int		word_len;
	int		i;

	null_idx = ft_strlen(sen);
	terminator = first_ltr_idx + 1;
	while ((terminator != null_idx) && !ft_is_whitespace(sen[terminator]))
		terminator++;
	word_len = terminator - first_ltr_idx;
	word = malloc(sizeof(char) * (word_len) + 1);
	i = 0;
	while (i < word_len)
	{
		word[i] = sen[first_ltr_idx + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

t_str_arr	*ft_split_whitespaces(char *sen)
{
	int			*first_letter_of_word_idxs;
	int			words_in_sen;
	int			i;
	t_str_arr	*str_arr;
	char		*curr_word;

	first_letter_of_word_idxs = malloc(sizeof(int) * ft_strlen(sen));
	words_in_sen = get_first_letter_idxs(sen, first_letter_of_word_idxs);
	i = 0;
	str_arr = create_str_arr(words_in_sen);
	while (i < words_in_sen)
	{
		curr_word = get_word(sen, first_letter_of_word_idxs[i]);
		push_str_arr(str_arr, curr_word);
		i++;
	}
	free(first_letter_of_word_idxs);
	return (str_arr);
}

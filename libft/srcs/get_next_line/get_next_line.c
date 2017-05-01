/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbaldwin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 23:01:29 by pbaldwin          #+#    #+#             */
/*   Updated: 2017/01/19 23:01:31 by pbaldwin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define A static void *buffer;int read_ret;int flag;int currently_copied;
#define B static int line_buffer = BUFF_SIZE;static int ran = 0;
#define C A;B;
#define D buffer, line_buffer + 1, ((2 * line_buffer) + 1)
#define EXIT_CONDITION 	{;ran = 0;free(buffer);return (0);};
#define BUFF_SIZE 4096

static int	new_line_index(char *str, int line_buffer)
{
	int	i;

	i = 0;
	while (str[i] && i < line_buffer)
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	*process_new_line(void **buffer, int line_buffer, char **line)
{
	int		i;
	char	*str;
	void	*new_buffer;
	char	*typed_buff;

	typed_buff = (char *)(*buffer);
	i = new_line_index(typed_buff, line_buffer);
	i = (i == -1 ? ft_strlen(typed_buff) : i);
	str = (char *)ft_memalloc(i + 1);
	ft_strncpy(str, typed_buff, i);
	*line = str;
	new_buffer = ft_memalloc(line_buffer + 1);
	if (i < line_buffer)
		ft_strncpy(new_buffer, (typed_buff + i + 1), line_buffer);
	free(*buffer);
	return (new_buffer);
}

int			get_next_line(const int fd, char **line)
{
	C;
	if (!line || fd < 0)
		return (-1);
	buffer = (ran ? buffer : ft_memalloc(line_buffer + 1));
	currently_copied = ft_strlen(buffer);
	flag = -1;
	while (flag == -1 && \
		(read_ret = read(fd, (buffer + currently_copied), BUFF_SIZE)) > 0)
	{
		currently_copied += read_ret;
		if (line_buffer - currently_copied < BUFF_SIZE)
		{
			buffer = ft_realloc(D);
			line_buffer *= 2;
		}
		flag = new_line_index(buffer, line_buffer);
	}
	if (read_ret == -1 || !buffer)
		return (-1);
	buffer = process_new_line(&buffer, line_buffer, line);
	ran = 1;
	if (!read_ret && !currently_copied)
		EXIT_CONDITION;
	return (1);
}

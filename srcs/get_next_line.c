/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:20:22 by kecosmon          #+#    #+#             */
/*   Updated: 2018/01/09 19:20:24 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		check_line(char **stack, char **line)
{
	char			*tmp_stack;
	char			*chr_stack;
	size_t			i;

	i = 0;
	chr_stack = *stack;
	if (!(tmp_stack = ft_strchr(chr_stack, '\n')))
		return (0);
	*tmp_stack = '\0';
	*line = ft_strdup(*stack);
	*stack = ft_strdup(tmp_stack + 1);
	free(chr_stack);
	return (1);
}

static int		read_line(char **stack, char **line, int fd)
{
	char	*tmp_buff;
	char	*buff;
	int		ret;

	if (!(buff = ft_strnew(BUFF_SIZE)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		if (*stack)
		{
			tmp_buff = *stack;
			*stack = ft_strjoin(tmp_buff, buff);
			free(tmp_buff);
			tmp_buff = NULL;
		}
		else
			*stack = ft_strdup(buff);
		if (check_line(stack, line))
			break ;
	}
	free(buff);
	buff = NULL;
	return (ret > 0 ? 1 : ret);
}

int				get_next_line(int const fd, char **line)
{
	static char *stack[MAX_FD];
	int			ret;

	if (!line || BUFF_SIZE <= 0 || fd < 0 || fd > MAX_FD ||
		(read(fd, stack[fd], 0) < 0))
		return (-1);
	if (stack[fd] && check_line(&stack[fd], line))
		return (1);
	ret = read_line(&stack[fd], line, fd);
	if (ret != 0 || stack[fd] == NULL || stack[fd][0] == '\0')
	{
		if (!ret && *line)
			*line = NULL;
		return (ret);
	}
	*line = stack[fd];
	stack[fd] = NULL;
	return (1);
}

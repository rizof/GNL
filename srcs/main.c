/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c               		                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 19:20:22 by kecosmon          #+#    #+#             */
/*   Updated: 2018/01/09 19:20:24 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int 	main(int argc, char const *argv[])
{
	int 	fd;
	int 	i;
	char 	*line;
	int 	ret;

	i = 1;
	if (argc)
	{
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			while ((ret = get_next_line(fd, &line)) > 0)
			{
				ft_putendl(line);
				ft_strdel(&line);
			}
			close(fd);
			i++;
		}
	}
	return (0);
}

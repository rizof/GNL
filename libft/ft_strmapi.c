/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:09:53 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:09:54 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*mem;

	mem = NULL;
	i = 0;
	if (!s || !f)
		return (0);
	mem = malloc(ft_strlen((char *)s) + 1);
	if (!mem)
		return (0);
	while (s[i])
	{
		mem[i] = f(i, (char)s[i]);
		i++;
	}
	mem[i] = '\0';
	return (mem);
}

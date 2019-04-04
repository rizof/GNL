/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:11:34 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:12:10 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_worlds(char const *s, char c)
{
	int a;
	int count;

	count = 0;
	a = 0;
	while (s[a] != '\0')
	{
		if (s[a] != c && (s[a - 1] == c || a == 0))
			count++;
		a++;
	}
	return (count);
}

static char		*worlds(char const *s, char c, int *len, char *world)
{
	int a;
	int b;

	b = 0;
	while (s[(*len)] == c && s[(*len)++])
		;
	while (s[b + *len] != c && s[*len + b++])
		;
	world = malloc(b + 1);
	if (!world)
		return (0);
	a = 0;
	while (s[(*len)] != c && s[(*len)])
		world[a++] = s[(*len)++];
	world[a] = 0;
	return (world);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = 0;
	if (s)
		str = malloc(sizeof(*str) * count_worlds(s, c) + 1);
	if (!str)
		return (0);
	while (i < count_worlds(s, c))
	{
		str[i] = worlds(s, c, &j, str[i]);
		i++;
	}
	str[i] = 0;
	return (str);
}

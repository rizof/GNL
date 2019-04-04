/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:10:25 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:10:26 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	char	*p1;
	char	*p2;
	int		i;

	i = 0;
	p1 = (char *)s1;
	p2 = (char *)s2;
	if (n == 0)
		return (0);
	while (--n && p1[i] == p2[i] && p1[i] != '\0')
		i++;
	return ((unsigned char)p1[i] - (unsigned char)p2[i]);
}

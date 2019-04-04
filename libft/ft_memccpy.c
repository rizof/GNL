/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:05:36 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:05:38 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	const unsigned char	*sr;
	unsigned char		*ds;
	unsigned char		chr;
	int					i;

	chr = c;
	ds = dest;
	sr = src;
	i = 0;
	while (n--)
	{
		if (sr[i] == chr)
		{
			ds[i] = sr[i];
			return (ds + i + 1);
		}
		ds[i] = sr[i];
		i++;
	}
	return (NULL);
}

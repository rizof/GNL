/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:03:23 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:03:24 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_len(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	size_t			len;
	char			*nb;
	unsigned int	number;

	number = n;
	len = str_len(n);
	if (n < 0)
	{
		number = -number;
		len++;
	}
	nb = ft_strnew(len);
	if (!nb)
		return (0);
	nb[len] = '\0';
	nb[--len] = number % 10 + '0';
	while (number /= 10)
		nb[--len] = number % 10 + '0';
	if (n < 0)
		nb[0] = '-';
	return (nb);
}

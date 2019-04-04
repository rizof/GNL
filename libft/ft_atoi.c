/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:01:03 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:01:22 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned long long	nb;
	int					neg;
	int					i;

	i = 0;
	neg = 1;
	nb = 0;
	while (nptr[i] == '\t' || nptr[i] == '\v' || nptr[i] == '\r' ||
		nptr[i] == '\f' || nptr[i] == '\n' || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while (nptr[i] && nptr[i] <= '9' && nptr[i] >= '0')
	{
		nb *= 10;
		nb += nptr[i] - '0';
		i++;
	}
	if (i > 19 || nb > 9223372036854775807)
		return ((neg == 1) ? -1 : 0);
	return ((int)nb * neg);
}

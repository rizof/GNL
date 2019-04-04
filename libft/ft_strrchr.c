/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:11:27 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:11:28 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	unsigned int	i;

	i = ft_strlen(str) + 1;
	while (i > 0 && str[i - 1] != c)
		i--;
	if (i > 0)
		return ((char*)(str) + i - 1);
	else
		return (NULL);
}

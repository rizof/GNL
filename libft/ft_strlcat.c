/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:09:29 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:09:30 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*cur;
	size_t	len;

	cur = (char *)ft_memchr(dst, '\0', size);
	if (cur == NULL)
		return (size + ft_strlen(src));
	len = (size_t)(cur - dst) + ft_strlen(src);
	while ((size_t)(cur - dst) < size - 1 && *src != '\0')
		*cur++ = *src++;
	*cur = '\0';
	return (len);
}

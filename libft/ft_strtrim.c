/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kecosmon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 18:12:40 by kecosmon          #+#    #+#             */
/*   Updated: 2017/11/21 18:12:41 by kecosmon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t			n;
	unsigned int	i;

	i = 0;
	n = 0;
	if (!s)
		return (0);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (ft_strnew(0));
	n = ft_strlen(s) - 1;
	while (n > 0 && (s[n] == ' ' || s[n] == '\n' || s[n] == '\t'))
		n--;
	return (ft_strsub(&s[i], 0, n - (size_t)i + 1));
}

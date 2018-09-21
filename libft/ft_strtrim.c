/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 13:58:54 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/10 14:13:18 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isblank(unsigned char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

char		*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	y;
	size_t	len;
	size_t	z;

	len = ft_strlen(s);
	i = 0;
	while (s[i] && ft_isblank((unsigned char)s[i]))
		i++;
	if (i == len)
		return (char *)ft_memalloc(0);
	y = len - 1;
	z = 0;
	while (s[y] && ft_isblank((unsigned char)s[y]))
	{
		y--;
		z++;
	}
	return (ft_strsub(s, i, len - i - z));
}

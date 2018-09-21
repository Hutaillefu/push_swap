/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:15:38 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/10 11:48:58 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_test(char h, char c, size_t i, size_t len)
{
	if (h && c && h == c && i < len)
		return (1);
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	int		y;
	int		needle_len;
	char	*ptr;

	if ((needle_len = ft_strlen(needle)) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		y = 0;
		if (haystack[i] == needle[y])
		{
			ptr = (char *)&haystack[i];
			while (ft_test(haystack[i], needle[y], i, len) == 1)
			{
				i++;
				y++;
			}
			if (y == needle_len)
				return (ptr);
		}
		i++;
	}
	return (NULL);
}

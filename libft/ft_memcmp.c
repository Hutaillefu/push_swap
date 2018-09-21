/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:43:19 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/09 12:43:28 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1n;
	unsigned char	*s2n;

	i = 0;
	s1n = (unsigned char *)s1;
	s2n = (unsigned char *)s2;
	while (i < n)
	{
		if (s1n[i] != s2n[i])
			return (s1n[i] - s2n[i]);
		i++;
	}
	return (0);
}

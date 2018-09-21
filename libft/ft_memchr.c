/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:42:00 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/09 15:04:57 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*iterator;
	size_t			i;

	iterator = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (iterator[i] == (unsigned char)c)
			return (&iterator[i]);
		i++;
	}
	return (NULL);
}

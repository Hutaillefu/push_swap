/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:45:00 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/09 12:45:05 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	y;

	y = ft_strlen(dst);
	i = 0;
	while (i < n && src[i])
	{
		dst[y] = src[i];
		i++;
		y++;
	}
	dst[y] = '\0';
	return (dst);
}

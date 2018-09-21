/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpush.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:45:34 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/10 18:03:53 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

void	ft_lstpush(t_list **alst, t_list *new)
{
	t_list *iterator;

    if (!alst || !new)
    return;

	if (!(*alst))
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	else
	{
        iterator = *alst;
		while (iterator->next)
        {
            iterator = iterator->next;
        }
        new->next = NULL;
        iterator->next = new;
	}
}

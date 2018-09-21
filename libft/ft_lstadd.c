/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:45:34 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/10 18:03:53 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{

	if (!alst || !new)
		return;

	if (!(*alst))
	{
		*alst = new;
		(*alst)->next = NULL;
	}
	else
	{
		new->next = *alst;
		*alst = new;
	}
}

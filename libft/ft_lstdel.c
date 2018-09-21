/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htaillef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:31:41 by htaillef          #+#    #+#             */
/*   Updated: 2017/11/10 17:44:15 by htaillef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel_rec(t_list *alst, void (*del)(void *, size_t))
{
	if (!(alst->next))
		ft_lstdelone(&alst, (*del));
	else
		ft_lstdel_rec(alst->next, (*del));
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *iterator;

	iterator = *alst;
	ft_lstdel_rec(iterator, (*del));
}

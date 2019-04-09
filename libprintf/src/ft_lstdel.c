/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:31:24 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:42:21 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (!(alst && *alst && del))
		return ;
	while (*alst)
	{
		del((*alst)->content, (*alst)->content_size);
		tmp = (*alst)->next;
		free(*alst);
		*alst = tmp;
	}
	ft_memdel((void**)alst);
}

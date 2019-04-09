/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:10:05 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:42:30 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*tmp;

	if (!alst)
		return ;
	tmp = *alst;
	del(tmp->content, tmp->content_size);
	ft_memdel((void**)alst);
}

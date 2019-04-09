/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:56:52 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:42:57 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*current;
	t_list	*before;

	if (!(lst && f))
		return (0);
	begin = ft_lstnew(f(lst)->content, f(lst)->content_size);
	before = begin;
	lst = lst->next;
	while (lst)
	{
		current = ft_lstnew(f(lst)->content, f(lst)->content_size);
		before->next = current;
		before = before->next;
		lst = lst->next;
	}
	return (begin);
}

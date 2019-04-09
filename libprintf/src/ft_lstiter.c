/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:49:35 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:42:41 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*current;

	if (!(lst))
		return ;
	current = lst;
	while (current)
	{
		f(current);
		current = current->next;
	}
}

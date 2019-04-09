/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: floblanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 17:42:47 by floblanc          #+#    #+#             */
/*   Updated: 2019/04/04 11:42:13 by maginist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libprintf.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	t_list	*begin;

	if (!(alst))
		return ;
	begin = *alst;
	new->next = begin;
	*alst = new;
}

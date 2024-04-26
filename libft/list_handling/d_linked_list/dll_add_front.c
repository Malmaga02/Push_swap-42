/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_add_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:02:25 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/26 13:50:34 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dll_add_front(t_dll **lst, t_dll *new)
{
	t_dll	*head;

	head = *lst;
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		new->prev = NULL;
		new->next = NULL;
		new->index = 0;
		*lst = new;
		return ;
	}
	new->next = head;
	new->prev = NULL;
	new->index = 0;
	*lst = new;
	set_index(lst);
}

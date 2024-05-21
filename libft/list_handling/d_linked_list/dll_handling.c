/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dll_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:20:45 by chsassi           #+#    #+#             */
/*   Updated: 2024/05/02 18:31:29 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_index(t_dll *pStack)
{
	int		i;
	t_dll	*tmp;
	t_dll	*tmp2;

	i = 0;
	tmp = pStack;
	tmp2 = pStack->next;
	while (tmp2)
	{
		if (tmp->value > tmp2->value)
		{
			i = tmp2->index;
			tmp = tmp2;
		}
		tmp2 = tmp2->next;
	}
	return (i);
}

int	find_min_value(t_dll *pStack)
{
	int		i;
	int		min;
	t_dll	*ptr;

	i = 0;
	min = INT_MAX;
	ptr = pStack;
	while (ptr)
	{
		if (ptr->value < min)
			min = ptr->value;
		ptr = ptr->next;
	}
	return (min);
}

int	find_max_index(t_dll *pStack)
{
	int		i;
	t_dll	*tmp;
	t_dll	*tmp2;

	i = 0;
	tmp = pStack;
	tmp2 = pStack->next;
	while (tmp2)
	{
		if (tmp->value < tmp2->value)
		{
			i = tmp2->index;
			tmp = tmp2;
		}
		tmp2 = tmp2->next;
	}
	return (i);
}

int	find_max_value(t_dll *pStack)
{
	int		i;
	int		max;
	t_dll	*ptr;

	i = 0;
	max = INT_MIN;
	ptr = pStack;
	while (ptr)
	{
		if (ptr->value > max)
			max = ptr->value;
		ptr = ptr->next;
	}
	return (max);
}

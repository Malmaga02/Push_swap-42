/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:14:12 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:21 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_pa(t_dll **stack_a, t_dll **stack_b)
{
	t_dll	*b_tmp;

	if (!*stack_b)
		return ;
	if (dll_size(*stack_b) == 1)
	{
		dll_add_front(stack_a, *stack_b);
		*stack_b = NULL;
		return ;
	}
	b_tmp = (*stack_b)->next;
	dll_add_front(stack_a, *stack_b);
	b_tmp->prev = NULL;
	*stack_b = b_tmp;
	set_index(stack_b);
}

void	checker_pb(t_dll **stack_b, t_dll **stack_a)
{
	t_dll	*a_tmp;

	if (!*stack_a)
		return ;
	if (dll_size(*stack_a) == 1)
	{
		dll_add_front(stack_b, *stack_a);
		*stack_a = NULL;
		return ;
	}
	a_tmp = (*stack_a)->next;
	dll_add_front(stack_b, *stack_a);
	a_tmp->prev = NULL;
	*stack_a = a_tmp;
	set_index(stack_a);
}

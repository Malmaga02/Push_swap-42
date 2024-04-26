/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_dll **stack_a, t_dll **stack_b)
{
	t_dll	*b_tmp;

	b_tmp = *stack_b;
	dll_add_front(stack_a, *stack_b);
	b_tmp->prev = NULL;
	b_tmp = b_tmp->next;
	*stack_b = b_tmp;
	set_index(stack_b);
	write(1, "pa\n", 3);
}

void	pb(t_dll **stack_b, t_dll **stack_a)
{
	t_dll	*a_tmp;

	a_tmp = (*stack_a)->next;
	dll_add_front(stack_b, *stack_a);
	a_tmp->prev = NULL;
	*stack_a = a_tmp;
	set_index(stack_a);
	write(1, "pb\n", 3);
}

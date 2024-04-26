/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	**rotate_op(t_dll **stack)
{
	t_dll	*head;
	t_dll	*last;
	t_dll	*second;

	head = *stack;
	last = dll_last(head);
	second = head->next;
	head->prev = last;
	head->next = NULL;
	last->next = head;
	second->prev = NULL;
	*stack = second;
	set_index(stack);
	return (stack);
}

t_dll	**rotate(t_dll **stack_a, t_dll **stack_b, int flag)
{
	t_dll	**stack_res;

	if (flag == MOVE_A)
	{
		stack_res = rotate_op(stack_a);
		return (write(1, "ra\n", 3), stack_res);
	}
	else if (flag == MOVE_B)
	{
		stack_res = rotate_op(stack_b);
		return (write(1, "rb\n", 3), stack_res);
	}
	else if (flag == MOVE_BOTH)
	{
		stack_a = rotate_op(stack_a);
		stack_b = rotate_op(stack_b);
	}
	return (write(1, "rr\n", 3), stack_a);
}

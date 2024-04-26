/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	**r_rotate_op(t_dll **stack)
{
	t_dll	*head;
	t_dll	*last;
	t_dll	*bef_last;


	head = *stack;
	last = dll_last(head);
	bef_last = last->prev;

	last->next = head;
	last->prev = NULL;
	head->prev = last;
	bef_last->next = NULL;
	*stack = last; 
	set_index(stack);
	return (stack);
}

t_dll	**r_rotate(t_dll **stack_a, t_dll **stack_b, int flag)
{
	t_dll	**stack_res;

	if (flag == MOVE_A)
	{
		stack_res = r_rotate_op(stack_a);
		return (write(1, "rra\n", 4), stack_res);
	}
	else if (flag == MOVE_B)
	{
		stack_res = r_rotate_op(stack_b);
		return (write(1, "rrb\n", 4), stack_res);
	}
	else if (flag == MOVE_BOTH)
	{
		stack_a = r_rotate_op(stack_a);
		stack_b = r_rotate_op(stack_b);
		return (write(1, "rrr\n", 4), stack_a);
	}
	return (0);
}

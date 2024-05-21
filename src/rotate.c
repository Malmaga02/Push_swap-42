/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_op(t_dll **stack)
{
	t_dll	*head;
	t_dll	*last;
	t_dll	*second;

	if (!*stack || dll_size(*stack) == 1)
		return ;
	head = *stack;
	last = dll_last(head);
	second = head->next;
	head->prev = last;
	head->next = NULL;
	last->next = head;
	second->prev = NULL;
	*stack = second;
	set_index(stack);
}

void	rotate(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
	{
		rotate_op(stack_a);
		write(1, "ra\n", 3);
		return ;
	}
	else if (flag == MOVE_B)
	{
		rotate_op(stack_b);
		write(1, "rb\n", 3);
		return ;
	}
	else if (flag == MOVE_BOTH)
	{
		rotate_op(stack_a);
		rotate_op(stack_b);
	}
	write(1, "rr\n", 3);
}

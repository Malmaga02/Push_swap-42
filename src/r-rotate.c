/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_op(t_dll **stack)
{
	t_dll	*head;
	t_dll	*last;
	t_dll	*bef_last;

	if (!*stack || dll_size(*stack) == 1)
		return ;
	head = *stack;
	last = dll_last(head);
	bef_last = last->prev;
	last->next = head;
	last->prev = NULL;
	head->prev = last;
	bef_last->next = NULL;
	*stack = last;
	set_index(stack);
}

void	r_rotate(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
	{
		r_rotate_op(stack_a);
		write(1, "rra\n", 4);
	}
	else if (flag == MOVE_B)
	{
		r_rotate_op(stack_b);
		write(1, "rrb\n", 4);
	}
	else if (flag == MOVE_BOTH)
	{
		r_rotate_op(stack_a);
		r_rotate_op(stack_b);
		write(1, "rrr\n", 4);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r-rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:14:12 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:21 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_r_rotate_op(t_dll **stack)
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

void	checker_r_rotate(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
		checker_r_rotate_op(stack_a);
	else if (flag == MOVE_B)
		checker_r_rotate_op(stack_b);
	else if (flag == MOVE_BOTH)
	{
		checker_r_rotate_op(stack_a);
		checker_r_rotate_op(stack_b);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_op(t_dll **stack)
{
	t_dll	*head;
	int		tmp_value;

	if (!*stack || dll_size(*stack) == 1)
		return ;
	head = *stack;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
}

void	swap(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
	{
		swap_op(stack_a);
		write(1, "sa\n", 3);
	}
	else if (flag == MOVE_B)
	{
		swap_op(stack_b);
		write(1, "sb\n", 3);
	}
	else if (flag == MOVE_BOTH)
	{
		swap_op(stack_a);
		swap_op(stack_b);
		write(1, "ss\n", 3);
	}
}

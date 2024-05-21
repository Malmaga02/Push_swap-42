/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:14:12 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:21 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	checker_swap_op(t_dll **stack)
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

void	checker_swap(t_dll **stack_a, t_dll **stack_b, int flag)
{
	if (flag == MOVE_A)
		checker_swap_op(stack_a);
	else if (flag == MOVE_B)
		checker_swap_op(stack_b);
	else if (flag == MOVE_BOTH)
	{
		checker_swap_op(stack_a);
		checker_swap_op(stack_b);
	}
}

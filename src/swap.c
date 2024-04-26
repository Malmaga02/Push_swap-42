/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:46:10 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/02 20:46:13 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dll	**swap_op(t_dll **node1)
{
	t_dll	*head;
	int		tmp_value;

	head = *node1;
	tmp_value = head->value;
	head->value = head->next->value;
	head->next->value = tmp_value;
	return (node1);
}

t_dll	**swap(t_dll **stack_a, t_dll **stack_b, int flag)
{
	t_dll	**stack_res;

	if (flag == MOVE_A)
	{
		stack_res = swap_op(stack_a);
		return (write(1, "sa\n", 3), stack_res);
	}
	else if (flag == MOVE_B)
	{
		stack_res = swap_op(stack_b);
		return (write(1, "sb\n", 3), stack_res);
	}
	else if (flag == MOVE_BOTH)
	{
		stack_a = swap_op(stack_a);
		stack_b = swap_op(stack_b);
		return (write(1, "ss\n", 3), stack_a);
	}
	return (NULL);
}

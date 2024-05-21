/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:03:34 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_move(t_dll *pStack)
{
	int		head_value;
	int		middle_value;
	int		last_value;
	int		min_value;
	int		max_value;

	head_value = pStack->value;
	middle_value = pStack->next->value;
	last_value = pStack->next->next->value;
	min_value = find_min_value(pStack);
	max_value = find_max_value(pStack);
	if ((middle_value == max_value && head_value == min_value)
		|| (middle_value == min_value && last_value == max_value)
		|| (middle_value != min_value && middle_value != max_value))
		return (SWAP);
	if (middle_value == min_value && head_value == max_value)
		return (ROTATE);
	else if (middle_value == max_value && last_value == min_value)
		return (R_ROTATE);
	return (STAY);
}

void	solve_3(t_dll **pStack)
{
	if (!pStack || !(*pStack))
		return ;
	if (is_sorted(*pStack))
		return ;
	if (find_move(*pStack) == SWAP)
		swap(pStack, NULL, MOVE_A);
	if (find_move(*pStack) == ROTATE)
		rotate(pStack, NULL, MOVE_A);
	else if (find_move(*pStack) == R_ROTATE)
		r_rotate(pStack, NULL, MOVE_A);
}

void	solve_4(t_dll **pStack, t_dll **stack_b)
{
	int		i;

	i = find_min_index(*pStack);
	if (i >= 1)
	{
		i = 4 - i;
		while (i > 0)
		{
			r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else if (i > 0)
	{
		while (i < 1)
		{
			rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	if (is_sorted(*pStack))
		return ;
	pb(stack_b, pStack);
	solve_3(pStack);
	pa(pStack, stack_b);
}

void	solve_5(t_dll **pStack, t_dll **stack_b)
{
	int		i;

	i = find_min_index(*pStack);
	if (i >= 2)
	{
		i = 5 - i;
		while (i > 0)
		{
			r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else if (i > 0)
	{
		while (i < 2)
		{
			rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	pb(stack_b, pStack);
	solve_4(pStack, stack_b);
	pa(pStack, stack_b);
}

void	minisort(t_dll **stack_a, t_dll **stack_b)
{
	int		len;

	len = dll_size(*stack_a);
	if (len == 2 && (*stack_a)->value > (*stack_a)->next->value)
		swap(stack_a, NULL, MOVE_A);
	else if (len == 3)
		solve_3(stack_a);
	else if (len == 4)
		solve_4(stack_a, stack_b);
	else if (len == 5)
		solve_5(stack_a, stack_b);
}

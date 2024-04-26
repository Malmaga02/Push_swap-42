/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 18:03:34 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/09 15:46:46 by chsassi          ###   ########.fr       */
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

t_dll	**solve_3(t_dll **pStack)
{
	if (!pStack || !(*pStack))
		return (NULL);
	if (is_sorted(*pStack))
		return (pStack);
	if (find_move(*pStack) == SWAP)
		pStack = swap(pStack, NULL, MOVE_A);
	if (find_move(*pStack) == ROTATE)
		pStack = rotate(pStack, NULL, MOVE_A);
	else if (find_move(*pStack) == R_ROTATE)
		pStack = r_rotate(pStack, NULL, MOVE_A);
	return (pStack);
}

/* t_dll	**solve_3(t_dll **pStack)
{
	int		head_value;
	int		middle_value;
	int		last_value;

	head_value = (*pStack)->value;
	middle_value = (*pStack)->next->value;
	last_value = (*pStack)->next->next->value;
	if (is_sorted(*pStack))
		return (pStack);
	if (head_value > middle_value)
	{
		if (middle_value > last_value)
		{
			pStack = rotate(pStack, NULL, MOVE_A);
			pStack = swap(pStack, NULL, MOVE_A);
		}
		else
			pStack = rotate(pStack, NULL, MOVE_A);
	}
	else if (head_value < middle_value)
	{
		if (head_value < last_value)
		{
			pStack = swap(pStack, NULL, MOVE_A);
			pStack = rotate(pStack, NULL, MOVE_A);
		}
		else
			pStack = r_rotate(pStack, NULL, MOVE_A);
	}
	return (pStack);
} */

t_dll	**solve_4(t_dll **pStack, t_dll **stack_b)
{
	int		i;

	i = find_min_index(*pStack);
	if (i > 1)
	{
		i = 4 - i;
		while (i > 0)
		{
			pStack = r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else
	{
		while (i < 1)
		{
			pStack = rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	if (is_sorted(*pStack))
		return (pStack);
	pb(stack_b, pStack);
	pStack = solve_3(pStack);
	pa(pStack, stack_b);
	return (pStack);
}

t_dll	**solve_5(t_dll **pStack, t_dll **stack_b)
{
	int		i;

	i = find_min_index(*pStack);
	if (i > 2)
	{
		i = 5 - i;
		while (i > 0)
		{
			pStack = r_rotate(pStack, NULL, MOVE_A);
			i--;
		}
	}
	else
	{
		while (i < 2)
		{
			pStack = rotate(pStack, NULL, MOVE_A);
			i++;
		}
	}
	pb(stack_b, pStack);
	pStack = solve_4(pStack, stack_b);
	pa(pStack, stack_b);
	return (pStack);
}

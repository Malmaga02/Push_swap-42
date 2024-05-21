/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:32:14 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:43 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves)
{
	while (moves.rot_a > 0)
	{
		rotate(stack_a, stack_b, MOVE_A);
		moves.rot_a--;
	}
	while (moves.rot_b > 0)
	{
		rotate(stack_a, stack_b, MOVE_B);
		moves.rot_b--;
	}
	while (moves.rot_both > 0)
	{
		rotate(stack_a, stack_b, MOVE_BOTH);
		moves.rot_both--;
	}
}

void	get_r_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves)
{
	while (moves.r_rot_a > 0)
	{
		r_rotate(stack_a, stack_b, MOVE_A);
		moves.r_rot_a--;
	}
	while (moves.r_rot_b > 0)
	{
		r_rotate(stack_a, stack_b, MOVE_B);
		moves.r_rot_b--;
	}
	while (moves.r_rot_both > 0)
	{
		r_rotate(stack_a, stack_b, MOVE_BOTH);
		moves.r_rot_both--;
	}
}

void	solver(t_dll **stack_a)
{
	t_dll	*stack_b;
	int		len;

	stack_b = NULL;
	len = dll_size(*stack_a);
	if (len <= 5)
	{
		minisort(stack_a, &stack_b);
		return ;
	}
	stack_b = get_stack_lis(stack_a);
	if (!stack_b)
		return ;
	solve_all(stack_a, &stack_b);
}

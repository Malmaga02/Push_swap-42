/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcolo_mosse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:51:42 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/25 15:51:44 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bestmoves	check_moves_b(t_dll *stack_b, int value_b, t_bestmoves moves)
{
	int	index;
	int	size;

	index = 0;
	size = dll_size(stack_b);
	while (stack_b)
	{
		if (stack_b->value == value_b)
		{
			index = stack_b->index;
			break;
		}
		stack_b = stack_b->next;
	}
	if (index > (size - 1) / 2)
		moves.r_rot_b = size - index;
	else
		moves.rot_b = index;
	return (moves);
}

t_bestmoves	check_moves_a(t_dll *stack_a, int value_b, t_bestmoves moves)
{
	int	index;
	int	size;
	int	diff;

	index = 0;
	diff = INT_MAX;
	size = dll_size(stack_a);
	if (find_min_value(stack_a) > value_b || find_max_value(stack_a) < value_b)
		return (moves);
	while (stack_a)
	{
		if (stack_a->value > value_b && diff > stack_a->value - value_b)
		{
			diff = stack_a->value - value_b;
			index = stack_a->index;
		}
		stack_a = stack_a->next;
	}
	if (index > (size - 1) / 2)
		moves.r_rot_a = size - index;
	else
		moves.rot_a = index; 
	return (moves);
}

t_bestmoves	organize_moves(t_bestmoves moves)
{
	if (moves.rot_a >= moves.rot_b)
	{
		moves.rot_both = moves.rot_b;
		moves = bestmoves_operations(moves, ROTATE);
	}
	else if (moves.rot_a < moves.rot_b)
	{
		moves.rot_both = moves.rot_a;
		moves = bestmoves_operations(moves, ROTATE);
	}
	if (moves.r_rot_a >= moves.r_rot_b)
	{
		moves.r_rot_both = moves.r_rot_b;
		moves = bestmoves_operations(moves, R_ROTATE);
	}
	else if (moves.r_rot_a < moves.r_rot_b)
	{
		moves.r_rot_both = moves.r_rot_a;
		moves = bestmoves_operations(moves, R_ROTATE);
	}
	moves = bestmoves_operations(moves, STAY);
	return (moves);
}
t_bestmoves	get_moves(t_dll *stack_a, t_dll *stack_b, int value_b)
{
	t_bestmoves	moves;

	moves = (t_bestmoves){0};
	moves = check_moves_b(stack_b, value_b, moves);
	moves = check_moves_a(stack_a, value_b, moves);
	moves = organize_moves(moves);
	return (moves);
}

t_bestmoves	get_best_moves(t_dll *stack_a, t_dll *stack_b)
{
	t_bestmoves	best;
	t_bestmoves	next;
	t_dll		*tmp_b;

	tmp_b = stack_b;
	best = get_moves(stack_a, stack_b, stack_b->value);
	while (tmp_b->next)
	{
		tmp_b = tmp_b->next;
		next = get_moves(stack_a, stack_b, tmp_b->value);
		if (best.tot_moves > next.tot_moves)
			best = bestmoves_cpy(next);
	}
	return (best);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsassi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:01 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/09 15:48:04 by chsassi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicates(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	while (mtx && mtx[i])
	{
		j = i + 1;
		while (mtx[j])
		{
			if (!ft_strncmp(mtx[i], mtx[j], 12))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_sorted(t_dll *pStack)
{
	t_dll	*tmp;

	tmp = pStack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	mtx_check(char **mtx)
{
	int	i;
	int	j;

	i = 0;
	while (mtx && mtx[i])
	{
		j = 0;
		while (mtx[i][j])
		{
			if (mtx[i][j] == '-' || mtx[i][j] == '+')
			{
				if (!(mtx[i][j + 1] >= '0' && mtx[i][j + 1] <= '9'))
					return (0);
				if (j != 0 && mtx[i][j - 1] != ' ')
					return (0);
			}
			else if (!(mtx[i][j] >= '0' && mtx[i][j] <= '9'))
				return (0);
			j++;
		}
		i++;
	}
	if (!check_duplicates(mtx))
		return (0);
	return (1);
}

t_bestmoves	bestmoves_cpy(t_bestmoves moves)
{
	t_bestmoves	res;

	res = (t_bestmoves){0};
	res.rot_a = moves.rot_a;
    res.rot_b = moves.rot_b;
    res.rot_both = moves.rot_both;
    res.r_rot_a = moves.r_rot_a;
    res.r_rot_b = moves.r_rot_b;
    res.r_rot_both = moves.r_rot_both;
    res.tot_moves = moves.tot_moves;
	return (res);
}

t_bestmoves	bestmoves_operations(t_bestmoves moves, int flag_move)
{
	if (flag_move == ROTATE)
	{	
		moves.rot_a -= moves.rot_both;
        moves.rot_b -= moves.rot_both;
	}
	if (flag_move == R_ROTATE)
	{	
		moves.r_rot_a -= moves.r_rot_both;
        moves.r_rot_b -= moves.r_rot_both;
	}
	if (flag_move == STAY)
		moves.tot_moves = moves.rot_a + moves.rot_b + moves.rot_both \
			+ moves.r_rot_a + moves.r_rot_b + moves.r_rot_both;
	return (moves);
}

void    get_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves)
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

void    get_r_rotate(t_dll **stack_a, t_dll **stack_b, t_bestmoves moves)
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
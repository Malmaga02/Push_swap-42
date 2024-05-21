/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:48:01 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:43 by mgalmari         ###   ########.fr       */
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

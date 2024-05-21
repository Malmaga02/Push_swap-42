/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 13:22:45 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:21 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	do_the_moves(t_dll **stack_a, t_dll **stack_b, char *str)
{
	if (!ft_strncmp("sa\n", str, 3))
		return (checker_swap(stack_a, stack_b, MOVE_A), 0);
	else if (!ft_strncmp("ra\n", str, 3))
		return (checker_rotate(stack_a, stack_b, MOVE_A), 0);
	else if (!ft_strncmp("rra\n", str, 4))
		return (checker_r_rotate(stack_a, stack_b, MOVE_A), 0);
	else if (!ft_strncmp("pa\n", str, 3))
		return (checker_pa(stack_a, stack_b), 0);
	else if (!ft_strncmp("sb\n", str, 3))
		return (checker_swap(stack_a, stack_b, MOVE_B), 0);
	else if (!ft_strncmp("rb\n", str, 3))
		return (checker_rotate(stack_a, stack_b, MOVE_B), 0);
	else if (!ft_strncmp("rrb\n", str, 4))
		return (checker_r_rotate(stack_a, stack_b, MOVE_B), 0);
	else if (!ft_strncmp("pb\n", str, 3))
		return (checker_pb(stack_b, stack_a), 0);
	else if (!ft_strncmp("ss\n", str, 3))
		return (checker_swap(stack_a, stack_b, MOVE_BOTH), 0);
	else if (!ft_strncmp("rr\n", str, 3))
		return (checker_rotate(stack_a, stack_b, MOVE_BOTH), 0);
	else if (!ft_strncmp("rrr\n", str, 4))
		return (checker_r_rotate(stack_a, stack_b, MOVE_BOTH), 0);
	else
		return (1);
}

int	read_moves(t_dll **stack_a, t_dll **stack_b)
{
	int		i;
	char	*str;

	i = 0;
	str = get_next_line(0);
	while (str && ft_strncmp("\n", str, 3))
	{
		i = do_the_moves(stack_a, stack_b, str);
		if (i == 1)
			return (free(str), dll_clear(stack_a), dll_clear(stack_b), 0);
		free(str);
		str = get_next_line(0);
	}
	if (str)
		free(str);
	return (1);
}

int	main(int ac, char **av)
{
	t_dll	*stack_a;
	t_dll	*stack_b;

	stack_a = checker_parse_input(ac, av);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	if (!read_moves(&stack_a, &stack_b))
		return (ft_putstr_fd("Error\n", STDERR_FILENO), 1);
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	if (stack_a)
		dll_clear(&stack_a);
	if (stack_b)
		dll_clear(&stack_b);
	return (0);
}

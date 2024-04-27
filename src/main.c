/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brulutaj <brulutaj@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 19:16:28 by chsassi           #+#    #+#             */
/*   Updated: 2024/04/19 20:41:08 by brulutaj         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_dll	*list;
	t_dll	*stack_b;
	t_dll	*tmp_b;

	list = NULL;
	stack_b = (t_dll *){0};
	if (ac == 1 || !av[1] || !av[1][0])
		return (0);
	if (ac == 2)
		list = parse_input_string(ac, av[1]);
	else if (ac > 2)
		list = parse_input_args(ac, &av[1]);
	if ((list && is_sorted(list)) || !list)
		return (0);
	stack_b = get_stack_lis(&list);
	if (!stack_b)
		return (0);
	tmp_b = stack_b;
	solve_all(&list, &stack_b);
 	dll_clear(&list);
	return (0);
}



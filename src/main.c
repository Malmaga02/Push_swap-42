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
	int		len;
	t_bestmoves best;

	list = NULL;
	stack_b = (t_dll *){0};
	len = 0;
	if (ac == 1 || !av[1] || !av[1][0])
		return (0);
	if (ac == 2)
		list = parse_input_string(ac, av[1]);
	else if (ac > 2)
		list = parse_input_args(ac, &av[1]);
	if ((list && is_sorted(list)) || !list)
		return (0);
	/* len = dll_size(list);
	if (len == 3)
		solve_3(&list);
	else if (len == 4)
		solve_4(&list, &stack_b);
	else if (len == 5)
		solve_5(&list, &stack_b); */
	stack_b = solve_all(&list);
	/* while (list)
	{
		ft_printf("value [%d] = %d\n", len, list->value);
		list = list->next;
		len++;
	}
	len = 0;
	while (stack_b)
	{
		ft_printf("value [%d] = %d\n", len, stack_b->value);
		stack_b = stack_b->next;
		len++;
	} */
	best = get_best_moves(list, stack_b);
	printf("rot_a = %d,\nrot_b = %d,\nrot_both = %d,\n", \
	best.rot_a, best.rot_b, best.rot_both);
	printf("r_rot_a = %d,\nr_rot_b = %d,\nr_rot_both = %d,\n", \
	best.r_rot_a, best.r_rot_b, best.r_rot_both);
	printf("tot = %d\n", best.tot_moves);
	dll_clear(&list);
	dll_clear(&stack_b);
	return (0);
}

/* int main()
{
	t_dll *head_a;
	t_dll *head_b;
	t_dll *n1_a;
	t_dll *n2_a;
	t_dll *n3_a;
	t_dll *n4_a;
	t_dll *n1_b;
	t_dll *n2_b;
	t_dll *n3_b;
	t_dll *n4_b;
	t_bestmoves	moves;

	head_a = NULL;
	head_b = NULL;
	moves = (t_bestmoves){0};

	n1_a = dll_new(2);
	dll_add_back(&head_a, n1_a);
	n2_a = dll_new(9);
	dll_add_back(&head_a, n2_a);
	n3_a = dll_new(4);
	dll_add_back(&head_a, n3_a);
	n4_a = dll_new(7);
	dll_add_back(&head_a, n4_a);
	set_index(&head_a);

	n1_b = dll_new(3);
	dll_add_back(&head_b, n1_b);
	n2_b = dll_new(5);
	dll_add_back(&head_b, n2_b);
	n3_b = dll_new(9);
	dll_add_back(&head_b, n3_b);
	n4_b = dll_new(0);
	dll_add_back(&head_b, n4_b);
	set_index(&head_b);

	moves = get_best_moves(head_a, head_b);
	printf("rot_a = %d,\nrot_b = %d,\nrot_both = %d,\n", \
	moves.rot_a, moves.rot_b, moves.rot_both);
	printf("r_rot_a = %d,\nr_rot_b = %d,\nr_rot_both = %d,\n", \
	moves.r_rot_a, moves.r_rot_b, moves.r_rot_both);
	printf("tot = %d\n", moves.tot_moves);
	dll_clear(&head_a);
	dll_clear(&head_b);
	
	return (0); 
}
 */
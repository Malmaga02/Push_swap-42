/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 15:12:28 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/26 15:12:33 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*lis_algo(t_dll *head, int *n)
{
	t_dll	*tmp;
	int     *lis_array;
	int     size;
	int		max;

	if (!head)
		return ((void *)0);
	tmp = head;
	size = dll_size(head);
	max = tmp->value;
	lis_array = ft_calloc(size, sizeof(int));
	if (!lis_array)
		return ((void *)0);
	lis_array[0] = tmp->index;
	while (tmp->next != NULL)
	{
		if (tmp->next->value > max)
		{
			(*n)++;
			lis_array[*n - 1] = tmp->next->index;
			max = tmp->next->value;
		}
		tmp = tmp->next;
	}
	return (lis_array);
}

t_dll   *handling_lis(t_dll **stack_a, int *index_a, int lis_size)
{
	int index;
	int size_a;
	int	i;
	t_dll   *stack_b;

	i = 0;
	index = 0;
	(void)lis_size;
	size_a = dll_size(*stack_a);
	stack_b = NULL;
	while (index < size_a)
	{
		if (index == index_a[i])
		{
			rotate(stack_a, &stack_b, MOVE_A);
			i++;
		}
		else
			pb(&stack_b, stack_a);
		index++;
	}
	free(index_a);
	return (stack_b);
}

t_dll    *get_stack_lis(t_dll **stack_a)
{
	t_dll   *stack_b;
	int     *index_a;
	int     lis_size;
	int		i;

	lis_size = 1;
	i = 0;
	index_a = lis_algo(*stack_a, &lis_size);
	while (i < lis_size)
	{
		ft_printf("%d\n", index_a[i]);
		i++;
	}
	stack_b = handling_lis(stack_a, index_a, lis_size);
	return (stack_b);
}
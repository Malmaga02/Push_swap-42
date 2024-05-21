/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 18:32:45 by mgalmari          #+#    #+#             */
/*   Updated: 2024/05/09 11:56:21 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_dll	*checker_get_list_head(char **mtx)
{
	t_dll	*list;
	t_dll	*head;
	int		i;
	long	nl;

	head = NULL;
	i = 0;
	while (mtx && mtx[i])
	{
		nl = ft_atol(mtx[i]);
		if (nl > INT_MAX || nl < INT_MIN)
			return (dll_clear(&head), NULL);
		list = dll_new(nl);
		if (!list)
			return (dll_clear(&head), NULL);
		list->index = i;
		dll_add_back(&head, list);
		i++;
	}
	return (free_mtx(mtx, count_rows(mtx)), head);
}

t_dll	*checker_parse_input_string(int ac, char *av)
{
	t_dll	*head;
	char	**mtx;

	(void)ac;
	head = (t_dll *){0};
	mtx = ft_split(av, ' ');
	if (!mtx || !*mtx || !mtx_check(mtx))
		return (free_mtx(mtx, count_rows(mtx)), write(2, "Error\n", 6), NULL);
	head = checker_get_list_head(mtx);
	if (!head)
		return (dll_clear(&head), ft_putstr_fd("Error\n", STDERR_FILENO), NULL);
	return (head);
}

t_dll	*checker_parse_input_args(int ac, char **av)
{
	t_dll	*head;
	char	**mtx;
	int		i;

	(void)ac;
	head = (t_dll *){0};
	mtx = NULL;
	i = 0;
	if (!mtx_check(av))
		return (ft_putstr_fd("Error\n", STDERR_FILENO), NULL);
	mtx = ft_calloc(ac, sizeof(char *));
	if (!mtx)
		return (free_mtx(mtx, count_rows(mtx)), NULL);
	while (av[i])
	{
		mtx[i] = ft_strdup(av[i]);
		i++;
	}
	head = checker_get_list_head(mtx);
	if (!head)
		return (dll_clear(&head), free_mtx(mtx, count_rows(mtx)), \
		ft_putstr_fd("Error\n", STDERR_FILENO), NULL);
	return (head);
}

t_dll	*checker_parse_input(int ac, char **av)
{
	t_dll	*stack_a;

	stack_a = (t_dll *){0};
	if (ac == 1 || !av[1] || !av[1][0])
		return (NULL);
	if (ac == 2)
		stack_a = checker_parse_input_string(ac, av[1]);
	else if (ac > 2)
		stack_a = checker_parse_input_args(ac, &av[1]);
	if (!stack_a)
		return (NULL);
	return (stack_a);
}

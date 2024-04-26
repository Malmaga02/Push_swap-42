/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_rows.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 14:28:09 by mgalmari          #+#    #+#             */
/*   Updated: 2024/04/04 14:28:12 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

int	count_rows(char **mtx)
{
	int	i;

	i = 0;
	while (mtx && mtx[i])
		i++;
	return (i);
}
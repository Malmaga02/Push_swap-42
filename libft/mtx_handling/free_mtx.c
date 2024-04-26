/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mtx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 16:40:34 by mgalmari          #+#    #+#             */
/*   Updated: 2024/03/27 16:40:36 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libft.h"

void	free_mtx(char **mtx, int len_mtx)
{
	while (mtx && len_mtx >= 0)
	{
		free(mtx[len_mtx]);
		len_mtx--;
	}
	free(mtx);
}

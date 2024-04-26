/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalmari <mgalmari <marvin@42.fr>>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 12:28:37 by mgalmari          #+#    #+#             */
/*   Updated: 2023/12/18 18:29:06 by mgalmari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*t;

	i = 0;
	t = (char *)s;
	while (i < n)
	{
		t[i] = '\0';
		i++;
	}
}

/*int main()
{
    char *s;
    size_t i = 0;
    size_t n = 5;
    s = (char *)malloc(n + 1);
    ft_bzero(s, n);
    while (i < n)
    {
        printf("%c, ", s[i]);
        i++;
    }
    free(s);
    return(0);
}*/

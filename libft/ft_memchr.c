/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:42:50 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/03 14:20:18 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*t;
	unsigned char	i;

	t = (unsigned char *)s;
	i = (unsigned char)c;
	while (n--)
	{
		if (*t == i)
			return (t);
		t++;
	}
	return (NULL);
}

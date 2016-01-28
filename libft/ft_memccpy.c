/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 13:11:37 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/06 18:00:52 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*trc;
	unsigned char	*tst;
	unsigned char	t;

	trc = (unsigned char *)src;
	tst = (unsigned char *)dst;
	t = (unsigned char)c;
	while (n)
	{
		if ((*tst++ = *trc++) == t)
			return (tst);
		n--;
	}
	return (NULL);
}

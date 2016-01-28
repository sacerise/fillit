/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 14:31:07 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/04 15:23:17 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	const char	*str;
	size_t		size;

	str = s1;
	size = ft_strlen(s2);
	if (!*s2)
		return ((char *)(s1));
	while (*str && n > 0 && size <= n)
	{
		if (ft_strnequ(str, s2, size) == 1)
			return ((char *)str);
		str++;
		n--;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:02:55 by sacerise          #+#    #+#             */
/*   Updated: 2015/12/03 16:15:37 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*d;
	char	*tmp;
	int		n;

	n = ft_strlen(s);
	while (ft_whitespace(*s) && *s++)
		n--;
	tmp = ((char *)s);
	while (*tmp)
		tmp++;
	while (ft_whitespace(*--tmp) && tmp != s)
		n--;
	if (n <= 0)
		n = 0;
	d = (ft_strsub(s, 0, n));
	return (d);
}

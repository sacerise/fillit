/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sacerise <sacerise@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 12:14:29 by sacerise          #+#    #+#             */
/*   Updated: 2015/11/30 12:31:33 by sacerise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s3;
	size_t	i;

	i = 0;
	if (!(s3 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
		s3[i++] = s[start++];
	s3[i] = '\0';
	return (s3);
}
